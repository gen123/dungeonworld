#include "I_cAssetManager.h"
#include "I_cGlobal.h"


I_cAssetManager *gAssetManager = 0;


I_cAssetManager::I_cAssetManager()
{

}


I_cAssetManager::~I_cAssetManager()
{
}



int I_cAssetManager::LoadAssets(void)
{
 int err = 0;
 err = LoadPlayer();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    } 
  
 err = LoadFloor();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    } 
 
  
 err = LoadWall();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    }  
   
   
 err = LoadGUI();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    }  
 
    
 err = LoadObjects();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    }  
 
     
 err = LoadTextPNG();
 if (err < 0)
    {
     return -1;
     return (0);
    }  
    
 
      
 err = LoadPanelImages();
 if (err < 0)
    {
     return -1;
     return (0);
    }  
    
 
 
 
     
 err = LoadPanel();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    }  

 err = LoadInventory();
 if (err < 0)
    {
     gData->AppendLog("MAIN: LoadAssets failed!");
     return -1;
    }  
        
    
    

 return 0;
}


int I_cAssetManager::LoadPlayer()
{
 
 string resdir = "data/tiles/entity/player/";
 
 

 for (int c=0;c<16;c++)
     {
      string pth = resdir + gData->toString(c) + ".png";
      int err = 0;
      err = Load(pth, &playerAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     }
 return 0;
}



int I_cAssetManager::LoadFloor()
{
 
 string resdir = "data/tiles/floor/";
 
 

 for (int c=0;c<6;c++)
     {
      string pth = resdir + gData->toString(c) + ".bmp";
      int err = 0;
      err = Load(pth, &floorAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     }
 return 0;
}




int I_cAssetManager::LoadPanelImages()
{
 
 string resdir = "data/npc/";
 
 
      string pth = resdir + "guts.png";
      int err = 0;
      err = Load(pth, &npcAsset[0]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     
 return 0;
}


int I_cAssetManager::LoadPanel(void)
{
 string resdir = "data/tiles/panel/";
 
 
      string pth = resdir + "panel.png";
      int err = 0;
      err = Load(pth, &panelAsset[0]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     
 return 0;
}




int I_cAssetManager::LoadInventory()
{
 
 string resdir = "data/tiles/else/";
 
 
      string pth = resdir + "wall.png";
      int err = 0;
      err = Load(pth, &invAsset[0]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     
 return 0;
}



int I_cAssetManager::LoadWall()
{
 
 string resdir = "data/tiles/wall/";
 
 

 for (int c=0;c<4;c++)
     {
      string pth = resdir + gData->toString(c) + ".bmp";
      int err = 0;
      err = Load(pth, &wallAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     }
 return 0;
}


int I_cAssetManager::LoadGUI(void)
{
 string resdir = "data/tiles/gui/";
 
 

 for (int c=0;c<5;c++)
     {
      string pth = resdir + gData->toString(c) + ".bmp";
      int err = 0;
      err = Load(pth, &guiAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     } 
}


int I_cAssetManager::LoadObjects(void)
{
 string resdir = "data/tiles/objects/";
 
 

 for (int c=0;c<2;c++)
     {
      string pth = resdir + gData->toString(c) + ".png";
      int err = 0;
      err = Load(pth, &objectAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     } 
}


int I_cAssetManager::LoadTextPNG(void)
{
 string resdir = "data/tiles/test/";
 
 

 for (int c=0;c<8;c++)
     {
      string pth = resdir + gData->toString(c) + ".png";
      int err = 0;
      err = Load(pth, &testAsset[c]);
      if (err < 0)
         {
          //gData->AppendLog("ASSET LOAD: Error on loading asset %s. Defaulting to EMPTY.",gameapiTextureName[c].name);
          return -1;
         }
     } 
}


GLuint I_cAssetManager::GetTextureAsset(GAMEAPI_TILE_ID asset)
{
 //GLuint asst =  assetList[asset];
 //return asst;
 return 0;
}


GLuint I_cAssetManager::GetRandomFloorTex(void)
{

 
 return floorAsset[rand() % 6];
}


GLuint I_cAssetManager::GetRandomWallTex(void)
{

 
 return wallAsset[rand() % 4];
}


GLuint I_cAssetManager::GetRandomObjectTex(void)
{
 return objectAsset[rand() % 2];
}



