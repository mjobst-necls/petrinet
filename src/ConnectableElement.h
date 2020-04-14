/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef CONNECTABLEELEMENT_H
#define CONNECTABLEELEMENT_H

#include "vector"

namespace petrinet{

class Arc;

class ConnectableElement
{
public:
    ConnectableElement();

    const std::vector<Arc*>& getIncomming() const { return incoming_; }
    const std::vector<Arc*>& getOutgoing() const { return outgoing_; }

    void removeOutgoing(Arc* a);
    void removeIncoming(Arc* a);

    void addOutgoing(Arc* a);
    void addIncoming(Arc* a);


protected:
    std::vector<Arc*> incoming_;
    std::vector<Arc*> outgoing_;
};

}

#endif // CONNECTABLEELEMENT_H
