#include "I_cCollisionHandler.h"



I_cCollisionHandler::I_cCollisionHandler()
{
}

I_cCollisionHandler::~I_cCollisionHandler()
{
}


bool I_cCollisionHandler::Collide(I_cTile *tile1, I_cTile *tile2)
{

 int playerx = tile2->tileRect.x;
 int playery = tile2->tileRect.y;
 int playersx = tile2->sizex;
 int playersy = tile2->sizey;
 
 
 int wallx = tile1->tileRect.x;
 int wally = tile1->tileRect.y;
 
 int wallx1 = tile1->tileRect.x + tile1->sizex;
 int wally1 = tile1->tileRect.x + tile1->sizey;


 if (check(playerx,playery,tile1) || check(playerx+playersx,playery+playersy,tile1))
    {
     return true;
    }

 return false;
}






bool I_cCollisionHandler::check(int x, int y, I_cTile *tile)
{
 if (x > tile->tileRect.x && 
     y > tile->tileRect.y && 
     x < tile->tileRect.x + tile->tileRect.x + tile->sizex && 
     y < tile->tileRect.y + tile->tileRect.y + tile->sizey)
    {
     return true;
    }
    
    
    return false;
}

