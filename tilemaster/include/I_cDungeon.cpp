
#include "I_cDungeon.h"
#include "include\I_cAssetManager.h"


I_cDungeon::I_cDungeon()
{
}



I_cDungeon::~I_cDungeon()
{
}



void I_cDungeon::Init(void)
{

}


I_cTile *I_cDungeon::GetTile(int posx, int posy)
{
 for (int w=0;w<tiles_w;w++) 
    {
     for (int h=0;h<tiles_h;h++)
         {
          I_cTile *tile = &mTileMap[w][h];
          
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


// staro. dungeon se ne crta direktno
void I_cDungeon::Draw()
{
 //for (int w=0;w<tiles_w;w++) 
 //    {
 //     for (int h=0;h<tiles_h;h++)
 //         {
 //          this->mTileMap[w][h].Draw(0);
 //         }
 //    }
}



