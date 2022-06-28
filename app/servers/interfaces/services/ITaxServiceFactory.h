//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_ITAXSERVICEFACTORY_H
#define DESIGN_PATTERNS_ITAXSERVICEFACTORY_H

#include <memory>
#include "ITaxService.h"
#include "types/ReportFormat.h"
#include "types/User.h"


namespace services
{
    class ITaxServiceFactory
    {
    public:

        virtual ~ITaxServiceFactory() = default;

        virtual std::unique_ptr<ITaxService> create(const types::User &) const = 0;
    };
}

#endif //DESIGN_PATTERNS_ITAXSERVICEFACTORY_H
