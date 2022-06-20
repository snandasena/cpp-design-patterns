//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_CONSTANTS_H
#define DESIGN_PATTERNS_CONSTANTS_H

#include <string>
#include <unordered_set>

namespace constants
{
    std::string OK{"OK"};
    std::string NOK{"NOK"};

    const std::unordered_set<std::string> validTaxNames{
            "corporate income tax",
            "individual income tax",
            "value added tax",
            "withholding tax"
            "property tax",
            "exit tax"
    };
}

#endif //DESIGN_PATTERNS_CONSTANTS_H
