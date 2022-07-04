//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_SERVER_H
#define DESIGN_PATTERNS_SERVER_H


#include <cstdint>
#include <memory>

#include "auth/IAuthentication.h"
#include "parsers/ICredentialsParser.h"
#include "services/ITaxServiceFactory.h"

namespace servers
{
    using Port = std::uint16_t;

    void runServer(Port port, const auth::IAuthentication &, const parsers::ICredentialsParser &,
                   const services::ITaxServiceFactory &);
}


#endif //DESIGN_PATTERNS_SERVER_H
