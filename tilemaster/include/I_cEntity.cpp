#include "I_cEntity.h"


I_cEntity::I_cEntity()
{
 sprite = NULL;
}


I_cEntity::~I_cEntity()
{
}


void I_cEntity::Init(int posx, int posy)
{
 sprite = new I_cSprite();
 sprite->Init(posx,posy);

}


void I_cEntity::Draw(int posx, int posy)
{
 sprite->Draw(posx,posy);
}


void I_cEntity::SetAnim(int anim)
{
 sprite->SetAnimCycle(anim);
}