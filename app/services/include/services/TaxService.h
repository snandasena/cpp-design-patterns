//
// Created by sajith on 7/4/22.
//

#ifndef DESIGN_PATTERNS_TAXSERVICE_H
#define DESIGN_PATTERNS_TAXSERVICE_H

#include "services/ITaxService.h"

#include <memory>

#include "auth/IAuthorization.h"
#include "parsers/IReportParser.h"
#include "storage/ReportsStorage.h"
#include "types/User.h"

namespace services
{
    class TaxService : public ITaxService
    {
    public:

        TaxService(const types::User &, const auth::IAuthorization &, const parsers::IReportParser &);

        ReportStatus onReportRequest(const std::string &) override;

    private:
        const types::User &user;
        const auth::IAuthorization &authManager;
        const parsers::IReportParser &reportParser;
        storage::ReportsStorage storage;
    };
}

#endif //DESIGN_PATTERNS_TAXSERVICE_H
