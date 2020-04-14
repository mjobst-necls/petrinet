/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef PETRINET_H
#define PETRINET_H

#include "list"

namespace petrinet{

class AbstractTransitionHelper;
class Arc;
class ConnectableElement;
class Place;
class Transition;

class PetriNet
{
public:
    PetriNet();

    void addPlace(Place* place, bool isInitial = false);
    void addTransition(Transition* transition);
    void addArc(Arc* arc);
    void addArc(ConnectableElement* source, ConnectableElement* target);

    void setTransitionHelper(AbstractTransitionHelper* transitionHelper) {transitionHelper_ = transitionHelper; }
    AbstractTransitionHelper* getTransitionHelper() const { return transitionHelper_; }

protected:
    std::list<Place*>         initialStates_;
    std::list<Place*>         places_;
    std::list<Transition*>    transitions_;
    //std::list<Transition*>    alwaysTransitions_;
    std::list<Arc*>           arcs_;

private:
    AbstractTransitionHelper*   transitionHelper_;

};

}


#endif // PETRINET_H
