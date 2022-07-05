//
// Created by sajith on 7/4/22.
//


#include "services/TaxServiceFactory.h"
#include "services/TaxService.h"

namespace services
{
    TaxServiceFactory::TaxServiceFactory(const auth::IAuthorization &auth, const parsers::IReportParser &parser) :
            authManager{auth}, reportParser{parser}
    {

    }
    std::unique_ptr<ITaxService> services::TaxServiceFactory::create(const types::User &user) const
    {
        return std::make_unique<TaxService>(user, authManager, reportParser);
    }
}
