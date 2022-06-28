//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_AUTHMANAGER_H
#define DESIGN_PATTERNS_AUTHMANAGER_H

#include "auth/IAuthentication.h"
#include "auth/IAuthorization.h"

#include <functional>
#include <set>

#include "types/User.h"

namespace auth
{
    class AuthManger : public IAuthorization, public IAuthentication
    {
    public:

        AuthManger();

        bool authenticate(const types::Login &, const types::Password &) const override;

        bool isAuthorized(const types::Login &, std::uint32_t) const override;

    private:

        std::set<types::User, std::less<>> users;
    };
}

#endif //DESIGN_PATTERNS_AUTHMANAGER_H
