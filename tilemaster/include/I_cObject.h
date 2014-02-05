#pragma once
#include "tilemaster.h"
#include "gameapi.h"
#include "I_cItem.h"
//#include "I_cInventory.h"


class I_cObject
{
 public:
	    I_cObject();
	   ~I_cObject();
	   
	    void Init(int sx, int sy, GLuint objTex);
	   
	    void Draw(int posx, int posy);
	   
        GLuint objectTexture;	   
        SDL_Rect objectRect;
        
        int sizex, sizey;
        
        I_cItem item[3];  
        int itemCount;
        
};