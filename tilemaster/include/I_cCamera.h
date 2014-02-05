#pragma once
#include "I_cDungeon.h"
#include "I_cPlayer.h"
#include "I_cCollisionHandler.h"
#include "I_cObjectLayer.h"


class I_cCamera
{
 public:
	    I_cCamera();
	   ~I_cCamera();
	   
	   
 void Init(int w, int h, I_cDungeon *dng, I_cPlayer *ply);
 void Draw();
 void DrawObjectLayer();
 
 int screen_w,screen_h;
 
 
 I_cTile **currentDrawMap;
 I_cTile **currentDrawObjectMap;
 
 I_cDungeon *currentDungeon;
 I_cPlayer *player;
 
 int camera_w;  // in tiles
 int camera_h;  
 
 float camera_smooth_x;
 float camera_smooth_y;
 
 int currentDngMapTile_x;
 int currentDngMapTile_y;
 
 float tile_offset_x;
 float tile_offset_y;
 
 int player_tilex,player_tiley; 
 
 int pola_ekrana_w, pola_ekrana_h;
I_cObjectLayer olayer;
 
  I_cTile *tiles[9];

 I_cCollisionHandler colHandler;

 void MoveOneTileRight(void);
 void MoveOneTileLeft(void);
 void MoveOneTileUp(void);
 void MoveOneTileDown(void);
 
 void MoveSmoothRight(float delta);
 void MoveSmoothLeft(float delta);
 void MoveSmoothUp(float delta);
 void MoveSmoothDown(float delta);
 
 I_cTile *GetPlayerTile(int *tx, int *ty);
 void GetSurroundingTiles(I_cTile **tiles);
 I_cTile *GetTile(float posx,float posy);
 I_cTile *GetObjectTile(float posx, float posy);
 
 int player_temp_x;
 
 void Clear();
};