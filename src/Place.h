/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef PLACE_H
#define PLACE_H

#include "ConnectableElement.h"
#include "NamedElement.h"

#include "list"

namespace petrinet{

class Token;
class TokenData;
class PlaceAction;

class Place : public ConnectableElement, public NamedElement
{
public:
    explicit Place(const std::string& name, int timeout = 0);

    const std::list<Token*>& getTokens() const;
    bool hasTokens() const;

    void removeAllTokens();
    Token* takeLastToken();

    void merge(Place& other, TokenData* tokenData);
    void merge(TokenData* other, TokenData* tokenData);
    void addToken(Token* token);
    std::list<PlaceAction*> addToken(Token* token, TokenData* tokenData);

    void addAction(PlaceAction* action);

    void tokenTimeout();

private:
    std::list<Token*>             tokens_;
    std::list<PlaceAction*>       actions_;
    int                           timeout_;
};

}

#endif // PLACE_H
