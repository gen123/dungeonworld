#pragma once
#include "tilemaster.h"
#include "gameapi.h"


class I_cItem
{
 public:
	    I_cItem();
	   ~I_cItem();
	  
	    void Init(GLuint tex);
	    
	    GLuint itemTexture;
	    
	   
	  
};