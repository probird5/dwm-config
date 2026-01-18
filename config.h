/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows (hyprland border_size) */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 5;        /* horiz inner gap between windows (hyprland gaps_in) */
static const unsigned int gappiv    = 5;        /* vert inner gap between windows (hyprland gaps_in) */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge (hyprland gaps_out) */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge (hyprland gaps_out) */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
    "monospace:size=10",
    "Noto Color Emoji:size=15" // Adjust the size as needed
};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Thunar",   NULL,       NULL,       0,            1,           -1 },  /* float like in hyprland */
	{ "thunar",   NULL,       NULL,       0,            1,           -1 },  /* lowercase variant */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
  { "===",      bstackhoriz }, /* horizontal bottom stack layout */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* launcher - rofi like in hyprland */
static const char *dmenucmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };
/* terminal - ghostty like in hyprland */
static const char *termcmd[]  = { "ghostty", NULL };
/* file manager - thunar like in hyprland */
static const char *thunarcmd[] = { "thunar", NULL };
/* screenshot */
static const char *flameshotcmd[] = { "flameshot", "gui", NULL };

/* media controls - using pamixer like in hyprland */
static const char *upvol[]   = { "pamixer", "-i", "5", NULL };
static const char *downvol[] = { "pamixer", "-d", "5", NULL };
static const char *mutevol[] = { "pamixer", "-t", NULL };
static const char *mutemic[] = { "pamixer", "--default-source", "-m", NULL };
/* brightness */
static const char *brup[]    = { "brightnessctl", "s", "+5%", NULL };
static const char *brdown[]  = { "brightnessctl", "s", "5%-", NULL };
/* media player controls - playerctl like in hyprland */
static const char *playpause[] = { "playerctl", "play-pause", NULL };
static const char *medianext[] = { "playerctl", "next", NULL };
static const char *mediaprev[] = { "playerctl", "previous", NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* Hyprland-style keybindings */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },      /* SUPER+Return = terminal (ghostty) */
	{ MODKEY,                       XK_q,      killclient,     {0} },                  /* SUPER+Q = kill window */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },                  /* SUPER+Shift+Q = quit dwm */
	{ MODKEY,                       XK_e,      spawn,          {.v = thunarcmd } },    /* SUPER+E = file manager (thunar) */
	{ MODKEY,                       XK_v,      togglefloating, {0} },                  /* SUPER+V = toggle floating */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },     /* SUPER+P = launcher (rofi) */
	{ MODKEY,                       XK_d,      togglefullscr,  {0} },                  /* SUPER+D = fullscreen */
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },   /* SUPER+M = monocle (maximize) */

	/* Focus navigation - SUPER+J/K */
	STACKKEYS(MODKEY,                          focus)
	/* Move windows in stack - SUPER+Shift+J/K */
	STACKKEYS(MODKEY|ShiftMask,                push)

	/* Resize master area - SUPER+H/L */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	/* Additional dwm features */
	{ MODKEY,                       XK_b,      togglebar,      {0} },                  /* SUPER+B = toggle bar */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },           /* SUPER+I = add to master */
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },           /* SUPER+Shift+D = remove from master */
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },                  /* SUPER+Shift+Return = swap with master */
	{ MODKEY,                       XK_Tab,    view,           {0} },                  /* SUPER+Tab = previous tag */

	/* Layout switching */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },   /* SUPER+T = tiled */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },   /* SUPER+F = floating */
	{ MODKEY|ShiftMask,             XK_b,      setlayout,      {.v = &layouts[3]} },   /* SUPER+Shift+B = bottom stack */
	{ MODKEY,                       XK_space,  setlayout,      {0} },                  /* SUPER+Space = toggle layout */
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },                  /* SUPER+Shift+F = fullscreen */

	/* Gaps control */
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	/* View all tags / tag all */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	/* Multi-monitor - SUPER+comma/period */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* Tag keys - SUPER+1-9 */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* Media keys - using pamixer/playerctl like in hyprland */
	{ 0, XF86XK_AudioRaiseVolume,  spawn,  {.v = upvol } },
	{ 0, XF86XK_AudioLowerVolume,  spawn,  {.v = downvol } },
	{ 0, XF86XK_AudioMute,         spawn,  {.v = mutevol } },
	{ 0, XF86XK_AudioMicMute,      spawn,  {.v = mutemic } },
	{ 0, XF86XK_AudioPlay,         spawn,  {.v = playpause } },
	{ 0, XF86XK_AudioPause,        spawn,  {.v = playpause } },
	{ 0, XF86XK_AudioNext,         spawn,  {.v = medianext } },
	{ 0, XF86XK_AudioPrev,         spawn,  {.v = mediaprev } },

	/* Brightness keys */
	{ 0, XF86XK_MonBrightnessUp,   spawn,  {.v = brup } },
	{ 0, XF86XK_MonBrightnessDown, spawn,  {.v = brdown } },

	/* Screenshot */
	{ 0, XK_Print, spawn, {.v = flameshotcmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};



