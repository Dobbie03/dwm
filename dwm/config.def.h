/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx         = 2;   /* border pixel of windows */
static const unsigned int snap             = 32;  /* snap pixel */
static const unsigned int gappih           = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv           = 10;  /* vert inner gap between windows */
static const unsigned int gappoh           = 10;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 10;   /* vert outer gap between windows and screen edge */
static const int smartgaps                 = 1;   /* 1 means no outer gap when there is only one window */
static const int showbar                   = 1;   /* 0 means no bar */
static const int topbar                    = 1;   /* 0 means bottom bar */
static const double activeopacity   	   = 1.0f;     /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity 	   = 1.0f;   /* Window opacity when it's inactive (0 <= opacity <= 1) */
static       Bool bUseOpacity       	   = False;     /* Starts with opacity on any unfocused windows */
static const int horizpadbar               = 5;   /* horizontal padding for statusbar */
static const int vertpadbar                = 20;   /* vertical padding for statusbar */
static const int focusonnetactive          = 1;   /* 0 means default behaviour, 1 means auto-focus on urgent window */
static const int attachmode                = 2;   /* 0 = master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const int pertag                    = 0;   /* 0 means global layout across all tags (default), 1 = layout per tag (pertag) */
static const int pertagbar                 = 0;   /* 0 means using pertag, but with the same barpos, 1 = normal pertag */
static const int zoomswap                  = 1;   /* 0 means default behaviour, 1 = zoomswap patch */
static const int fancybar                  = 1;   /* 0 means default behaviour, 1 = fancybar patch */
static const int savefloats                = 1;   /* 0 means default behaviour, 1 = savefloats patch */
static const int losefullscreen            = 1;   /* 0 means default behaviour, 1 = losefullscreen patch */
static const int nrg_force_vsplit          = 1;   /* nrowgrid layout, 1 means force 2 clients to always split vertically */
static const unsigned int systraypinning   = 2;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing   = 8;   /* systray spacing */
static const int systraypinningfailfirst   = 0;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray               = 1;   /* 0 means no systray */
static const unsigned int systrayiconsize  = 18; /* systray icon size in px */
static const char *fonts[]          	   = { "Fira Sans:size=10", "Font Awesome 5 Pro:style=Solid:pixelsize=16:antialias=true", "Font Awesome 5 Brands:style=Solid:pixelsize=16:antialias=true", "Material Design Icons:Regular:pixelsize=19:antialias=true" };
static const char dmenufont[]       	   = "noto:size=14";
static const char col_gray1[]              = "#141414";
static const char col_gray2[]              = "#505050";
static const char col_gray3[]              = "#353535";
static const char col_gray4[]              = "#b5b5b5";
static const char col_gray5[]              = "#fffefe";
static const char col_gray6[]              = "#292929";
static const char col_gray7[]              = "#282828";
static const char col_gray8[]              = "#202020";
static const char col_cyan[]               = "#808fa0";
static const char col_blue[]			   = "#6699cc";
static const char col1[]                   = "#98971a";
static const char col2[]                   = "#d79921";
static const char col3[]                   = "#458588";
static const char col4[]                   = "#b16286";
static const char col5[]                   = "#689d6a";
static const char col6[]                   = "#a89984";
/*static const unsigned int baralpha       = 0xd0;*/
/*static const unsigned int baralpha       = 225;*/
/*static const unsigned int baralpha       = 235;*/
static const unsigned int baralpha         = 255;
static const unsigned int borderalpha      = 255;

static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray4, col_gray8, col_gray8 },
	[SchemeSel]  = { col_cyan, col_gray8,  col_gray2  },
};


static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* staticstatus */
static const int statmonval = 0;

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };
/*static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };*/
/*static const char *tags[] = { "•", "•", "•", "•", "•", "•", "•", "•", "•", "•" };*/
/*static const char *tags[] = { "[web]", "[term]", "[torr]", "[mpd]", "[file]", "[vid]", "[edit]", "[chat]", "[tag]", "[steam]" };*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  WM_WINDOW_ROLE(STRING) = role
	 */
	/* class            			role       instance     title   tags mask  switchtotag  iscentered   isfloating   monitor */
  { "qutebrowser",    				NULL,      NULL,        NULL,       1,	    1,         	0,           0,            0 },
  { "firefox",        				NULL,      NULL,        NULL,       1,	    1,         	0,           0,            0 },
  { "Surf",           				NULL,      NULL,        NULL,       1,	    1,         	0,           0,            0 },
  { "ncmpcpp",   					NULL,	   NULL,        NULL,       1 << 3, 1,         	1,			 0,	           0 },
  { "URxvt",          				NULL,      NULL,        NULL,       1 << 1, 1,         	0,           0,            0 },
  { "Transmission-gtk",				NULL,      NULL,        NULL,       1 << 2, 1,         	0,           0,            0 },
  { "SoulseekQt",					NULL,      NULL,        NULL,       1 << 2, 1,         	0,           0,            0 },
  { "Nicotine",						NULL,      NULL,        NULL,       1 << 2, 1,         	0,           0,            0 },
  { "Thunar",		    			NULL,      NULL,        NULL,       1 << 4, 1,         	0,           0,            0 },
  { "Gpicview",		    			NULL,      NULL,        NULL,       1 << 4, 1,         	0,           0,            0 },
  { "Sxiv",		    				NULL,      NULL,        NULL,       1 << 4, 1,         	1,           1,            0 },
  { "File-roller",    				NULL,      NULL,        NULL,       1 << 4, 1,         	1,           1,            0 },
  { "mpv",          				NULL,      NULL,        NULL,       1,      1,         	1,           1,            0 },
  { "Subl",		    				NULL,      NULL,        NULL,       1 << 6, 1,         	0,           0,            0 },
  { "Emacs",	    				NULL,      NULL,        NULL,       1 << 6, 1,         	0,           0,            0 },
  { "Code",		    				NULL,      NULL,        NULL,       1 << 6, 1,         	0,           0,            0 },
  { "steam",          				NULL,      NULL,        NULL,       1 << 7, 1,         	0,           0,            0 },
  { "Slack",          				NULL,      NULL,        NULL,       1 << 7, 1,         	0,           0,            0 },
  { "Easytag",	    				NULL,      NULL,        NULL,       1 << 8, 1,         	1,           0,            0 },
  { "Xfce4-taskmanager",			NULL,      NULL,        NULL,       1 << 9, 1,         	1,           0,            0 },
  { "Nitrogen",						NULL,      NULL,        NULL,       1 << 9, 1,         	1,           1,            0 },
  { "Xfce4-appearance-settings",	NULL,      NULL, 	    NULL,       1 << 9, 1,         	1,    		 1,            0 },
  { "Xfce4-mouse-settings", 		NULL, 	   NULL, 	    NULL,       1 << 9, 1,         	1,    		 1,            0 },
  { "Gpick", 						NULL, 	   NULL, 	    NULL,       0,    	1,         	1,    		 1,            0 },
  { "MuPDF", 						NULL, 	   NULL, 	    NULL,       0,    	1,         	1,    		 1,            0 },
  { "Lxappearance",   				NULL, 	   NULL, 	    NULL,       1 << 9, 1,         	1,    		 1,            0 },
  { "Blueman-manager", 				NULL, 	   NULL, 	    NULL,       1 << 9, 1,         	1,    		 1,            0 },
  { "Pavucontrol",              	NULL,      NULL,        NULL,	    1 << 9, 1,          1,   		 1,            0 },
  { "Piper", 						NULL, 	   NULL, 	    NULL,       1 << 9, 1,         	1,    		 1,            0 },
  { "Gucharmap", 					NULL, 	   NULL, 	    NULL,       1 << 6, 1,         	1,    		 1,            0 },
  { "Gimp", 						NULL, 	   NULL, 	    NULL,       1 << 9, 1,         	1,    		 0,            0 },
  { "Alacritty",           			NULL,      NULL,        NULL,       1 << 1, 1,         	0,           0,            0 },
  { "kitty",            			NULL,      NULL,        NULL,       1 << 1, 1,         	0,           0,            0 },
  { "st",	            		 	NULL,      NULL,        NULL,       1 << 1,	1,     	 	1,           0,            0 },
  { "St",	            		 	NULL,      NULL,        NULL,       1 << 1,	1,     	 	1,           0,            0 },
  { "nvim",                     	NULL,      NULL,        NULL,       1 << 6, 1,          0,           0,            0 },
  { "firefox",	   "GtkFileChooserDialog",    "Save File",  NULL,		0,	 	0,          1,           1,		       0 },
  { "firefox",                   	NULL, "Toolkit", "Picture-in-Picture", 0,   1,          0,           1,		       0 },
  { "firefox",                   	NULL, 	NULL, "About Mozilla Firefox", 0,   1,          0,           1,		       0 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "vanitygaps.c"

static const int layoutaxis[] = {
	SPLIT_VERTICAL,   /* layout axis: 1 = x, 2 = y; negative values mirror the layout, setting the master area to the right / bottom instead of left / top */
	TOP_TO_BOTTOM,    /* master axis: 1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
	TOP_TO_BOTTOM,    /* stack axis:  1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
};

static const Layout layouts[] = {
	{ "󰕴", dwindle },
	{ "󰕰", tile },
	{ "󰡃", grid },
	{ "󰕫", centeredmaster },
	{ "󰕬", centeredfloatingmaster },
	{ "󰕯", NULL },
	{ "󰾍", bstack },
	{ "󱇚", bstackhoriz },
	{ "󱒈", gaplessgrid },
	{ "󰕭", horizgrid },
	{ "󱒇", nrowgrid },
	{ "󰡃", spiral },
	{ "󰃚", monocle },
	{ "󱒉", deck },
	{ NULL,	NULL },
};

/* key definitions */
/*#define MODKEY Mod1Mask*/
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


#define APP_BROWSER     "firefox"
#define APP_BROWSER_    "firefox --private-window"
#define APP_QUTE        "qutebrowser --qt-arg stylesheet ~/.local/share/qutebrowser/fix-tooltips.qss"
#define APP_SURF        "surf"
#define APP_FILE        "thunar"
#define APP_EDITOR      "easytag"
#define APP_MAGNET      "transmission-gtk"
#define APP_EDIT        "subl"
#define APP_CODE        "subl"
#define APP_NVIM        "st -c nvim -e nvim"
#define APP_NANO        "alacritty --class nano,nano -e nano"
#define APP_NEOVIM      "alacritty --class nvim,nvim -e nvim"
#define APP_MUSICA      "alacritty --class ncmpcpp,ncmpcpp -e ncmpcpp"
#define APP_MUSICVIS    "alacritty --class ncmpcpp,ncmpcpp -e ncmpcpp -S visualizer"
#define APP_MUSIC_      "st -g 200x80 -c ncmpcpp -e ncmpcpp"
#define APP_MUSIC       "st -c ncmpcpp -e ncmpcpp"    
#define APP_DUNSTHIST   "dunstctl history-pop"
#define APP_DUNSTCLOSE  "dunstctl close"
#define APP_CLIP        "greenclip print | sed '/^$/d' | dmenu -l 10 -p clipboard | xargs -r -d'\n' -I '{}' greenclip print '{}'"
/*#define APP_CLIP        "/usr/bin/clipit.sh"*/
/*#define APP_EXIT        "/usr/bin/logout.sh"*/
#define APP_EXIT        "/usr/bin/dmenu_logout"
#define APP_DMENU       "/usr/bin/dmenubot.sh"
#define APP_VOLU        "/home/dobbie/.bin/volume up"
#define APP_VOLD        "/home/dobbie/.bin/volume down"
#define APP_MUTE        "amixer -q set Master toggle"
#define APP_MPDTOG      "mpc toggle"
#define APP_MPDSTOP     "mpc stop"
#define APP_MPDNEXT     "mpc next"
#define APP_MPDPREV     "mpc prev"
#define APP_MPDREW      "mpc seek -10"
#define APP_MPDFAST     "mpc seek +10"
#define APP_SCROT       "/usr/bin/scr"
#define APP_SCROT_      "teiler"
#define APP_LOCK        "slock"
#define APP_LIGHT       "/usr/bin/switch light"
#define APP_DARK        "/usr/bin/switch dark"

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = {"dmenu_run_history", NULL};
static const char *termcmd[]       = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
/*static const char *scratchpadcmd[] = { "alacritty", "-t", scratchpadname, "-o", "window.dimensions.columns=130", "-o", "window.dimensions.lines=30", NULL };*/

#include "mpdcontrol.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function             argument */
	{ MODKEY,                       XK_space,  spawn,               {.v = dmenucmd } },
	{ MODKEY,			            XK_t, 	   spawn,               {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  	    {.v = scratchpadcmd } },
	{ MODKEY,                     	XK_s,	   togglescratch,  	    {.v = scratchpadcmd } },
	{ MODKEY,			            XK_b,      togglebar,           {0} },
	{ MODKEY,                       XK_j,      focusstack,          {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,          {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_j,      rotatestack,         {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_k,      rotatestack,         {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,          {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,          {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,            {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,      setmfact,            {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,            {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,            {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,            {.f =  0.00} },
	{ MODKEY|Mod4Mask,              XK_m,      zoom,                {0} },
	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,            {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,            {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,          {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,          {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,          {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,          {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,          {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,          {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,          {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,          {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,          {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,         {0} },
	{ MODKEY,			            XK_Tab,    focusstack,          {.i = +1 } },
	{ Mod1Mask|ControlMask,         XK_Tab,    view,                {0} },
	{ MODKEY,                       XK_q,      killclient,          {0} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_1,      setlayout,           {.v = &layouts[0]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_2,      setlayout,           {.v = &layouts[1]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_3,      setlayout,           {.v = &layouts[2]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_4,      setlayout,           {.v = &layouts[3]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_5,      setlayout,           {.v = &layouts[4]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_6,      setlayout,           {.v = &layouts[5]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_7,      setlayout,           {.v = &layouts[6]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_8,      setlayout,           {.v = &layouts[7]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_9,      setlayout,           {.v = &layouts[8]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_0,      setlayout,           {.v = &layouts[9]} },
	{ MODKEY|Mod4Mask|ControlMask,  XK_w,      setflexlayout,       {.i = 293 } }, // centered master
	{ MODKEY|ControlMask,           XK_e,      setflexlayout,       {.i = 273 } }, // bstackhoriz layout
	{ MODKEY|ShiftMask,             XK_r,      setflexlayout,       {.i = 272 } }, // bstack layout
	{ MODKEY|ShiftMask|ControlMask, XK_t,      setflexlayout,       {.i = 261 } }, // default tile layout
	{ MODKEY|ShiftMask,             XK_g,      setflexlayout,       {.i = 263 } }, // tile + grid layout
	{ MODKEY|ShiftMask|ControlMask, XK_w,      setflexlayout,       {.i =   7 } }, // grid
	{ MODKEY|Mod4Mask|ControlMask,  XK_e,      setflexlayout,       {.i = 262 } }, // deck layout
	{ MODKEY|ControlMask,           XK_r,      setflexlayout,       {.i =   6 } }, // monocle
	{ MODKEY|ControlMask,           XK_g,      setflexlayout,       {.i = 257 } }, // columns (col) layout
	{ MODKEY|ControlMask,           XK_space,  setlayout,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscreen,    {0} },
	{ MODKEY,                       XK_n,      view,                {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,                 {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,            {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,            {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,         {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_comma,  tagmon,              {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_period, tagmon,              {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_comma,  tagallmon,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_period, tagallmon,           {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_comma,  tagswapmon,          {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_period, tagswapmon,          {.i = -1 } },
	TAGKEYS(                        XK_1,                           0)
	TAGKEYS(                        XK_2,                           1)
	TAGKEYS(                        XK_3,                           2)
	TAGKEYS(                        XK_4,                           3)
	TAGKEYS(                        XK_5,                           4)
	TAGKEYS(                        XK_6,                           5)
	TAGKEYS(                        XK_7,                           6)
	TAGKEYS(                        XK_8,                           7)
	TAGKEYS(                        XK_9,                           8)
	TAGKEYS(                        XK_0,                           9)
	{ MODKEY|ShiftMask,             XK_q,       quit,               {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,       quit,               {1} },
	{ MODKEY|ControlMask,           XK_t,       rotatelayoutaxis,   {.i = 0} },    /* flextile, 0 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,     rotatelayoutaxis,   {.i = 1} },    /* flextile, 1 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,     rotatelayoutaxis,   {.i = 2} },    /* flextile, 2 = stack axis */
	{ MODKEY|ControlMask,           XK_Return,  mirrorlayout,       {0} },         /* flextile, flip master and stack areas */
	{ MODKEY,                       XK_m,      spawn,               SHCMD(APP_MUSIC) },
	{ MODKEY|ShiftMask,             XK_m,      spawn,               SHCMD(APP_MUSICA) },
  	{ ControlMask,                  XK_grave,  spawn,               SHCMD(APP_DUNSTHIST) },
  	{ ControlMask,                  XK_space,  spawn,               SHCMD(APP_DUNSTCLOSE) },
	{ MODKEY,						XK_l,       spawn,		    	SHCMD(APP_LOCK) },
	{ 0,							XK_Print,   spawn,		    	SHCMD(APP_SCROT) },
	{ ShiftMask,					XK_Print,   spawn,		    	SHCMD(APP_SCROT_) },
	{ MODKEY,                       XK_minus,   spawn,              SHCMD(APP_VOLD) },
	{ MODKEY,                       XK_equal,   spawn,              SHCMD(APP_VOLU) },
	{ MODKEY|ShiftMask,             XK_minus,   spawn,              SHCMD(APP_MUTE) },
	/*{ 0, XF86XK_AudioMute,                      spawn,              SHCMD(APP_MUTE) },
	{ 0, XF86XK_AudioRaiseVolume,               spawn,              SHCMD(APP_VOLUP) },
	{ 0, XF86XK_AudioLowerVolume,               spawn,              SHCMD(APP_VOLDP) },*/
	/*{ 0, XF86XK_AudioPrev,                    spawn,              SHCMD(APP_MPDPREV) },
	{ 0, XF86XK_AudioNext,                      spawn,              SHCMD(APP_MPDNEXT) },*/
	{ 0, XF86XK_AudioPause,                     spawn,              SHCMD(APP_MPDTOG) },
	{ 0, XF86XK_AudioPlay,                      spawn,              SHCMD(APP_MPDTOG) },
	/*{ 0, XF86XK_AudioStop,                      spawn,              SHCMD(APP_MPDSTOP) },
	{ 0, XF86XK_AudioRewind,                    spawn,              SHCMD(APP_MPDREW) },
	{ 0, XF86XK_AudioForward,                   spawn,              SHCMD(APP_MPDFAST) },*/
	{ MODKEY,                       XK_w,       spawn,              SHCMD(APP_BROWSER)  },
  	{ MODKEY|ShiftMask,             XK_w,       spawn,              SHCMD(APP_QUTE) },
	{ MODKEY,						XK_x,		spawn,				SHCMD(APP_EXIT) },
	{ MODKEY|ShiftMask,             XK_p,	    spawn,              SHCMD(APP_CLIP)},
	{ MODKEY,						XK_f,	    spawn,				SHCMD(APP_FILE) },
	{ MODKEY,                       XK_e,       spawn,              SHCMD(APP_EDIT)  },
	{ MODKEY|ShiftMask,             XK_e,       spawn,              SHCMD(APP_EDITOR)  },
	{ MODKEY|ShiftMask,             XK_t,       spawn,              SHCMD(APP_MAGNET)  },
	{ MODKEY,                       XK_F1,     mpdchange,           {.i = -1} }, // PREVIOUS SONG
	{ MODKEY|ShiftMask,             XK_F1,     mpdchange,           {.i = +1} }, // NEXT SONG
	{ MODKEY,                       XK_Escape, mpdcontrol,          {0} },		 // TOGGLE PLAY/PAUSE
  	{ MODKEY,                       XK_a,      					    toggleopacity,  {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask         button          function        argument */
	{ ClkLtSymbol,          0,                 Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                 Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,                 Button4,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,                 Button5,        cyclelayout,    {.i = -1 } },
	{ ClkWinTitle,          0,                 Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                 Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,            Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,            Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,            Button4,        rotatestack,    {.i = +1 } },
	{ ClkClientWin,         MODKEY,            Button5,        rotatestack,    {.i = -1 } },
	{ ClkClientWin,         MODKEY,            Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button4,        cyclelayout,    {.i = -1 } },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button5,        cyclelayout,    {.i = +1 } },
	{ ClkTagBar,            0,                 Button1,        view,           {0} },
	{ ClkTagBar,            0,                 Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,            Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,            Button3,        toggletag,      {0} },
};
