#include "I_cInventory.h"
#include "I_cAssetManager.h"


I_cInventory::I_cInventory()
{
}


I_cInventory::~I_cInventory()
{
}



void I_cInventory::Init(float posx, float posy, int itemcount)
{
 
 pos_x = posx;
 pos_y = posy;
 itemCount = itemcount;
 
 invTiles = new I_cTile[itemCount];

 for (int c=0;c<itemCount;c++)
     {
      invTiles[c].Init(40,40,gAssetManager->guiAsset[3]);
     }
 
 
 
}
        
        
void I_cInventory::Draw()
{
 int x=0,y=0,c=0;
 int drawx = 0;
 int drawy = 0;
 
 while (c<itemCount)
       {
        drawx = x*40+pos_x;   
        drawy = y*40+pos_y;
        
        invTiles[c].Draw(drawx,drawy);
        
        x++;
        if (x > 3)
           {
            x = 0;
            y++;
           }
        c++;   
       }
}
       