#pragma once
#include "I_cBitmap.h"
#include "gameapi.h"
#include "namedef.h"
#include <time.h>


class I_cAssetManager: public I_cBitmap
{
 public:
        I_cAssetManager();
       ~I_cAssetManager();
       
        int LoadAssets(void);
       
       
        int LoadPlayer(void);
        int LoadFloor(void);
        int LoadWall(void);
        int LoadGUI(void);
        int LoadObjects(void);
        int LoadPanel(void);
        int LoadInventory(void);
        int LoadPanelImages(void);
        
        int LoadTextPNG(void);
        GLuint GetTextureAsset(GAMEAPI_TILE_ID asset);
        
        
        
 //private:        
         //GLuint assetList[GAMEAPI_MAX_ASSETS];
         GLuint playerAsset[16];
         GLuint floorAsset[6];
         GLuint wallAsset[4];
         GLuint guiAsset[5];
         GLuint objectAsset[2];
         GLuint testAsset[8];
         GLuint panelAsset[1];
         GLuint invAsset[1];
         GLuint npcAsset[1];
         
         GLuint GetRandomFloorTex(void);
         GLuint GetRandomWallTex(void);
         GLuint GetRandomObjectTex(void);
         
};



extern I_cAssetManager *gAssetManager;