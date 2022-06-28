//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_IAUTHENTICATION_H
#define DESIGN_PATTERNS_IAUTHENTICATION_H

#include "types/User.h"

namespace auth
{
    class IAuthentication
    {
    public:

        virtual ~IAuthentication() = default;

        virtual bool authenticate(const types::Login &, const types::Password &) const = 0;
    };
}

#endif //DESIGN_PATTERNS_IAUTHENTICATION_H
