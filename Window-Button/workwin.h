/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : [r]FoX
 */

#define GetString( g )      ((( struct StringInfo * )g->SpecialInfo )->Buffer  )
#define GetNumber( g )      ((( struct StringInfo * )g->SpecialInfo )->LongInt )

#define GD_TEST_BUT                            0

#define GDX_TEST_BUT                           0

#define Project0_CNT 1

extern struct IntuitionBase *IntuitionBase;
extern struct Library       *GadToolsBase;

extern struct Screen        *Scr;
extern UBYTE                 *PubScreenName;
extern APTR                  VisualInfo;
extern struct Window        *Project0Wnd;
extern struct Gadget        *Project0GList;
extern struct IntuiMessage   Project0Msg;
extern struct Gadget        *Project0Gadgets[1];
extern UWORD                 Project0Left;
extern UWORD                 Project0Top;
extern UWORD                 Project0Width;
extern UWORD                 Project0Height;
extern UBYTE                *Project0Wdt;
extern struct TextAttr       topaz8;
extern UWORD                 Project0GTypes[];
extern struct NewGadget      Project0NGad[];
extern ULONG                 Project0GTags[];

extern int TEST_BUTClicked( void );

extern int SetupScreen( void );
extern void CloseDownScreen( void );
extern void HandleProject0IDCMP( void );
extern int Project0CloseWindow();
extern int OpenProject0Window( void );
extern void CloseProject0Window( void );
