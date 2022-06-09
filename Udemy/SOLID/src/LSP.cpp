//
// Created by sajith on 6/9/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Document;

using namespace std;

struct IFax
{
    virtual void fax(Document &doc) = 0;

    virtual ~IFax() = default;
};


struct IScanner
{
    virtual void scan(Document &doc) = 0;

    virtual ~IScanner() = default;
};


struct IPrinter
{
    virtual void print(Document &doc) = 0;

    virtual ~IPrinter() = default;
};

struct Scanner : IScanner
{

    void scan(Document &doc) override
    {

    }
};

struct Printer : IPrinter
{
    void print(Document &doc) override
    {

    }
};

struct IMachine : IPrinter, IScanner
{

};

struct Machine : IMachine
{
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &ptr, IScanner &scnr) : printer{ptr}, scanner{scnr} {}

    void print(Document &doc) override
    {

    }

    void scan(Document &doc) override
    {

    }
};

