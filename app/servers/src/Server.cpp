//
// Created by sajith on 6/28/22.
//
#include "servers/Server.h"

#include <boost/asio.hpp>
#include <memory>
#include <thread>

#include "servers/ReportSession.h"


using boost::asio::ip::tcp;

namespace servers
{
    void runServer(Port port, const auth::IAuthentication &authManager,
                   const parsers::ICredentialsParser &credentialsParser,
                   const services::ITaxServiceFactory &taxServiceFactory)
    {
        boost::asio::io_context io_context;
        tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));

        for (;;)
        {
            std::thread(&ReportSession::start,
                     ReportSession(a.accept(), authManager, credentialsParser, taxServiceFactory))
                    .detach();
        }
    }
}