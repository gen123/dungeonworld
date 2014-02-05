#pragma once
#include "tilemaster.h"
#include "gameapi.h"
#include "I_cTile.h"

class I_cSprite : public I_cTile
{
 public:
		I_cSprite();
	   ~I_cSprite();
	   
	    void Init(int posx, int posy);
       
       
        void SetAnimation(int anim_start, int anim_end);
        void StopAnimation();
        void Draw(int posx, int posy);

        int half_w,half_h;

        //vector<GLuint>textureList; 
        
        uint32_t timeDelay;
	    int currentTexture;
	    int currentAnim;
	    int currentAnimEnd;
	    bool stop;
	   
};