#include "I_cCamera.h"
#include "I_cGlobal.h"


I_cCamera::I_cCamera()
{
 currentDungeon = NULL;
 screen_w = 0;
 screen_h = 0;
 
 currentDngMapTile_x = 0;
 currentDngMapTile_y = 0;
 
 camera_smooth_x = 0;
 camera_smooth_y = 0;
 
 player_temp_x = 0;
 
 int tile_offset_x = 0;
 int tile_offset_y = 0;

}


I_cCamera::~I_cCamera()
{
}


void I_cCamera::Init(int w, int h, I_cDungeon *dng, I_cPlayer *ply)
{
 screen_h = h;
 screen_w = w;
 currentDungeon = dng;
 
 pola_ekrana_w = GAMEAPI_WINDOW_W/2;
 pola_ekrana_h = GAMEAPI_WINDOW_H/2;
 
 
 camera_w = screen_w/GAME_TILE_SIZE_W;
 camera_h = screen_h/GAME_TILE_SIZE_H;
 
 
 currentDrawMap = new I_cTile*[camera_h];
 
 for (int c=0;c<camera_w;c++)
     {
      currentDrawMap[c] = new I_cTile[camera_h];
     }
 
 for (int w=0;w<camera_w;w++)
     {
      for (int h=0;h<camera_h;h++)
          {
           currentDrawMap[w][h].Init(GAME_TILE_SIZE_W,GAME_TILE_SIZE_H,0);
           currentDrawMap[w][h].SetTileId(TILE_ID_NULL);
          }
     } 
     
 // postavi
 
 for (int x=0;x < camera_w && x < currentDungeon->tiles_w;x++)
     {
      for (int y=0;y < camera_h && y < currentDungeon->tiles_h;y++)
          {
           currentDrawMap[x][y] = currentDungeon->mTileMap[x][y];
          }
      
     }
 
 // object draw map iste velicine kao i kamera
 olayer.Init(5,dng->tiles_w,dng->tiles_h);
 currentDrawObjectMap = new I_cTile*[camera_h];
 
 for (int c=0;c<camera_w;c++)
     {
      currentDrawObjectMap[c] = new I_cTile[camera_h];
     }
 
 for (int w=0;w<camera_w;w++)
     {
      for (int h=0;h<camera_h;h++)
          {
           currentDrawObjectMap[w][h].Init(GAME_TILE_SIZE_W,GAME_TILE_SIZE_H,0);
           currentDrawObjectMap[w][h].SetTileId(TILE_ID_NULL);
          }
     } 
     
 // postavi
 
 for (int x=0;x < camera_w && x < currentDungeon->tiles_w;x++)
     {
      for (int y=0;y < camera_h && y < currentDungeon->tiles_h;y++)
          {
           for (int c=0;c<olayer.num_objects;c++)
               {
                if (olayer.objectList[c].tx == x && olayer.objectList[c].ty == y)
                   {
                    currentDrawObjectMap[x][y] = olayer.objectList[c].object;
                   }
               }
          }
      } 
 
 
 
 
 
 player = ply;

      
}


void I_cCamera::Draw()
{
 //currentDungeon->Draw();
 

  for (int w=0;w<camera_w;w++) 
     {
      for (int h=0;h<camera_h;h++)
          {
           if (currentDrawMap[w][h].tileId1_ != TILE_ID_NULL)
              {
               currentDrawMap[w][h].Draw(camera_smooth_x+w*GAME_TILE_SIZE_W,40+camera_smooth_y+h*GAME_TILE_SIZE_H);
              }
          }
     }
   


 
     
   GetSurroundingTiles(tiles);
  
  I_cTile *tile = GetPlayerTile(&player_tilex,&player_tiley);
  I_cTile *otile = GetObjectTile(player_tilex,player_tiley); //


  //DrawObjectLayer();
  
 
  player->Draw();

 
}



void I_cCamera::DrawObjectLayer()
{
  for (int w=0;w<camera_w;w++) 
     {
      for (int h=0;h<camera_h;h++)
          {
           if (currentDrawObjectMap[w][h].tileId1_ != TILE_ID_NULL)
              {
               currentDrawObjectMap[w][h].Draw(camera_smooth_x+w*GAME_TILE_SIZE_W,40+camera_smooth_y+h*GAME_TILE_SIZE_H);
              }
          }
     }   
}

void I_cCamera::GetSurroundingTiles(I_cTile **tiles)
{
 int ptx,pty;
 ptx = 0,pty = 0;
 
 I_cTile *ptile = GetPlayerTile(&ptx,&pty);
 
 if (ptile)
    {
     if (ptx > 0 && pty > 0 )
        {
         tiles[0] = &this->currentDrawMap[ptx-1][pty-1];
         tiles[1] = &this->currentDrawMap[ptx][pty-1];
         tiles[2] = &this->currentDrawMap[ptx+1][pty-1];
         tiles[3] = &this->currentDrawMap[ptx-1][pty];
         tiles[4] = &this->currentDrawMap[ptx][pty];
         tiles[5] = &this->currentDrawMap[ptx+1][pty];
         tiles[6] = &this->currentDrawMap[ptx-1][pty+1];
         tiles[7] = &this->currentDrawMap[ptx][pty+1];
         tiles[8] = &this->currentDrawMap[ptx+1][pty+1];
        }
     }
}

I_cTile *I_cCamera::GetTile(float posx,float posy)
{

 for (int w=0;w<camera_w;w++) 
    {
     for (int h=0;h<camera_h;h++)
         {
          I_cTile *tile = &currentDrawMap[w][h];
          
          if (posx >= tile->tileRect.x && 
              posy >= tile->tileRect.y &&
              posx <= tile->tileRect.x + tile->sizex && 
              posy <= tile->tileRect.y + tile->sizey)
             {
              return tile;
             }
         }
    }
 return NULL; 
}

I_cTile *I_cCamera::GetObjectTile(float posx, float posy)
{
 for (int w=0;w<camera_w;w++) 
    {
     for (int h=0;h<camera_h;h++)
         {
          I_cTile *tile = &currentDrawObjectMap[w][h];
          
          if (posx >= tile->tileRect.x && 
              posy >= tile->tileRect.y &&
              posx <= tile->tileRect.x + tile->sizex && 
              posy <= tile->tileRect.y + tile->sizey)
             {
              return tile;
             }
         }
    }
 return NULL;  
}


void I_cCamera::MoveSmoothRight(float delta)
{
 I_cTile *ptile = GetTile(player->pos_x+player->sizex+delta,player->pos_y);
 
 I_cTile tile;
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_x = ptile->tileRect.x -  player->sizex;
  return;
 }



 ptile = GetTile(player->pos_x+player->sizex+delta,player->pos_y+player->sizey);
 
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_x = ptile->tileRect.x -  player->sizex;
  return;
 }



 if (player->pos_x >= pola_ekrana_w)
    {
	 if (currentDngMapTile_x + camera_w <= currentDungeon->tiles_w-1)
		{
		 camera_smooth_x-=delta;
		 tile_offset_x -= delta;
		 if (tile_offset_x <= -40)
			{
			 MoveOneTileRight();
			 tile_offset_x = 0;
			 camera_smooth_x = 0;
			} 
		 }else {
                player->pos_x += delta;
                
               }
    }else {
           player->pos_x += delta;
          }
          
   

}

void I_cCamera::MoveSmoothLeft(float delta)
{
 I_cTile *ptile = GetTile(player->pos_x+delta,player->pos_y);
 
 I_cTile tile;
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_x = ptile->tileRect.x+ptile->sizex;
  return;
 }
 

 
 ptile = GetTile(player->pos_x+delta,player->pos_y+player->sizey);
 
 
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_x = ptile->tileRect.x+ptile->sizex;
  return;
 } 
 

 
 if (player->pos_x <= pola_ekrana_w)
    {
	 if (currentDngMapTile_x > 0)
		{
		 camera_smooth_x-=delta;
		 tile_offset_x -= delta;
		 if (tile_offset_x >= 40)
		    {
		 	 tile_offset_x = 0;
		 	 MoveOneTileLeft();
			 camera_smooth_x = 0;
		    } 
		 }else {
                player->pos_x += delta;
		       }
     }else {
            player->pos_x += delta;
           }	
           
  

}



void I_cCamera::MoveSmoothUp(float delta)
{
 I_cTile *ptile = GetTile(player->pos_x,player->pos_y+player->sizey+delta);
 
 I_cTile tile;
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_y = ptile->tileRect.y -  player->sizey;
  return;
 }



 ptile = GetTile(player->pos_x+player->sizex,player->pos_y+player->sizey+delta);
 
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_y = ptile->tileRect.y -  player->sizey;
  return;
 }
 

 if (player->pos_y >= pola_ekrana_h)
    {
	 if (currentDngMapTile_y + camera_h <= currentDungeon->tiles_h-1)
		{
		 camera_smooth_y-=delta;
		 tile_offset_y -= delta;
		 if (tile_offset_y <= -40)
			{

			 MoveOneTileUp();
			 tile_offset_y = 0;
			 camera_smooth_y = 0;
			} 
		 }else {
                player->pos_y += delta;
               }		 
    }else {
           player->pos_y += delta;
          }
          
 
}




void I_cCamera::MoveSmoothDown(float delta)
{
 I_cTile *ptile = GetTile(player->pos_x,player->pos_y+delta);
 
 I_cTile tile;
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_y = ptile->tileRect.y+ptile->sizey;
  return;
 }

 ptile = GetTile(player->pos_x+player->sizex,player->pos_y+delta);
 
 tile.tileRect.x = player->pos_x;
 tile.tileRect.y = player->pos_y;
 tile.sizex = player->sizex;
 tile.sizey = player->sizey;
 
 if (ptile)
 if (ptile->tileId1_ == TILE_ID_WALL)
 {
  player->pos_y = ptile->tileRect.y+ptile->sizey;
  return;
 } 
 



 if (player->pos_y <= pola_ekrana_h)
    {
     if (currentDngMapTile_y > 0)
        {
         camera_smooth_y-=delta;
         tile_offset_y -= delta;
         if (tile_offset_y >= 40)
            {
		 	 tile_offset_y = 0;
		 	 MoveOneTileDown();
			 camera_smooth_y = 0;             
            }
            
        }else {
               player->pos_y += delta;
              }
     }else {
            player->pos_y += delta;
           }
}



void I_cCamera::MoveOneTileRight(void)
{
 Clear();
 currentDngMapTile_x++;
 
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           currentDrawMap[x][y] = currentDungeon->mTileMap[xp][yp];
           
           
          }
     }

 
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           for (int c=0;c<olayer.num_objects;c++)
               {
                if (olayer.objectList[c].tx == xp && olayer.objectList[c].ty == yp)
                   {
                    currentDrawObjectMap[x][y] = olayer.objectList[c].object;
                   }
               }
          }
      } 

}


void I_cCamera::MoveOneTileLeft(void)
{
 Clear();
 currentDngMapTile_x--;
 
 if (currentDngMapTile_x<0)
    {
     currentDngMapTile_x = 0;
    }
 
 
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           currentDrawMap[x][y] = currentDungeon->mTileMap[xp][yp];
          }
      
     }
     
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           for (int c=0;c<olayer.num_objects;c++)
               {
                if (olayer.objectList[c].tx == xp && olayer.objectList[c].ty == yp)
                   {
                    currentDrawObjectMap[x][y] = olayer.objectList[c].object;
                   }
               }
          }
      }      
}

void I_cCamera::MoveOneTileUp(void)
{
 Clear();
 currentDngMapTile_y++;
 
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           currentDrawMap[x][y] = currentDungeon->mTileMap[xp][yp];
          }
      
     }
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           for (int c=0;c<olayer.num_objects;c++)
               {
                if (olayer.objectList[c].tx == xp && olayer.objectList[c].ty == yp)
                   {
                    currentDrawObjectMap[x][y] = olayer.objectList[c].object;
                   }
               }
          }
      }      
}

void I_cCamera::MoveOneTileDown(void)
{
 Clear();
 currentDngMapTile_y--;
 
 if (currentDngMapTile_y < 0)
    {
     currentDngMapTile_y = 0;
    }
 
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           currentDrawMap[x][y] = currentDungeon->mTileMap[xp][yp];
          }
     }
 for (int x=0,int xp = currentDngMapTile_x;x < camera_w && xp < currentDungeon->tiles_w;x++,xp++)
     {
      for (int y=0, int yp = currentDngMapTile_y;y < camera_h && y < currentDungeon->tiles_h;y++,yp++)
          {
           for (int c=0;c<olayer.num_objects;c++)
               {
                if (olayer.objectList[c].tx == xp && olayer.objectList[c].ty == yp)
                   {
                    currentDrawObjectMap[x][y] = olayer.objectList[c].object;
                   }
               }
          }
      }      
}
 


void I_cCamera::Clear()
{
  for (int w=0;w<camera_w;w++) 
     {
      for (int h=0;h<camera_h;h++)
          {
           currentDrawMap[w][h].SetTileId(TILE_ID_NULL);
           currentDrawObjectMap[w][h].SetTileId(TILE_ID_NULL);
          }
     } 
}


I_cTile *I_cCamera::GetPlayerTile(int *tx, int *ty)
{
 for (int w=0;w<camera_w;w++) 
    {
     for (int h=0;h<camera_h;h++)
         {
          I_cTile *tile = &currentDrawMap[w][h];
          
          if (player->pos_x + player->center_x >= tile->tileRect.x && 
              player->pos_y + player->center_y >= tile->tileRect.y &&
              player->pos_x + player->center_x <= tile->tileRect.x + tile->sizex && 
              player->pos_y + player->center_y <= tile->tileRect.y + tile->sizey)
             {
              *tx = w;
              *ty = h;
              return tile;
             }
         }
    }
 return NULL;
}

