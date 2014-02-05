
#include "I_cGlobalBasic.h"
#include "dtz.h"



#pragma warning(disable:4996)



//#define DEBUG_OFF

string I_cGlobalBasic::toString(int c)
{
 char *ch = new char[32];

 sprintf(ch,"%d",c);
 string s(ch);
 delete []ch;
 return s;
 
}



string I_cGlobalBasic::toStringu(unsigned long c)
{
 char *ch = new char[32];

 sprintf(ch,"%u",c);
 string s(ch);
 delete []ch;
 return s;
}



string I_cGlobalBasic::toStringf(float c)
{
 char *ch = new char[32];


 sprintf(ch,"%f",c);
 string s(ch);
 delete []ch;
 return s;
}

int I_cGlobalBasic::toInt(string s)
{

    int r = atoi(s.c_str());
 return r;
}

float I_cGlobalBasic::toFloat(string s)
{
    float f = (float)atof(s.c_str());
    return (float)f;
}



bool I_cGlobalBasic::FileExists(string path)
{
 FILE *f = NULL;
 f = fopen(path.c_str(),"r");
 if (f == NULL)
    {
     return false;
    }else {
           fclose(f);
           return true;
          }
}
 



 string I_cGlobalBasic::AppendLog(char *format, ...)
{
 #ifndef DEBUG_OFF
		LogCounter++;
		vector<char>vChar;
        int *dataptr = (int *)&format;
        char c;
        dataptr++; 
        while ((c = *format++))
                if (c != '%') 
				   {
					vChar.push_back(c);
				} else {
				           
						   switch (c = *format++)   
						          {
								   case 'd': {
											  int num = *dataptr++;  
											  char buf[10], *ptr = buf;
											  if (num < 0) 
											     {
                                                  num = -num;
											      vChar.push_back('-');
											     }
											  do {
									    
													*ptr++ = '0'+num%10;
											  }while (num /= 10);
													
													  do{
															  vChar.push_back((*--ptr));
													  }while (ptr != buf);
											  
											  break;
											 }
                              case 'x': {
                                      unsigned int num = *dataptr++,dig;
                                      char buf[8], *ptr = buf;
                                      do
                                              *ptr++ = (dig=(num&0xf)) >9?
                                                        'a' + dig - 10 :

                                                        '0' + dig;
                                      while (num >>= 4);
                                      do
                                               vChar.push_back(*--ptr);
                                      while (ptr != buf);
                                      break;
										}
                              case 'c': 
                                        vChar.push_back((*dataptr++)&0xff);
										break;
                              case 's': {
                                      char *ptr = (char *)*dataptr++;
                                      while ((c = *ptr++))
										     {
											  vChar.push_back(c);
                                            
											 }
                                      break;
                                        }
                              
                        }
				}

                          for (int c=0;c<this->indent_;c++)
                    {
                        vChar.insert(vChar.begin(),' ');
                    }


			string s;
			for (size_t c=0;c<vChar.size();c++)
			s+= vChar[c];
            _datetime_t tim = _datetime_t::now();



            string b = string(tim.fmt("%d/%m - %H:%M:%S"));

            switch (debug_mode)
               {
            case  FILE_MODE :
                  {
                   
			       logfile = fopen(path_.c_str(),"a");
                   fprintf(logfile,"#%d [%s] %s\n",LogCounter,b.c_str(),s.c_str());
			       fclose(logfile);
                   break;
                  }
                  
               case CONSOLE_MODE :
                  {
                   printf("#%d [%s] %s\n",LogCounter,b.c_str(),s.c_str());
                   break;
                  }
               }
	vChar.clear();
    return s;

#endif
return "";
} 



void I_cGlobalBasic::StartAppend(int indent, string title)
{
 this->IncInd(indent);
 
  _datetime_t tim = _datetime_t::now();
  string b = string(tim.fmt("%d/%m - %H:%M:%S"));
  // fak kaj, koji su ovo hakovi :)
  string s;
  for (int c=0;c<indent;c++) s+=" ";
 
            switch (debug_mode)
               {
            case  FILE_MODE :
                  {
                      
                   
                  logfile = fopen(path_.c_str(),"a");
  		           fprintf(this->logfile,"\n#%d [%s]%s---------------------[ START: %s ]------------------------------\n",LogCounter,b.c_str(),s.c_str(),title.c_str());
			        fclose(logfile);
                   break;
                  }
                  
               case CONSOLE_MODE :
                  {
  		            printf("\n#%d [%s]%s---------------------[ START: %s ]------------------------------\n",LogCounter,b.c_str(),s.c_str(),title.c_str());
                   break;
                  }


               }
}

void I_cGlobalBasic::StopAppend(int indent,string title)
{
  _datetime_t tim = _datetime_t::now();
  string b = string(tim.fmt("%d/%m - %H:%M:%S"));
  // fak kaj koji su ovo hakovi :)
  string s;
  for (int c=0;c<indent;c++) s+=" ";

            switch (debug_mode)
               {
            case  FILE_MODE :
                  {
                   
                  logfile = fopen(path_.c_str(),"a");
  		           fprintf(this->logfile,"\n#%d [%s]%s---------------[ STOP: %s ]------------------------------------------\n",LogCounter,b.c_str(),s.c_str(),title.c_str());
			        fclose(logfile);
                   break;
                  }
                  
               case CONSOLE_MODE :
                  {
  		            printf("\n#%d [%s]%s---------------[ STOP: %s ]------------------------------------------\n",LogCounter,b.c_str(),s.c_str(),title.c_str());
                   break;
                  }
  
               }
               
   this->DecInd(indent);
}



void I_cGlobalBasic::ResetLog(void)
{
	if (path_.empty()) 
	   {
	    path_ = "defualt_debug.txt";
	   }

	logfile = fopen(path_.c_str(),"w");
	if (logfile == NULL)
	   {
	    path_ = "defualt_debug.txt";
	   }
	    
	fclose(logfile);
	LogCounter = 0;
    this->indent_ = 0;
}



void I_cGlobalBasic::SetDebugFile(string path)
{
	path_ = path;

}

void I_cGlobalBasic::IncInd()
{
    this->indent_+=3;
}

void I_cGlobalBasic::IncInd(int i)
{
    this->indent_+=i;
}


void I_cGlobalBasic::DecInd(int i)
{
    this->indent_-= i;
    if (this->indent_ <0)
    indent_ = 0;
}

void I_cGlobalBasic::DecInd()
{
    this->indent_-=3;
    if (this->indent_ <0)
    indent_ = 0;
}

void I_cGlobalBasic::SetDebugMode(unsigned char mode)
{
    this->debug_mode = mode;
}






void I_cGlobalBasic::IntToHexString(int val, char *lo, char *hi)
{
 
 //char clo[3];
 //char chi[3];
 //char hilo[9];
 //char byte[5];

 //string shi;
 //string slo;
 //sprintf(hilo,"%p",val);
 //
 //int i=0;
 //for (int c=4,i=0;c<8;c++,i++)
 //    {
 //     byte[i] = hilo[c];
 //    }


 //byte[4] = '\0';
 //
 //for (int c=0,i=0;c<2;c++,i++)
 //    {
 //     chi[i] = byte[c];
 //    }
 //chi[2] = '\0';

 //for (int c=2,i=0;c<4;c++,i++)
 //    {
 //     clo[i] = byte[c]; 
 //    }
 //clo[2] = '\0';


 //shi = string(chi);
 //slo = string(clo);


 //sprintf(lo,"%s",slo.c_str());
 //sprintf(hi,"%s",shi.c_str());
}

bool I_cGlobalBasic::HexToDecimal (char* HexNumber, int& Number)
{ 
    char* pStopString; 
    Number = strtol (HexNumber, &pStopString, 16);
    return (bool)(Number != LONG_MAX);
}



string I_cGlobalBasic::FindChar(string s, char c, CHOICE choice)
{
 switch (choice) 
        {
         case LEFT:
              {
               const char *pChar = strchr(s.c_str(),c);
               string tmpStr;
               for (int c=0;c<(int)s.length()-(int)strlen(pChar);c++)
                   {
                    tmpStr+=s[c];
                   }
               return tmpStr;
               break;
               
              }
         case RIGHT:
              {
               const char *pChar = strchr(s.c_str(),c);
               string tmpStr(pChar);
               tmpStr.erase(tmpStr.begin());
               return tmpStr;
               break;
              }
              
         }
 return string("");
}





template <typename C>
void I_cGlobalBasic::DeleteAndClear(C & c)
{
    typename C::iterator it;
    for (it=c.begin(); it!=c.end(); ++it) 
    {
        delete *it;
    }

    c.clear();
}



//Function to convert unsigned char to string of length 2
void I_cGlobalBasic::Char2Hex(const unsigned char ch, char* szHex)
{
	unsigned char byte[2];
	byte[0] = ch/16;
	byte[1] = ch%16;
	for(int i=0; i<2; i++)
	{
		if(byte[i] >= 0 && byte[i] <= 9)
			szHex[i] = '0' + byte[i];
		else
			szHex[i] = 'A' + byte[i] - 10;
	}
	szHex[2] = 0;
}

//Function to convert string of length 2 to unsigned char
void I_cGlobalBasic::Hex2Char(const char* szHex, unsigned char& rch)
{
	rch = 0;
	for(int i=0; i<2; i++)
	{
		if(*(szHex + i) >='0' && *(szHex + i) <= '9')
			rch = (rch << 4) + (*(szHex + i) - '0');
		else if(*(szHex + i) >='A' && *(szHex + i) <= 'F')
			rch = (rch << 4) + (*(szHex + i) - 'A' + 10);
		else
			break;
	}
}    

//Function to convert string of unsigned chars to string of chars
void I_cGlobalBasic::CharStr2HexStr(const unsigned char* pucCharStr, char* pszHexStr, int iSize)
{
	int i;
	char szHex[3];
	pszHexStr[0] = 0;
	for(i=0; i<iSize; i++)
	{
		Char2Hex(pucCharStr[i], szHex);
		strcat(pszHexStr, szHex);
	}
}



//Function to convert string of chars to string of unsigned chars
void I_cGlobalBasic::HexStr2CharStr(const char* pszHexStr, unsigned char* pucCharStr, int iSize)
{
	int i;
	unsigned char ch;
	for(i=0; i<iSize; i++)
	{
		Hex2Char(pszHexStr+2*i, ch);
		pucCharStr[i] = ch;
	}
}



string I_cGlobalBasic::GetStringToken(string s, int num)
{
 string tmp;
 for (int c=0,i=0;c<(int)s.size();c++)
     {
      if (s[c] != ' ')
         {
          tmp+=s[c];
         }else return tmp;
     }
  return "";
 }
          


/*
int GetSelectedItem(CListCtrl *plctrl)
{
 
 POSITION pos = plctrl->GetFirstSelectedItemPosition();
 int selected=-1;
 if (pos != NULL)
    {
     while (pos)
           {
            int nItem = plctrl->GetNextSelectedItem(pos);
	        selected = nItem;
		   }
	}
 // -1 ako nije niti jedan selectiran
 return selected;
}

*/


