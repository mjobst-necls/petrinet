/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef TRANSITION_H
#define TRANSITION_H

#include "ConnectableElement.h"
#include "NamedElement.h"

#include "list"

namespace petrinet{

class AbstractTransitionCondition;
class AbstractPetriNetQuery;
class PetriNet;
class Place;
class PlaceAction;
class Token;
class TokenData;
class TransitionAction;

class Transition : public ConnectableElement, public NamedElement
{
public:
    Transition();
    Transition(const std::string& name);

    bool isMatching(const AbstractPetriNetQuery& query) const;
    bool isActive() const;

    std::list<petrinet::PlaceAction*> trigger(const AbstractPetriNetQuery& query);

    void setPetriNet(PetriNet* petriNet);
    void setAction(TransitionAction* action);
    TransitionAction* getAction() const { return action_; }

    TokenData* getTokenData(const AbstractPetriNetQuery& query);

    bool hasBackwardsArc(const petrinet::Place& place) const;
    bool hasTowardsArc(const petrinet::Place& place) const;

    void addCondition(const AbstractTransitionCondition* condition);
    const std::list<const AbstractTransitionCondition*>& getConditions() { return conditions_; }

    bool checkConditions(const Token& token, const petrinet::TokenData& tokenDataNew) const;

private:
    PetriNet*           petriNet_;
    TransitionAction*   action_;
    std::list<const AbstractTransitionCondition*> conditions_;
};

}

#endif // TRANSITION_H
