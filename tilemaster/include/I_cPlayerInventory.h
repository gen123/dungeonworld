#pragma once
#include "I_cTile.h"
#include "I_cInventory.h"




class I_cPlayerInventory: public I_cInventory
{
 public:
        I_cPlayerInventory();
       ~I_cPlayerInventory();
       
        void Init(void);
        void Draw(float startposx, float startposy);
        
        I_cTile *playerInvTile;       
        I_cTile *backImage;
        I_cTile *equipped;
        
};