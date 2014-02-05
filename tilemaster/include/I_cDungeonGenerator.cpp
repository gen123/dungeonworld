#include "I_cDungeonGenerator.h"
#include "I_cAssetManager.h"



I_cDungeonGenerator::I_cDungeonGenerator()
{
}


I_cDungeonGenerator::~I_cDungeonGenerator()
{
}



I_cDungeon *I_cDungeonGenerator::Generate(void)
{
 I_cDungeon *dng = new I_cDungeon();
 
 return dng; 
}



void I_cDungeonGenerator::test_CreateRoom1(I_cDungeon *dng)     
{

 dng->tiles_w = 27;
 dng->tiles_h = 20;


 // stvori 2D polje 
 dng->mTileMap = new I_cTile*[dng->tiles_w];
 for (int c=0;c<dng->tiles_w;c++)
     {
      try {
           dng->mTileMap[c] = new I_cTile[dng->tiles_h];
          }catch(...)
                {
                 printf("uhvatio sam exception prilikom stvaranja\n");
                 return;
                }
     }
  

 
 // postavi sva polja da su zid
 for (int w=0;w<dng->tiles_w;w++)
     {
      for (int h=0;h<dng->tiles_h;h++)
          {
           I_cTile *ptrTile = &dng->mTileMap[w][h];

           ptrTile->Init(GAME_TILE_SIZE_W,GAME_TILE_SIZE_H,gAssetManager->GetRandomWallTex());
           ptrTile->SetTileId(TILE_ID_WALL);
           printf("");
          }
     }

 // postavi sva unutarnja polja da su daske
 for (int w=1;w<dng->tiles_w-1;w++)
     {
      for (int h=1;h<dng->tiles_h-1;h++)
          {
           dng->mTileMap[w][h].Init(GAME_TILE_SIZE_W,GAME_TILE_SIZE_H,gAssetManager->GetRandomFloorTex());
           dng->mTileMap[w][h].SetTileId(TILE_ID_FLOOR);
          }
     }
     
 
 // stvori nekoliko zidova unutar mape
 for (int c=0;c<13;c++)  
    {
     int ww = rand() % dng->tiles_w;
     int hh = rand() % dng->tiles_h;

     dng->mTileMap[ww][hh].Init(GAME_TILE_SIZE_W,GAME_TILE_SIZE_H,gAssetManager->GetRandomWallTex());
     dng->mTileMap[ww][hh].SetTileId(TILE_ID_WALL);
    }
    
 // stvori nekoliko itema na mapi
 for (int c=0;c<20;c++)
     {
      int ww = rand() % dng->tiles_w;
      int hh = rand() % dng->tiles_h;
      
      dng->mTileMap[ww][hh].CreateTileItem(gAssetManager->GetRandomObjectTex());
     }

   

}
   
void I_cDungeonGenerator::test_CreateRoom2(I_cDungeon *dng)       
{
 //int startx = 7*40;
 //int starty = 7*40;

 //dng->tiles_h = 8;
 //dng->tiles_w = 4;
 //
 //dng->mTileMap = new I_cTile*[dng->tiles_h];
 //
 //for (int c=0;c<dng->tiles_h;c++)
 //    {
 //     dng->mTileMap[c] = new I_cTile[dng->tiles_w];
 //    }
 //    
 //for (int c=0;c<dng->tiles_h;c++)
 //    {
 //     for (int i=0;i<dng->tiles_w;i++)
 //         {
 //          dng->mTileMap[c][i].Init(c*40+startx,i*40+starty,40,40,true,gAssetManager->GetRandomWallTex());
 //          dng->mTileMap[c][i].SetTileId(TILE_ID_WALL);
 //         }
 //    }


 //for (int c=1;c<dng->tiles_h-1;c++)
 //    {
 //     for (int i=1;i<dng->tiles_w-1;i++)
 //         {
 //          dng->mTileMap[c][i].Init(c*40+startx,i*40+starty,40,40,true,gAssetManager->GetRandomFloorTex());
 //         }
 //    }

}


void I_cDungeonGenerator::test_CreateCorridor(I_cDungeon *dng)
{
 //int startx = 5*40;
 //int starty = 3*40; 
 //
 //dng->tiles_h = 6;
 //dng->tiles_w = 5;
 //
 //dng->mTileMap = new I_cTile*[dng->tiles_h];
 //
 //for (int c=0;c<dng->tiles_h;c++)
 //    {
 //     dng->mTileMap[c] = new I_cTile[dng->tiles_w];
 //    }
 //    
 //for (int c=0;c<dng->tiles_h;c++)
 //    {
 //     for (int i=0;i<dng->tiles_w;i++)
 //         {
 //          dng->mTileMap[c][i].Init(c*40+startx,i*40+starty,40,40,true,gAssetManager->GetRandomWallTex());
 //         }
 //    }


 //for (int c=1;c<dng->tiles_h-1;c++)
 //    {
 //     for (int i=1;i<dng->tiles_w-1;i++)
 //         {
 //          dng->mTileMap[c][i].Init(c*40+startx,i*40+starty,40,40,true,gAssetManager->GetRandomFloorTex());
 //         }
 //    }
 //    
 //dng->mTileMap[0][1].SetTexture(gAssetManager->floorAsset[0]);
 //dng->mTileMap[3][4].SetTexture(gAssetManager->floorAsset[1]);
 //dng->mTileMap[4][4].SetTexture(gAssetManager->floorAsset[1]);
 
}







