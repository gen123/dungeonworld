#pragma once
#include <sdl.h>
#include <SDL_ttf.h>
#include <sdl_opengl.h>
#include <string>
#include "I_cTile.h"
#include "freetype.h"	

using namespace std;

class I_cTextPanel
{
 public:
        I_cTextPanel();
       ~I_cTextPanel();
       
       
       void outText(int x, int y, string text,bool picture, GLuint pic);
       void SetPanelColor(GameAPI_Color from, GameAPI_Color to);
       void SetFont(string name, uint8_t size);
       
       
       
 private:
         int posx,int posy;
       
         int InitFont();
       
         I_cTile *panel;

         GameAPI_Color from_;
         GameAPI_Color to_;
         freetype::font_data our_font;	
         string fontName_;
};