#pragma once
#include "tilemaster.h"
#include "gameapi.h"





class I_cBitmap
{
 public:
        I_cBitmap();
       ~I_cBitmap();
       
        int Load(string path, GLuint *texture);
        virtual void Draw(void);
       


 private:
         SDL_Surface *surface;       
         SDL_Rect bitmapRect;
         
         
         
           
};