#include "I_cPlayerInventory.h"
#include "I_cAssetManager.h"


I_cPlayerInventory::I_cPlayerInventory()
{
}


I_cPlayerInventory::~I_cPlayerInventory()
{
}



void I_cPlayerInventory::Init(void)
{
 playerInvTile = new I_cTile();
 playerInvTile->Init(320,262,gAssetManager->invAsset[0]);


 invTiles = new I_cTile[24];

 for (int c=0;c<16;c++)
     {
      invTiles[c].Init(40,40,gAssetManager->guiAsset[3]);
     }


 equipped = new I_cTile[6];
 for (int c=0;c<6;c++)
     {
      equipped[c].Init(40,40,gAssetManager->guiAsset[3]);
     }

}



        
        
void I_cPlayerInventory::Draw(float startposx, float startposy)
{
 playerInvTile->Draw(startposx+40,startposy);
 
 int c=0;
 for (int x=0;x<4;x++) 
     {
      for (int y=0;y<6;y++)
          {
           invTiles[c].Draw(x*42+startposx+190,y*42+startposy+5);
          }
     } 

 equipped[0].Draw(startposx+80+15,startposy+5);



 equipped[1].Draw(startposx+40+15,startposy+40+5);
 equipped[2].Draw(startposx+120+15,startposy+40+5);
 
 equipped[3].Draw(startposx+80+15,startposy+80+5);

 equipped[4].Draw(startposx+40+15,startposy+120+5);
 equipped[5].Draw(startposx+120+15,startposy+120+5);

     
}
       