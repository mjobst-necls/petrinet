/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef ABSTRACTTRANSITIONHELPER_H
#define ABSTRACTTRANSITIONHELPER_H

#include "list"

namespace petrinet{

class Transition;
class AbstractPetriNetQuery;
class PlaceAction;

class AbstractTransitionHelper
{
public:
    AbstractTransitionHelper();

    virtual bool isMatching(const Transition& transition, const AbstractPetriNetQuery& query) const = 0;
    virtual std::list<petrinet::PlaceAction*> trigger(Transition& transition, const AbstractPetriNetQuery& query) const = 0;
};

}

#endif // ABSTRACTTRANSITIONHELPER_H
