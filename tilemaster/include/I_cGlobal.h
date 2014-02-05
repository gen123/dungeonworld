#pragma once
#include "I_cGlobalBasic.h"
#include <sdl.h>
#include <SDL_ttf.h>
#include <sdl_opengl.h>


class I_cGlobal : public I_cGlobalBasic
{
    public:
           I_cGlobal();
          ~I_cGlobal();
          
TTF_Font *font;


 bool showDebugText_;

int round(double x);
int nextpoweroftwo(int x);
                      
    public:
           void SetCurrentDir(string dir);

    private:
            string currentDir_;                      


   void drawText(char * text, TTF_Font* tmpfont);
   
   SDL_Surface *back;

}; 


extern I_cGlobal *gData;