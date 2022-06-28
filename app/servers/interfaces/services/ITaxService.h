//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_ITAXSERVICE_H
#define DESIGN_PATTERNS_ITAXSERVICE_H

#include <string>
#include <string_view>

#include "types/ReportFormat.h"

namespace services
{
    using ReportStatus = std::string;

    class ITaxService
    {
    public:

        virtual ~ITaxService() = default;

        virtual ReportStatus onReportRequest(const std::string &) = 0;
    };
}
#endif //DESIGN_PATTERNS_ITAXSERVICE_H
