//
// Created by sajith on 6/13/22.
//

#ifndef DESIGN_PATTERNS_PERSONBUILDER_H
#define DESIGN_PATTERNS_PERSONBUILDER_H

#include "Person.h"

class PersonJobBuilder;

class PersonAddressBuilder;

class PersonBuilderBase
{
protected:
    Person &person;

public:
    PersonBuilderBase(Person &person);
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;
public:
    PersonBuilder();

    PersonAddressBuilder lives() const;

    PersonJobBuilder works() const;
};


#endif //DESIGN_PATTERNS_PERSONBUILDER_H
