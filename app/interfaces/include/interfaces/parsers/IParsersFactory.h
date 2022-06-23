//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_IPARSERSFACTORY_H
#define DESIGN_PATTERNS_IPARSERSFACTORY_H

#include <memory>
#include "parsers/ICredentialsParser.h"
#include "parsers/IReportParser.h"

namespace parsers
{
    class IParserFactory
    {
    public:
        virtual ~IParserFactory() = default;

        virtual std::unique_ptr<IReportParser> createReportParser() const = 0;

        virtual std::unique_ptr<ICredentialsParser> createCredentialParser() const = 0;

    };
}


#endif //DESIGN_PATTERNS_IPARSERSFACTORY_H
