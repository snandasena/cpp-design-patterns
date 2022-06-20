//
// Created by sajith on 6/13/22.
//

#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create()
{
    return PersonBuilder{};
}

