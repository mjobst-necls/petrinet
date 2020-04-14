/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef ABSTRACTTRANSITIONCONDITION_H
#define ABSTRACTTRANSITIONCONDITION_H

namespace petrinet{

class Transition;
class TokenData;

class AbstractTransitionCondition
{
public:
    AbstractTransitionCondition();

    virtual bool isFullfilled(const TokenData& tokenDataExisting, const TokenData& tokenDataNew) const = 0;

    void setTransition(const petrinet::Transition* transition);
    const Transition* getTransition() const;

protected:
    const Transition* relatedTransition_;
};

}

#endif // ABSTRACTTRANSITIONCONDITION_H
