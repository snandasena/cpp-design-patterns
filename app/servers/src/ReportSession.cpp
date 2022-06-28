//
// Created by sajith on 6/28/22.
//


#include "servers/ReportSession.h"

#include <iostream>
#include <stdexcept>

#include "constants/Constants.h"
#include "types/User.h"

namespace
{
    std::size_t read(tcp::socket &sock, char *buff, const std::size_t n)
    {
        boost::system::error_code error;
        const auto readLength = sock.read_some(boost::asio::buffer(buff, n), error);
        std::cout << "Received " << readLength << " bytes\n";

        if (error == boost::asio::error::eof)
        {
            return 0;
        }
        else if (error)
        {
            throw boost::system::system_error{error};
        }
        return readLength;
    }
}


namespace servers
{
    ReportSession::ReportSession(tcp::socket sk, const auth::IAuthentication &aManager,
                                 const parsers::ICredentialsParser &pser,
                                 const services::ITaxServiceFactory &tSF) : sock{std::move(sk)}, authManager{aManager},
                                                                            parser{pser}, taxServiceFactory{tSF}
    {}

    std::optional<types::User> ReportSession::loginUser()
    {
        if (const auto length = read(sock, data, MAX_LENGTH))
        {
            const auto user = parser.parseCredentials({data, length});
            if (user && authManager.authenticate(user->login, user->password))
            {
                return user;
            }
        }
        return std::nullopt;
    }

    void ReportSession::start() try
    {
        if (const auto user = loginUser())
        {
            boost::asio::write(sock, boost::asio::buffer(constants::OK.data(), constants::OK.size()));

            for (auto taxService = taxServiceFactory.create(*user);;)
            {
                if (const auto length = read(sock, data, MAX_LENGTH))
                {
                    const auto response = taxService->onReportRequest({data, length});
                    boost::asio::write(sock, boost::asio::buffer(response.data(), response.size()));
                }
                else
                {
                    stop();
                }
            }
        }
        else
        {
            boost::asio::write(sock, boost::asio::buffer(constants::NOK.data(), constants::NOK.size()));
            stop();
            std::cerr << __FILE__ << " Failed to login a user for tax reporting\n";
        }
    }catch (const std::exception &e)
    {
        std::cerr<<__FILE__<<' '<< __LINE__ <<' '<<e.what()<<'\n';
    }


    void ReportSession::stop()
    {

    }
}