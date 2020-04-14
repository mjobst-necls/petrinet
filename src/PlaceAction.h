/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef PLACEACTION_H
#define PLACEACTION_H

#include "TimestampedElement.h"
#include "NamedElement.h"

namespace petrinet{

class TokenData;

class PlaceAction : public NamedElement
{
public:
    PlaceAction();
    PlaceAction(const PlaceAction& other);
    virtual ~PlaceAction();

    virtual void execute() = 0;
    virtual PlaceAction* create(const TokenData& tokenData) = 0;

    virtual bool equals(const PlaceAction& other) const = 0;

    void setExecuteLater(bool executeLater) { executeLater_ = executeLater; }
    bool getExecuteLater() const { return executeLater_; }

private:
    bool    executeLater_;
};

}

#endif // PLACEACTION_H
