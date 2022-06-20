//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_ICREDENTIALSPARSER_H
#define DESIGN_PATTERNS_ICREDENTIALSPARSER_H

#include <optional>
#include <string>

#include "types/User.h"

namespace parsers
{
    class ICredentialsParser
    {
    public:
        virtual ~ICredentialParser() = default;

        virtual std::optional<types::User> parseCredentials(const std::string &) const = 0;
    };
}

#endif //DESIGN_PATTERNS_ICREDENTIALSPARSER_H
