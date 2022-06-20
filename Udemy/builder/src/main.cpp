//
// Created by sajith on 6/19/22.
//

#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"

using namespace std;
int main()
{

    Person p = Person::create()
            .lives().at("123 London")
                    .with_postcode("SW1 1GB")
            .works().at("");

    return 0;
}