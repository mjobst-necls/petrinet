/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef TRANSITIONACTION_H
#define TRANSITIONACTION_H


namespace petrinet{

class AbstractPetriNetQuery;
class TokenData;

class TransitionAction
{
public:
    TransitionAction();

    virtual bool isMatching(const AbstractPetriNetQuery& query) = 0;
    virtual TokenData* getTransitionTokenData(const AbstractPetriNetQuery& query) = 0;
};

}

#endif // TRANSITIONACTION_H
