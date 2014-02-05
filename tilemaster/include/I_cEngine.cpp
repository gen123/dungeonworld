#include "gameapi.h"
#include "I_cEngine.h"
#include "I_cGlobal.h"
#include "include\I_cAssetManager.h"






I_cEngine::I_cEngine() 
{

 
 LightAmbient[0] = 100.0f;
 LightAmbient[1] = 100.0f;
 LightAmbient[2] = 100.0f;
 LightAmbient[3] = 100.0f;
 
 LightDiffuse[0] = 35.0f;
 LightDiffuse[1] = 30.0f;
 LightDiffuse[2] = 30.0f;
 LightDiffuse[3] = 3.0f;
 
 
 LightDiffuse[0] = 100.0f;
 LightDiffuse[1] = 100.0f;
 LightDiffuse[2] = 3.0f;
 LightDiffuse[3] = 1.0f; 
 
 outputSurface_ = NULL; 
 run_ = true;
 
 test_textPanel = NULL;
}



I_cEngine::~I_cEngine()
{
}



int I_cEngine::Init(void)
{
 int err = 0;
 
 err = InitSDL(GAMEAPI_WINDOW_W,GAMEAPI_WINDOW_H,true);
 if (err < 0)
    {
     return -1;
    }
    
 InitGL();    
    
 //TTF_Init();     
 
// camera_.Init(GAMEAPI_WINDOW_W,GAMEAPI_WINDOW_H,room1,player);



  mainBar = new I_cTile();
 mainBar->Init(GAMEAPI_WINDOW_W,80,gAssetManager->guiAsset[1]);
 

 test_textPanel = new I_cTextPanel();

}





int I_cEngine::InitSDL(int w, int h, bool fs)
{
 if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
     return -1;
    }
    
 const SDL_VideoInfo* info = NULL;    
 info = SDL_GetVideoInfo( );    
    
 int bpp  = info->vfmt->BitsPerPixel;
        
 SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
 SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
 SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
 SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 32 );
 SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );


 outputSurface_ = SDL_SetVideoMode(w,h, bpp, SDL_HWSURFACE  | SDL_OPENGL);
 if (!outputSurface_) 
    {
     gData->AppendLog("SYSTEM: Unable to set video mode.");
     return -1;
    }  

  
  
 return 0; 
}


void I_cEngine::PushEvent(GAMEAPI_EVENT event)
{
 
 vEventList.push_back(event);
}


GAMEAPI_EVENT I_cEngine::PollEvent(void)
{
 GAMEAPI_EVENT popEvent = GAMEAPI_EVENT_NO_EVENT;
 if (vEventList.size() > 0)
    {
     popEvent = vEventList[vEventList.size()-1];
     vEventList.pop_back();    
    }
 return popEvent;
}







void I_cEngine::InitGL(void)
{

 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	

 glClearColor( 0.7f, 0.7f, 0.7f, 0.0f );
 glViewport( 0, 0, GAMEAPI_WINDOW_W, GAMEAPI_WINDOW_H);
 glClear( GL_COLOR_BUFFER_BIT );
 glMatrixMode( GL_PROJECTION );
 glLoadIdentity();
 glOrtho(0.0f, GAMEAPI_WINDOW_W, GAMEAPI_WINDOW_H, 0.0f, 1.0f, -1.0f);
 glMatrixMode( GL_MODELVIEW ); 
 glLoadIdentity();
 
 
  //glEnable(GL_LIGHTING);
  //   glLightfv(GL_LIGHT0, GL_DIFFUSE, LightAmbient);		//
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);	// Position The Light
	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT0);
 //
 
 

}

void I_cEngine::HandleEvents(void)
{
 GAMEAPI_EVENT event = PollEvent();

 switch(event)
       {
        case GAMEAPI_EVENT_QUIT:
             run_ = false;
        break;
        

        case GAMEAPI_EVENT_KEY_LEFT:
        case GAMEAPI_EVENT_KEY_RIGHT:
        case GAMEAPI_EVENT_KEY_UP:
        case GAMEAPI_EVENT_KEY_DOWN:
             ProcessInput(event);
        break;

        
        default: break;
       } 
}


DWORD I_cEngine::Run(LPVOID)
{
 char tmp[8];
 Init();
 
 while(run_)
      {
       SDL_PollEvent(&sdlEvent_);
	   switch (sdlEvent_.type)
			  {
			   case SDL_QUIT:
			   { 
				PushEvent(GAMEAPI_EVENT_QUIT);
				break;
			   }
              
               case SDL_KEYDOWN:
               {
                //eventKeyDown(&sdlEvent_);
                switch (sdlEvent_.key.keysym.sym )
                       {
                        case SDLK_RIGHT:
                        PushEvent(GAMEAPI_EVENT_KEY_RIGHT);			  
                       }
               } 
			  }      
       
       HandleEvents();
       framerate.Update();
       sprintf(tmp,"%d",framerate.GetFPS());
       SDL_WM_SetCaption(tmp,0);       
       
       Render();
      }
 return 0;
}



void I_cEngine::ProcessInput(GAMEAPI_EVENT event)
{
/*      if (leftPress) 
          {
          float vp = vx*framerate.GetSpeedFactor();
          camera.MoveSmoothLeft(vp);
          
          }
      if (rightPress)
          {
          float vp = vx*framerate.GetSpeedFactor();
          camera.MoveSmoothRight(vp);
          }    
      if (upPress)
         {
          float vp = vy*framerate.GetSpeedFactor();
          camera.MoveSmoothDown(vp);
         }    
      if (downPress)
         {
          float vp = vy*framerate.GetSpeedFactor();
          camera.MoveSmoothUp(vp);
          } */   
}



void I_cEngine::Render(void)
{
  glClearColor(0.2f, 0.2f, 0.2f, 0.0f);  
  glClear(GL_COLOR_BUFFER_BIT);
  

  //mainBar->Draw(0,0);

  //test_textPanel->outText(10,10,"test",0,0);
     
		//				glEnable(GL_LIGHTING);
		//				LightPosition[0] = player->pos_x;
		//				LightPosition[1] = player->pos_y;
		//				glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
  //camera_.Draw();
  //						glDisable(GL_LIGHTING);
  
  

    glBegin( GL_QUADS );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 10,0, 0 );
	glVertex3f( 10,10, 0 );
	glVertex3f(  0,10, 0 );

glEnd();

  
  

 SDL_GL_SwapBuffers();
}












