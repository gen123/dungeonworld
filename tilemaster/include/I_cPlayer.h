#pragma once
#include "I_cEntity.h"



class I_cPlayer : public I_cSprite
{
 public:
		I_cPlayer();
	   ~I_cPlayer();
	   
	    void Init(int posx, int posy);
	    void Draw();
	    
	    float pos_x,pos_y;
	    
	    int center_x;
	    int center_y;
	   
	   
	  
};