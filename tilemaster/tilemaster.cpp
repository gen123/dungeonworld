// tilemaster.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "tilemaster.h"
#include "include\I_cGlobal.h"
#include "include\I_cAssetManager.h"
#include "include\I_cTile.h"
#include "include\I_cPlayer.h"
#include "include\I_cDungeonGenerator.h"
#include "include\Framerate.h"
#include <math.h>
#include "include\I_cCollisionHandler.h"
#include "include\I_cCamera.h"
#include <SDL_ttf.h>
#include <SDL_Image.h>
#include "include\I_cInventory.h"
#include "include\I_cTextPanel.h"
#include "include\I_cPlayerInventory.h"
#include "freetype.h"	
#include "include\I_cEngine.h"

#define iPI 3.14159265358979323846



GLuint	base;				// Base Display List For The Font Set
GLfloat	cnt1;				// 1st Counter Used To Move Text & For Coloring
GLfloat	cnt2;				// 2nd Counter Used To Move Text & For Coloring




I_cDungeonGenerator dngGen;
I_cDungeon *room1;
I_cDungeon *room2;
I_cDungeon *hodnik;



SDL_Event sdlEvent;

int InitSDL(int w, int h, bool fs);
void render();
void InitGL(void);



I_cObjectLayer olayer;

I_cTile *pod[6];
I_cTile *wall[4];
I_cPlayer *player = NULL;


I_cTile *tileTest;



 I_cTextPanel *textPanelNormal;
 I_cTextPanel *textPanelLines;
 I_cTextPanel *textPanelColor;
 I_cTextPanel *textPanelPicture;

float playerx = 100;
float playery = 100;

bool pressed = false;

bool mousedown;
bool upup;             //Whether the up key is up.
bool downup;           //Likewise for the down key.
bool leftup;           //You get the drift.
bool rightup; 

GLfloat LightAmbient[]=		{ 100.0f, 100.0f, 100.0f, 100.0f };
GLfloat LightDiffuse[]=		{ 35.0f, 30.0f, 30.0f, 3.0f };
GLfloat LightPosition[]=	{ 100.0f, 100.0f, 3.0f, 1.0f };


double angleLeft,angleRight,angleUp,angleDown;

I_cCamera camera;

void eventKeyUp(SDL_Event *event);
void eventKeyDown(SDL_Event *event);
 
 float vel = 1;
 float vx = 0;
 float vy = 0;
 
 
 bool leftPress;
 
bool  rightPress;
bool  upPress;
 bool downPress;
 
 bool collision = false;
 
 
 
 
  //I_cTile *side,*top;
  I_cTile *mainBar;
  I_cTile *inv1;
  I_cTile *inv2;
  I_cTile *inv3;
  I_cTile *hm;
  
  I_cTile *playerTile;
 
 
 I_cTile tt[16];
 
 I_cCollisionHandler colHandler;
 
 
 I_cInventory *gDrawInventory;
 
 
 I_cPlayerInventory playerInv;
 
 bool openInventory;
 
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow)
{
 int err = 0;
 char path[256];
 
 GetCurrentDirectory(256,path);
 
 
 // ako je program pokrenut s '-d' parametrom otvori konzolu
 gData = new I_cGlobal();
 if (string(lpCmdLine) == "-d")
    {
      gData->SetDebugMode(FILE_MODE);
    }else {
           gData->SetDebugMode(CONSOLE_MODE);
          }
 gData->SetDebugFile("tilemaster_dbg.txt");
 gData->ResetLog();
 gData->SetCurrentDir(path);
 srand(time(0));

 
 gAssetManager = new I_cAssetManager(); 
 err = gAssetManager->LoadAssets();
 if (err < 0)
    {
     printf("load assets failed\n");
     return 0;
    }
    
 I_cEngine *gameEngine = new I_cEngine();
 gameEngine->Start();
 
 int done = 1;
 while(done)
 {
 }
                      
 /*

 mainBar = new I_cTile();
 mainBar->Init(GAMEAPI_WINDOW_W,80,gAssetManager->guiAsset[1]);


 inv1 = new I_cTile();
 inv1->Init(40,40,gAssetManager->guiAsset[3]);

 inv2 = new I_cTile();
 inv2->Init(40,40,gAssetManager->guiAsset[3]);
 //
 inv3 = new I_cTile();
 inv3->Init(40,40,gAssetManager->guiAsset[3]);
 // 
 hm = new I_cTile();
 hm->Init(150,60,gAssetManager->guiAsset[4]);
 
 
 playerTile = new I_cTile();
 playerTile->Init(40,40,gAssetManager->playerAsset[0]);



 tileTest = new I_cTile();
 //tileTest->Init(60,60,true,gAssetManager->guiAsset[3]);
 tileTest->Init(60,60,gAssetManager->objectAsset[0]);


 //side = new I_cTile();
 //side->Init(240,80,true,gAssetManager->guiAsset[0]);
 
 player = new I_cPlayer();
 player->Init(playerx,playery);
 player->SetTexture(gAssetManager->playerAsset[0]);

 //for (int c=0;c<16;c++)
 //    {
 //     tt[c].Init(60,60,true,gAssetManager->Asset[c]);
 //    }
 
 //player->SetAnim(-1);
 player->sizex = 34;
 player->sizey = 50;
 

 room1 = new I_cDungeon();
 dngGen.test_CreateRoom1(room1);

for (int c=0;c<16;c++)
    {
     tt[c].Init(40,40,gAssetManager->playerAsset[c]);
    }
    
    
    

int done = 1;
upup = true;           //Initialize all the key booleans to true.
downup = true;
leftup = true;
rightup = true;
 
 leftPress = false;
 rightPress = false;
 upPress = false;
 downPress = false;
 
 





 angleLeft = 180*iPI /180;
 angleRight = 0;
 angleUp = 270*iPI /180;
 angleDown = 90*iPI /180;


 playerInv.Init();

 vel = 4;



 while(done)
 {
  while (SDL_PollEvent(&sdlEvent))
        {
         switch (sdlEvent.type)
                {
                 case SDL_QUIT:
                      { 
                       gameEngine->PushEvent(GAMEAPI_EVENT_QUIT);
                       done = false;
                       break;
                      }
                      
                      
                  case SDL_KEYDOWN:
                  {
                   eventKeyDown(&sdlEvent);
                  switch (sdlEvent.key.keysym.sym )
                         {
                          case SDLK_RIGHT:
                          gameEngine->PushEvent(GAMEAPI_EVENT_KEY_RIGHT);
                          //player->SetAnimation(GAMEAPI_WALK_RIGHT_MARK,GAMEAPI_WALK_RIGHT_MARK+3);
                          //delete gDrawInventory;
                          //gDrawInventory = NULL;
                          break;
                          case SDLK_LEFT:
                          gameEngine->PushEvent(GAMEAPI_EVENT_KEY_LEFT);
                          //player->SetAnimation(GAMEAPI_WALK_LEFT_MARK,GAMEAPI_WALK_LEFT_MARK+3);
                          //delete gDrawInventory;
                          //gDrawInventory = NULL;
                          break;
                          case SDLK_DOWN:
                          gameEngine->PushEvent(GAMEAPI_EVENT_KEY_DOWN);
                          //player->SetAnimation(GAMEAPI_WALK_DOWN_MARK,GAMEAPI_WALK_DOWN_MARK+3);
                          //delete gDrawInventory;
                          //gDrawInventory = NULL;
                          break;
                          case SDLK_UP:
                          gameEngine->PushEvent(GAMEAPI_EVENT_KEY_UP);
                          //player->SetAnimation(GAMEAPI_WALK_UP_MARK,GAMEAPI_WALK_UP_MARK+3);
                          //delete gDrawInventory;
                          //gDrawInventory = NULL;
                          break;
                          
                         // case SDLK_e:
                         // {
                         //  // ako je otvoren inventory, nemoj nista raditi samo nastavi
                         //  if (gDrawInventory)
                         //     {
                         //      delete gDrawInventory;
                         //      gDrawInventory = NULL;
                         //      continue;
                         //     }
                         // 
                         // 
                         //  I_cTile *tile = camera.GetTile(player->pos_x,player->pos_y);
                         //  if (tile->objectItem)  // postoji item na ovom polju
                         //     {
                         //      if (tile->objectItem->itemCount > 0)
                         //         {
                         //          // stvori inventory sa itemCount inv-tilea i prikazi iteme
                         //          gDrawInventory = new I_cInventory();
                         //          gDrawInventory->Init(player->pos_x, player->pos_y,tile->objectItem->itemCount);
                         //          // na ovom mjestu treba ubaciti inventory u draw buffer
                         //         }
                         //     }
                         // }
                         // 
                         // case SDLK_p:
                         // {
                         //  gData->showDebugText_ = !gData->showDebugText_;
                         //  break;
                         // }      

                         // case SDLK_i:   // otvori inventory
                         // {
                         //  openInventory = !openInventory;
                         //  break;
                         // }                

                         // case SDLK_q:   // otvori inventory
                         // {
                         //  
                         //  break;
                         // }    
                         // 
                         // default:
                         // {
                         //  // zatvori inventoru ako je otvoren
                         // }
                         //  
                         }
                         
                  
                  break;
                 }
                 
                // case SDL_KEYUP:
                // {
                //  player->StopAnimation();
                //  eventKeyUp(&sdlEvent);
                //  break;
                // }
                // 
                // case SDL_MOUSEBUTTONUP:
                // {
                //  if (sdlEvent.button.button == 1)  // left
                //     {
                //      I_cTile *tile = camera.GetObjectTile(sdlEvent.button.x,sdlEvent.button.y);
                //      if (tile)
                //         {
                //          printf("tileid = %d\n",tile->tileId1_);
                //         }else {
                //                // inventory tile?
                //               }
                //      
                //      
                //     }
                // }
                // 
                }
           
        }
        
  

   //render();

   
   
   

   
  } 
  
  */
 return 0;
}



void render()
{
  glClearColor(0.2f, 0.2f, 0.2f, 0.0f);  


    glBegin( GL_QUADS );
	
	glVertex3f( 0, 0, 0 );
	glVertex3f( 10,0, 0 );
	glVertex3f( 10,10, 0 );
	glVertex3f(  0,10, 0 );

    glEnd();

  
  

 SDL_GL_SwapBuffers();
}






void eventKeyUp(SDL_Event *event)
{
 switch (event->key.keysym.sym)
        {
         case SDLK_LEFT:
              leftPress  = false;
              break;
         case SDLK_RIGHT:
              rightPress = false;
              break;
         case SDLK_UP:
              upPress = false;
              break;
         case SDLK_DOWN:
              downPress = false;
              break;
         default: break;
        }
}



void eventKeyDown(SDL_Event *event)
{
 
 switch (event->key.keysym.sym)
        {
         case SDLK_LEFT:
              {
               leftPress = true;
               vx = vel * cos(angleLeft);
               break;
              }
         case SDLK_RIGHT:
              {
               rightPress = true;
               vx = vel * cos(angleRight);
               break;
              }
         case SDLK_UP:
              {
               upPress = true;
               vy = vel * sin(angleUp);               
               break;
              }
         case SDLK_DOWN:
              {
               downPress = true;
               vy = vel * sin(angleDown);               
               break;
              }
         default: break;
        }
}









