#pragma once
#include "I_cTile.h"


class I_cCollisionHandler
{
 public:
        I_cCollisionHandler();
       ~I_cCollisionHandler();
       
       
       bool Collide(I_cTile *tile1, I_cTile *tile2);
       
       bool check(int x, int y, I_cTile *tile);
};