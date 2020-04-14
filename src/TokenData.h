/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef TOKENDATA_H
#define TOKENDATA_H

#include "TimestampedElement.h"

namespace petrinet{
class Transition;

class TokenData : public TimestampedElement
{
public:
    TokenData();
    TokenData(const TokenData& other);

    void setTransition(Transition* t) { transition_ = t; }
    Transition* getTransition() const { return transition_; }

    virtual bool isMergeable(const TokenData& other) const = 0;
    virtual TokenData* clone() const = 0;


private:
    Transition* transition_;
};

}

#endif // TOKENDATA_H
