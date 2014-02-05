#pragma once
#include "I_cTile.h"


class I_cInventory
{
 public:
        I_cInventory();
       ~I_cInventory();
       
        void Init(float posx, float posy, int itemcount);
        
        
        void Draw();
       
        int itemCount;
        float pos_x;
        float pos_y;
 I_cTile *invTiles;       
};