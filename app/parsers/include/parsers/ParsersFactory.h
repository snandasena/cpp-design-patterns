//
// Created by sajith on 6/21/22.
//

#ifndef DESIGN_PATTERNS_PARSERSFACTORY_H
#define DESIGN_PATTERNS_PARSERSFACTORY_H

#include "parsers/IParsersFactory.h"
#include <memory>
#include "types/ReportFormat.h"

namespace parsers
{
    class ParserFactory : public IParserFactory
    {
    public:
        ParserFactory(const types::ReportFormat);

        std::unique_ptr<IReportParser> createReportParser() const override;

        std::unique_ptr<ICredentialsParser> createCredentialParser() const override;

    private:
        const types::ReportFormat reportFormat;
    };
}


#endif //DESIGN_PATTERNS_PARSERSFACTORY_H
