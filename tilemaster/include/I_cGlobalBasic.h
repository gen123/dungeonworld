#pragma once

#include <stdio.h>
#include <string>
#include <vector>


//EditBin debug\filename.exe /SUBSYSTEM:CONSOLE

using namespace std;



#define FILE_MODE 0x01
#define CONSOLE_MODE 0x02

//#define DEBUG_OFF


typedef unsigned char CHOICE;

const CHOICE LEFT  = 0x01;
const CHOICE RIGHT = 0x02;

class I_cGlobalBasic
{
 public:
    

	string toString(int c);
	string toStringu(unsigned long c);
	string toStringf(float c);
    int toInt(string s);
    float toFloat(string s); 

	virtual string AppendLog(char *format, ...);
	void StartAppend(int indent, string title);
	void StopAppend(int indent,string title);
	void ResetLog(void);
    //int GetMessageParam(int *param);
	void SetDebugFile(string path);
    void IncInd();
    void IncInd(int i);
    void DecInd();
    void DecInd(int i);
    void SetDebugMode(unsigned char mode);
    
    string FindChar(string s, char c, CHOICE choice);
    //char *FindTxt(string *s, char c);    

    bool HexToDecimal (char* HexNumber, int& Number);
    void IntToHexString(int val, char *lo, char *hi);
    void Char2Hex(const unsigned char ch, char* szHex);
    void Hex2Char(const char* szHex, unsigned char& rch);
    void CharStr2HexStr(const unsigned char* pucCharStr, char* pszHexStr, int iSize);
    void HexStr2CharStr(const char* pszHexStr, unsigned char* pucCharStr, int iSize);
    
    string GetStringToken(string s,int num);
    
    bool FileExists(string path);
    

    template <typename C> void DeleteAndClear(C & c);
	string path_;


	private:
	FILE *logfile;
	unsigned long LogCounter;

	int indent_;              //  NI
	string indent_string_;    //  NI
    unsigned char debug_mode;
    //_datetime_t datetime;

	
	
};