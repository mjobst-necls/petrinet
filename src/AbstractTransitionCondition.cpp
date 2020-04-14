/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "AbstractTransitionCondition.h"

namespace petrinet{

AbstractTransitionCondition::AbstractTransitionCondition()
{

}

void AbstractTransitionCondition::setTransition(const petrinet::Transition* transition)
{
    relatedTransition_ = transition;
}

const petrinet::Transition* AbstractTransitionCondition::getTransition() const
{
    return relatedTransition_;
}

}
