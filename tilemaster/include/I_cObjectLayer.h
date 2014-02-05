#pragma once
#include "I_cTile.h"




typedef struct OBJECT_LIST
{
 int tx,ty;
 I_cTile object;
}OBJECT_LIST;

class I_cObjectLayer
{
 public:
	    I_cObjectLayer();
	   ~I_cObjectLayer();
	   
	   
	    void Init(int numobjects, int tilesw, int tilesh);
	   
        void Draw();
	   
	   int tiles_w,tiles_h;
	   int num_objects;
	   
	   OBJECT_LIST *objectList;
	    
};