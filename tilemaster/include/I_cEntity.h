#pragma once
#include "I_cSprite.h"


class I_cEntity
{
 public:
        I_cEntity();
       ~I_cEntity();
       
        virtual void Init(int posx, int posy);
        virtual void Draw(int posx, int posy);
        virtual void SetAnim(int anim);
            
        I_cSprite *sprite;

};