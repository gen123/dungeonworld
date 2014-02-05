#pragma once
#include "I_cDungeon.h"


class I_cDungeonGenerator
{
 public:
		I_cDungeonGenerator();
	   ~I_cDungeonGenerator();
	   
	   
 public:
        I_cDungeon *Generate(void);	   
        
 //private:
         void test_CreateRoom1(I_cDungeon *dng);    
         void test_CreateRoom2(I_cDungeon *dng);       
         void test_CreateCorridor(I_cDungeon *dng);       
};