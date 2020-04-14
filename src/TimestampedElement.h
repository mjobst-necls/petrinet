/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef TIMESTAMPEDELEMENT_H
#define TIMESTAMPEDELEMENT_H

#include "time.h"

namespace petrinet{

class TimestampedElement
{
public:
    TimestampedElement();
    TimestampedElement(const TimestampedElement& other);

    time_t getTimestamp() const { return timestamp_; }
    void setTimestamp(time_t timestamp) { timestamp_ = timestamp; }

private:
    time_t     timestamp_;
};

}

#endif // TIMESTAMPEDELEMENT_H
