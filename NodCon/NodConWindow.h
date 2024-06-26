/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : [r]FoX
 */

#define GetString( g )      ((( struct StringInfo * )g->SpecialInfo )->Buffer  )
#define GetNumber( g )      ((( struct StringInfo * )g->SpecialInfo )->LongInt )

#define GD_Node_gad1                           0
#define GD_Node_gad2                           1
#define GD_Node_gad3                           2
#define GD_Node_gad4                           3
#define GD_Node_gad5                           4
#define GD_Node_gad6                           5
#define GD_Node_gad7                           6
#define GD_Node_gad8                           7
#define GD_Node_gad9                           8
#define GD_SXClose                             9
#define GD_SXOpen                              10
#define GD_ShutNode                            11
#define GD_LaunchNode                          12
#define GD_OpenChat                            13
#define GD_KickUser                            14

#define GDX_Node_gad1                          0
#define GDX_Node_gad2                          1
#define GDX_Node_gad3                          2
#define GDX_Node_gad4                          3
#define GDX_Node_gad5                          4
#define GDX_Node_gad6                          5
#define GDX_Node_gad7                          6
#define GDX_Node_gad8                          7
#define GDX_Node_gad9                          8
#define GDX_SXClose                            9
#define GDX_SXOpen                             10
#define GDX_ShutNode                           11
#define GDX_LaunchNode                         12
#define GDX_OpenChat                           13
#define GDX_KickUser                           14

#define NodCon_GUI_CNT 15

extern struct IntuitionBase *IntuitionBase;
extern struct Library       *GadToolsBase;

extern struct Screen        *Scr;
extern UBYTE                 *PubScreenName;
extern APTR                  VisualInfo;
extern struct Window        *NodCon_GUIWnd;
extern struct Gadget        *NodCon_GUIGList;
extern struct IntuiMessage   NodCon_GUIMsg;
extern struct Gadget        *NodCon_GUIGadgets[15];
extern UWORD                 NodCon_GUILeft;
extern UWORD                 NodCon_GUITop;
extern UWORD                 NodCon_GUIWidth;
extern UWORD                 NodCon_GUIHeight;
extern UBYTE                *NodCon_GUIWdt;
extern struct TextAttr       topaz8;
extern UWORD                 NodCon_GUIGTypes[];
extern struct NewGadget      NodCon_GUINGad[];
extern ULONG                 NodCon_GUIGTags[];

extern int Node_gad1Clicked( void );
extern int Node_gad2Clicked( void );
extern int Node_gad3Clicked( void );
extern int Node_gad4Clicked( void );
extern int Node_gad5Clicked( void );
extern int Node_gad6Clicked( void );
extern int Node_gad7Clicked( void );
extern int Node_gad8Clicked( void );
extern int Node_gad9Clicked( void );
extern int SXCloseClicked( void );
extern int SXOpenClicked( void );
extern int ShutNodeClicked( void );
extern int LaunchNodeClicked( void );
extern int OpenChatClicked( void );
extern int KickUserClicked( void );

extern int SetupScreen( void );
extern void CloseDownScreen( void );
extern int HandleNodCon_GUIIDCMP( void );
extern int NodCon_GUICloseWindow();
extern int OpenNodCon_GUIWindow( void );
extern void CloseNodCon_GUIWindow( void );
