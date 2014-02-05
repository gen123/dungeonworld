#include "I_cSprite.h"
#include "I_cAssetManager.h"


I_cSprite::I_cSprite()
{
// currentTexNum = 0;
 currentAnim = 0;
 currentTexture = 0;
}


I_cSprite::~I_cSprite()
{
}





void I_cSprite::Init(int posx, int posy)
{
 I_cTile::Init(ENTITY_SIZE_W,ENTITY_SIZE_H,0);
 
 half_w = ENTITY_SIZE_W/2;
 half_h = ENTITY_SIZE_H/2;

}


void I_cSprite::SetAnimation(int anim_start, int anim_end)
{
 currentAnim = anim_start;
 currentAnimEnd = anim_end;
 currentTexture = currentAnim;
 
 printf("anim start = %d, end = %d\n",anim_start,anim_end);
 
 stop = false;
}


void I_cSprite::StopAnimation()
{
 I_cTile::SetTexture(gAssetManager->playerAsset[currentAnim]);
 stop = true;
}

void I_cSprite::Draw(int posx, int posy)
{
 
 if (stop == false)
    {
     if (currentTexture > currentAnimEnd)
        {
         currentTexture = currentAnim;
        }
     I_cTile::SetTexture(gAssetManager->playerAsset[currentTexture++]);
    }

 
 I_cTile::Draw(posx,posy);
 

}











