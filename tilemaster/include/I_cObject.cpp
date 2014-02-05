#include "I_cObject.h"




I_cObject::I_cObject()
{
}



I_cObject::~I_cObject()
{
}



void I_cObject::Init(int sx, int sy, GLuint objTex)
{
 objectTexture = objTex;
 sizex = sx;
 sizey = sy;
 itemCount =  rand() % 12;
 itemCount++;
}
	   
void I_cObject::Draw(int posx, int posy)
{
 
 objectRect.x = posx;
 objectRect.y = posy;
 objectRect.w = objectRect.x + sizex;
 objectRect.h = objectRect.y + sizey;


 glEnable(GL_TEXTURE_2D);
 glBindTexture( GL_TEXTURE_2D, objectTexture);
 
 glBegin( GL_QUADS );
	// gore ljevo 
	glTexCoord2i( 0, 0 );
	glVertex3f( objectRect.x,  objectRect.y, 0 );
 
	// gore desno
	glTexCoord2i( 1, 0 );
	glVertex3f( objectRect.w, objectRect.y, 0 );
 
	// dolje desno (corner)
	glTexCoord2i( 1, 1 );
	glVertex3f( objectRect.w, objectRect.h, 0 );
 
	// dolje ljevo
	glTexCoord2i( 0, 1 );
	glVertex3f(  objectRect.x,  objectRect.h, 0 );
glEnd();

glDisable(GL_TEXTURE_2D);
}



