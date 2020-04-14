/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef PETRINETQUERY_H
#define PETRINETQUERY_H

#include "string"

namespace petrinet{

class AbstractPetriNetQuery
{
public:
    AbstractPetriNetQuery();
    virtual ~AbstractPetriNetQuery();

    virtual std::string getQuery() const = 0;
    virtual std::string getQueryType() const = 0;
};

}

#endif // PETRINETQUERY_H
