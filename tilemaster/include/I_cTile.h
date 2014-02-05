#pragma once
#include "tilemaster.h"
#include "gameapi.h"
#include "I_cObject.h"

class I_cTile
{
 public:
		I_cTile();
	   ~I_cTile();
	   
	    virtual void Draw(int posx, int posy);
	    
	    void Init(int sx, int sy, GLuint texture);
	    void SetTexture(GLuint tex);
	    void SetTileId(GAMEAPI_TILE_ID tileid);
	    void CreateTileItem(GLuint tex);
	    void DestroyTileItem(void);

         GAMEAPI_TILE_ID tileId1_;	   
         
         SDL_Rect tileRect;
         
         int sizex, int sizey;
         
         bool useDefualtTex;
         GLuint tileTexture;

 
         // tile moze sadrzavati objekte na sebi
         I_cObject *objectItem;
};