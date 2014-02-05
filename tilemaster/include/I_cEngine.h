#pragma once
#include <vector>
#include "gamedef.h"
#include "I_cFrame.h"
#include "Thread.h"
#include "Framerate.h"
#include "include\I_cCamera.h"
#include "I_cTextPanel.h"



class I_cEngine: public CThread
{
 public:
		I_cEngine();
	   ~I_cEngine();
	   
        int Init(void);	   
	   
	    void HandleEvents(void);
	   
	   int InitSDL(int w, int h, bool fs);
	   void InitGL(void);
	   
	   void PushEvent(GAMEAPI_EVENT event);
	   GAMEAPI_EVENT PollEvent(void);

       

GLfloat LightAmbient[4];
GLfloat LightDiffuse[4];
GLfloat LightPosition[4];
	   
 vector<I_cFrame*>vFrameBuffer; 
 
 vector<GAMEAPI_EVENT>vEventList;
 
 I_cTextPanel *test_textPanel;
 
 I_cTile *mainBar;

 SDL_Surface *outputSurface_;	  
 
 
 private:
         DWORD Run(LPVOID);
         void Render();
         void ProcessInput(GAMEAPI_EVENT event);
         
         
 private:
         bool run_;   
         Framerate framerate;    
         I_cCamera camera_;  
         SDL_Event sdlEvent_; 
 
};