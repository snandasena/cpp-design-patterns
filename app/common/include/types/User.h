//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_USER_H
#define DESIGN_PATTERNS_USER_H

#include <cstdint>
#include <set>
#include <string>

namespace types
{
    struct Login
    {
        const std::string value;
    };

    struct Password
    {
        const std::string value;
    };

    struct User
    {
        const Login login;
        const Password password;
        const std::set<std::uint32_t> taxpayers;
    };

    bool operator==(const Login &, const Login &);

    bool operator<(const User &, const User &);

    bool operator<(const User &, const Login &);

    bool operator<(const Login &, const User &);

}
#endif //DESIGN_PATTERNS_USER_H
