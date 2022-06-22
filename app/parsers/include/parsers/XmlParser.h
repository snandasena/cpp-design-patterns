//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_XMLPARSER_H
#define DESIGN_PATTERNS_XMLPARSER_H


#include "parsers/ICredentialsParser.h"
#include "parsers/IReportParser.h"


namespace parsers
{
    class XmlParser : public IReportParser, public ICredentialsParser
    {
    public:

        std::optional<types::Report> parseReport(const std::string &) const override;

        std::optional<types::User> parseCredentials(const std::string &) const override;
    };
}
#endif //DESIGN_PATTERNS_XMLPARSER_H
