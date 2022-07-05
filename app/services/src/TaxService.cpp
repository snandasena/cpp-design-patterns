//
// Created by sajith on 7/4/22.
//

#include "constants/Constants.h"
#include "services/TaxService.h"

services::TaxService::TaxService(const types::User &u, const auth::IAuthorization &auth,
                                 const parsers::IReportParser &parsr) :
        user{u}, authManager{auth}, reportParser{parsr}
{

}
services::ReportStatus services::TaxService::onReportRequest(const std::string &request)
{
    const auto report = reportParser.parseReport(request);
    if (report != std::nullopt && authManager.isAuthorized(user.login, report->payer))
    {
        storage.storeReport(*report);
        return constants::OK;
    }
    return constants::NOK;
}
