#ifndef GAMEAPI_H
#define GAMEAPI_H

#include "tilemaster.h"


#define GAMEAPI_MAX_ASSETS 8
#define GAMEAPI_MAX_SPRITE 8

#define GAMEAPI_WINDOW_W 800
#define GAMEAPI_WINDOW_H 600

#define GAMEAPI_WALK_RIGHT_MARK 0
#define GAMEAPI_WALK_LEFT_MARK 4
#define GAMEAPI_WALK_DOWN_MARK 8
#define GAMEAPI_WALK_UP_MARK 12

#define GAME_TILE_SIZE_W 40
#define GAME_TILE_SIZE_H 40

typedef struct GameAPI_Tile
{
 int def;
}GAMEAPI_TILE;

#define ENTITY_SIZE_W 40
#define ENTITY_SIZE_H 40

typedef enum GameAPI_Tile_ID
{
 TILE_ID_NULL = 0,
 TILE_ID_WALL = 1,
 TILE_ID_FLOOR = 2,
 TILE_ID_OBJECT = 3

}GAMEAPI_TILE_ID;


typedef enum GameAPI_Object_ID
{
 OBJECT_ID_INVENTORY = 0,
 OBJECT_ID_ITEM =1

}GAMEAPI_OBJECT_ID;
        

typedef enum GameAPI_WalkUp
{
 SPRITE_WALK0 = 0,
 SPRITE_WALK1 = 1,
 SPRITE_WALK2 = 2,
 SPRITE_WALK3 = 3,
 SPRITE_WALK4 = 4,
 SPRITE_WALK5 = 5,
 SPRITE_WALK6 = 6,
 SPRITE_WALK7 = 7
}GAMEAPI_WALK_UP;


typedef struct GameAPI_Color
{
 float r,g,b;
}GameAPI_Color;



        


typedef struct GameAPI_POSITION
{
 int x;
 int y;
}GAMEAPI_POSITION; 



typedef struct GameAPI_INDEX_TEXT_PAIR
{
 uint16_t index;
 const char *name;
}GAMEPI_INDEX_TEXT_PAIR;





#endif