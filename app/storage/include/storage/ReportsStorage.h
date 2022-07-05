//
// Created by sajith on 7/4/22.
//

#ifndef DESIGN_PATTERNS_REPORTSSTORAGE_H
#define DESIGN_PATTERNS_REPORTSSTORAGE_H

namespace types
{
    struct Report;
}

namespace storage
{
    class ReportsStorage
    {
    public:
        void storeReport(const types::Report &);
    };
}

#endif //DESIGN_PATTERNS_REPORTSSTORAGE_H
