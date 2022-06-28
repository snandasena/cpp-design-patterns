//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_REPORTSESSION_H
#define DESIGN_PATTERNS_REPORTSESSION_H

#include <boost/asio.hpp>
#include <memory>
#include <optional>

#include "auth/IAuthentication.h"
#include "parsers/ICredentialsParser.h"
#include "services/ITaxServiceFactory.h"

using boost::asio::ip::tcp;

namespace types
{
    struct User;
}

namespace servers
{
    class ReportSession
    {
    public:

        ReportSession(tcp::socket, const auth::IAuthentication &, const parsers::ICredentialsParser&,
                      const services::ITaxServiceFactory &);

        void start();

        void stop();

    private:

        std::optional<types::User> loginUser();

        static constexpr auto MAX_LENGTH = 1024;

        tcp::socket sock;
        char data[MAX_LENGTH];

        const auth::IAuthentication &authManager;
        const parsers::ICredentialsParser &parser;
        const services::ITaxServiceFactory &taxServiceFactory;

    };
}


#endif //DESIGN_PATTERNS_REPORTSESSION_H
