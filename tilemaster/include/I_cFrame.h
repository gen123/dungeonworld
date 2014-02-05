#pragma once
#include <vector>
#include "I_cTile.h"


class I_cFrame
{
 public:
        I_cFrame();
       ~I_cFrame();
       
        
       
        virtual void Draw(void);
        
        
        vector<I_cTile*>vFrame;
};