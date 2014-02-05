#pragma once
#include "I_cTile.h"
#include "I_cItem.h"

class I_cInvTile//: public I_cTile
{
 public:
        I_cInvTile();
       ~I_cInvTile();
       

 I_cItem *item;  // jedan inventory tile sadrzi jedan item       
 bool selected;  // ovo je selektirani inv item?
};