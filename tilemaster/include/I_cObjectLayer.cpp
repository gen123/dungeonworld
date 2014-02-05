#include "I_cObjectLayer.h"
#include "I_cAssetManager.h"


I_cObjectLayer::I_cObjectLayer()
{
}


I_cObjectLayer::~I_cObjectLayer()
{
}


void I_cObjectLayer::Init(int numobjects, int tilesw, int tilesh)
{

 tiles_w = tilesw;
 tiles_h = tilesh;
 num_objects = numobjects;
 
 objectList = new OBJECT_LIST[numobjects];
 
 for (int c=0;c<num_objects;c++)  
    {
     objectList[c].tx = rand() % tiles_w-1;
     objectList[c].ty = rand() % tiles_h-1;

     objectList[c].tx++;
     objectList[c].ty++;
     
     objectList[c].object.Init(35,35,gAssetManager->GetRandomObjectTex());
     objectList[c].object.SetTileId(TILE_ID_OBJECT);
    }
 // 
 //}
 
    
 
}



// deprecated!
void I_cObjectLayer::Draw()
{
 //for (int x=0;x<tilesw;x++)
 //    {
 //     for (int y=0;y<tilesh;y++)
 //         {
 //          objectList[c].object.Draw(objectList[c].tx,objectList[c].ty,0);
 //         }
 //    }

 //for (int c=0;c<20;c++)  
 //    {
 //     objectList[c].object.Draw(objectList[c].tx*40,objectList[c].ty*40,0);
 //     printf("objectList[c].tx = %d\n",objectList[c].tx);
 //    }
}