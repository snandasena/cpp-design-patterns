//
// Created by sajith on 6/23/22.
//

#ifndef DESIGN_PATTERNS_STARTUPCONFIG_H
#define DESIGN_PATTERNS_STARTUPCONFIG_H


#include <cstdint>
#include <optional>

#include "types/ReportFormat.h"

struct StartupConfig
{
    const std::uint16_t port;
    const types::ReportFormat format;
};

std::optional<const StartupConfig> optionsToStartupConfig(int arg, char *argv[]);


#endif //DESIGN_PATTERNS_STARTUPCONFIG_H
