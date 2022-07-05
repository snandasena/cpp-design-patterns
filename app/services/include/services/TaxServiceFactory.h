//
// Created by sajith on 7/4/22.
//

#ifndef DESIGN_PATTERNS_TAXSERVICEFACTORY_H
#define DESIGN_PATTERNS_TAXSERVICEFACTORY_H

#include "auth/IAuthorization.h"
#include "parsers/IReportParser.h"
#include "services/ITaxServiceFactory.h"

namespace services
{
    class TaxServiceFactory : public ITaxServiceFactory
    {
    public:

        TaxServiceFactory(const auth::IAuthorization &, const parsers::IReportParser &);

        std::unique_ptr<ITaxService> create(const types::User &) const override;

    private:
        const auth::IAuthorization &authManager;
        const parsers::IReportParser &reportParser;
    };
}

#endif //DESIGN_PATTERNS_TAXSERVICEFACTORY_H
