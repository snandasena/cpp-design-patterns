//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_JSONPARSER_H
#define DESIGN_PATTERNS_JSONPARSER_H

#include "parsers/ICredentialsParser.h"
#include "parsers/IReportParser.h"

namespace parsers
{
    class JsonParser : public IReportParser, public ICredentialParser
    {
    public:
        std::optional <types::Report> parseReport(const std::string &) const override;

        std::optional <types::User> parseCredentials(const std::string &) const override;
    };
}

#endif //DESIGN_PATTERNS_JSONPARSER_H
