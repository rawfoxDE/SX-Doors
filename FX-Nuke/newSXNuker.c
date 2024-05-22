/*

System-X FileCheck Door (designed for the Conference Based Version!)

This source is public domain, do what you want with it!

*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <sxstructs.h>

struct MsgPort *bbsport;

struct JHMessage
{
  struct Message Msg;
  char String[200];
  int Data;
  int Command;
} themsg;


void PS(char * str);
void XIMFunction(int func, long data, char * str);
void Nuker(void);

int main(int argc, char *argv[])
{
	char portname[16];

	if(argv[1][0]==0)
	{
		PutStr("This program requires System-X BBS Software\n");
	} else {
		sprintf(portname, "AEDoorPort%s", argv[1]);
		bbsport = FindPort(portname);
		if(bbsport)
		{
			XIMFunction(1, 0, 0); 	/* function 1 = register */

			Nuker();

			XIMFunction(2, 0, 0); 	/* function 2 = shutdown */
		}
	}
}

void PS(char * str)
{
	XIMFunction(1500, (long)str, 0);  /* XIM Function to send some text to SX */
}

void XIMFunction(int func, long data, char * str)
{
	struct MsgPort *replyport;

	replyport = CreateMsgPort();
	if(replyport)
	{
		themsg.Msg.mn_Length	= sizeof(struct JHMessage);
		themsg.Msg.mn_ReplyPort	= replyport;
		themsg.Data 		= data;
		themsg.Command 		= func;
		if(str && str[0]!=0) strcpy(themsg.String, str);
		PutMsg(bbsport, (struct Message *)&themsg);
		WaitPort(replyport);
		DeleteMsgPort(replyport);
	}
}

void Nuker(void)
{
   char buf[256],filename[36],fname[1024], *arg;
   BPTR lck, fh;

   lck = Lock(filename, SHARED_LOCK);
   if(!lck) return;
   UnLock(lck);

   XIMFunction(1507, 0, 0);
   arg = (char *)themsg.Data;

        if(arg[0]!=0)
	{
		strcpy(filename, arg);
	}
        else 
        {
        PS("\n\r\033[34m.----------------------[ \033[36mSXNuker\033[34m ]--------------------->-->>-->>>\n\r\n\r");     
        PS("\033[34m`------------------------------------------------------------->-->>>\r\n\033[2A");
	XIMFunction(5, 34, "\033[34m|\033[33m  Enter Filename : \033[31m");
        if(themsg.Data==-1) XIMFunction(2,0,0);
	if(themsg.String[0]==0) return;
        strcpy(filename, themsg.String);
        }
        
        PS("\n\r\033[33m   ... search for : \033[37m");
        PS(filename);
        PS("\n\r\033[0m");

        fh = Open("SX:Prefs/Confs.DAT", MODE_OLDFILE);
        
	if(fh)
	{
	struct ConfStruct Conf;

		while(1)
		{
        		if(Read(fh, &Conf, sizeof(struct ConfStruct)))
			{
                           sprintf(buf, "\r\n\033[32m   search in: \033[36m%s ..", Conf.name);
                           PS("\033[35x");
			   PS(buf);
                       
			   if(Conf.filepath[0] == 0)
			   lck = 0;
			   else 
			        {
			        sprintf(fname, "%s%s", Conf.filepath, filename);
		        	lck = Lock(fname, SHARED_LOCK);
			        }

			    if(lck)
			    {
			    UnLock(lck);
                            PS("\033[35m  >> FOUND !!!! << ");
       	                    sprintf(buf,"\n\r\n\r\033[33m         File \033[31m%s\033[33m Found in : \033[36m%s\033[0m\n\r", filename,Conf.name);
			    PS(buf);
                            sprintf(buf,"\n\r\033[33m  The Path of the actual Conference : \033[36m%s\033[0m\n\r", Conf.path);
			    PS(buf);
                            sprintf(buf,"\033[33m       Fileareas in This Conference : \033[36m%u\033[0m\n\r\n\r", Conf.fileareas);
                            PS(buf);
                            PS("\033[34m>----[\33[36m bY [r]FoX\033[34m ]-----------------------------[\033[36m & zEd^dC\033[34m ]--->>-->\n\r");                       
		            Close(fh);
                            XIMFunction(7,(long)fname,0);
                            Delay(50);
                            return;
                            }
			    else
                            PS("\033[31m .. not here in this FileBase :(");
		       } else
                       break;
                }
                PS("\n\r\n\r\033[34m>----[\33[36m bY [r]FoX\033[34m ]-----------------------------[\033[36m & zEd^dC\033[34m ]--->>-->\n\r");                       
		Close(fh);
        }
        PS("\n\r\n\r");
}
