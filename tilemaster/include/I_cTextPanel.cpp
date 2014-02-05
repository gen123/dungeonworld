#include "I_cTextPanel.h"
#include "I_cGlobal.h"
#include "I_cAssetmanager.h"


I_cTextPanel::I_cTextPanel()
{
 // postavke default boje
  from_.r = 0.1f;
  from_.g = 0.2f;
  from_.b = 0.5f;
  
  to_.r = 0.2f;
  to_.g = 0.2f;
  to_.b = 1.0f;  
  
  // postavi default font i size
  our_font.init("test.TTF", 8);				  
}


I_cTextPanel::~I_cTextPanel()
{
 our_font.clean();
}


void I_cTextPanel::SetPanelColor(GameAPI_Color from, GameAPI_Color to)
{
 from_.r = from.r;
 from_.g = from.g;
 from_.b = from.b;
 
 to_.r = from.r;
 to_.g = from.g;
 to_.b = from.b;
}


void I_cTextPanel::SetFont(string name, uint8_t size)
{
 our_font.clean();
 our_font.init(name.c_str(), size);				
}





void I_cTextPanel::outText(int x, int y, string text,bool picture, GLuint pic)
{
 posx = x;
 posy = y;

 freetype::print(our_font, x, y, picture,pic,from_,to_,text.c_str(), 0);
}



