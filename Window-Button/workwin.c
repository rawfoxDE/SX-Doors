/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : [r]FoX
 */

#include <exec/types.h>

#include <intuition/intuition.h>
#include <intuition/classes.h>
#include <intuition/classusr.h>
#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>

#include <libraries/gadtools.h>

#include <graphics/displayinfo.h>
#include <graphics/gfxbase.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/graphics_protos.h>
#include <clib/utility_protos.h>

#include <string.h>
#include <dos.h>

#include <pragmas/exec_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/gadtools_pragmas.h>
#include <pragmas/graphics_pragmas.h>
#include <pragmas/utility_pragmas.h>

#include "workwin.h"

struct Screen         *Scr = NULL;
UBYTE                 *PubScreenName = NULL;
APTR                   VisualInfo = NULL;
struct Window         *Project0Wnd = NULL;
struct Gadget         *Project0GList = NULL;
struct IntuiMessage    Project0Msg;
struct Gadget         *Project0Gadgets[1];
UWORD                  Project0Left = 10;
UWORD                  Project0Top = 15;
UWORD                  Project0Width = 400;
UWORD                  Project0Height = 75;
UBYTE                 *Project0Wdt = (UBYTE *)"Work Window";

struct TextAttr topaz8 = {
	( STRPTR )"topaz.font", 8, 0x00, 0x01 };

UWORD Project0GTypes[] = {
	BUTTON_KIND
};

struct NewGadget Project0NGad[] = {
	15, 10, 103, 17, (UBYTE *)"Testbutton", NULL, GD_TEST_BUT, PLACETEXT_RIGHT, NULL, NULL
};

ULONG Project0GTags[] = { 
-(TAG_DONE) };

int SetupScreen( void )
{
	if ( ! ( Scr = LockPubScreen( PubScreenName )))
		return( 1L );

	if ( ! ( VisualInfo = GetVisualInfo( Scr, TAG_DONE )))
		return( 2L );

	return( 0L );
}

void CloseDownScreen( void )
{
	
   if(VisualInfo) 
   {
		FreeVisualInfo( VisualInfo );
		VisualInfo = NULL;
	}
  
	if(Scr) 
   {
		UnlockPubScreen( NULL, Scr );
		Scr = NULL;
	}

}


int OpenProject0Window( void )
{
	struct NewGadget	ng;
	struct Gadget	*g;
	UWORD		lc, tc;
	UWORD		offx = Scr->WBorLeft, offy = Scr->WBorTop + 1; // + Scr->RastPort.TxHeight + 1;

	if(!(g=CreateContext(&Project0GList))) return( 1L );

	for( lc = 0, tc = 0; lc < Project0_CNT; lc++ ) 
   {
		CopyMem((char * )&Project0NGad[ lc ], (char * )&ng, (long)sizeof( struct NewGadget ));

		ng.ng_VisualInfo = VisualInfo;
		ng.ng_TextAttr   = &topaz8;
		ng.ng_LeftEdge  += offx;
		ng.ng_TopEdge   += offy;

		Project0Gadgets[ lc ] = g = CreateGadgetA((ULONG)Project0GTypes[ lc ], g, &ng, ( struct TagItem * )&Project0GTags[ tc ] );

		while( Project0GTags[ tc ] ) tc += 2;
		tc++;

		if ( NOT g )
			return( 2L );
	}

	if ( ! ( Project0Wnd = OpenWindowTags( NULL,
				WA_Left,	Project0Left,
				WA_Top,		Project0Top,
				WA_Width,	Project0Width,
				WA_Height,	Project0Height + offy,
				WA_IDCMP,	BUTTONIDCMP,
				WA_Flags,	WFLG_SMART_REFRESH|WFLG_BORDERLESS,
				WA_Gadgets,	Project0GList,
				WA_Title,	Project0Wdt,
				WA_ScreenTitle,	"GadToolsBox V2.0b � 1991-1993",
				WA_PubScreen,	Scr,
				WA_MinWidth,	67,
				WA_MinHeight,	21,
				WA_MaxWidth,	1336,
				WA_MaxHeight,	554,
				TAG_DONE )))
	return( 4L );

	GT_RefreshWindow( Project0Wnd, NULL );

	return( 0L );
}

void CloseProject0Window( void )
{	
   if(Project0Wnd)
   {
		CloseWindow( Project0Wnd );
		Project0Wnd = NULL;
	}

	if(Project0GList)
   {
		FreeGadgets( Project0GList );
		Project0GList = NULL;
	}

   
}
