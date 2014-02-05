#pragma once
#include "I_cTile.h"
#include <vector>


using namespace std;


class I_cDungeon
{
 public:
        I_cDungeon();
       ~I_cDungeon();
       
        void Init(void);
       
        //vector<vector<I_cTile*> >vTileMap;
        I_cTile **mTileMap;
        
        void Draw();
        
        I_cTile *GetTile(int posx, int posy);
        
      int tiles_w;
      int tiles_h;
};