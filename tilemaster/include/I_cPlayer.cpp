#include "I_cPlayer.h"



I_cPlayer::I_cPlayer()
{
}


I_cPlayer::~I_cPlayer()
{
}



void I_cPlayer::Init(int posx, int posy)
{
 pos_x = posx;
 pos_y = posy;
 
 
 //I_cEntity::Init(posx,posy);
 
 center_x = sizex/2;
 center_y = sizey/2;
 
}


void I_cPlayer::Draw()
{
// I_cEntity::Draw(pos_x,pos_y);
 //I_cTile::Draw(pos_x,pos_y);
 
 I_cSprite::Draw(pos_x,pos_y);
}