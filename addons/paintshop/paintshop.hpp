// Control types
#define CT_MAP_MAIN 101
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_XSLIDER 43
#define CT_SLIDER 3

// Static styles
#define ST_PICTURE 0x30
#define ST_MULTI 16
// Listbox styles
#define ST_LEFT 0x00
#define LB_TEXTURES 0x10
// Slider styles
#define SL_DIR 0x400
#define SL_VERT 0
#define SL_HORZ 1024
#define SL_TEXTURES 0x10


// Base Classes

class HP_IGUIBack
{
	type = 0;
	idc = -1;
	style = 80;
	text = "";
	colorText[] = {.1,.1,.1,.6};
	font = "PuristaMedium";
	sizeEx = 0;
	shadow = 0;
	x = 0.1;
	y = 0.1;
	w = 0.1;
	h = 0.1;
	colorbackground[] = {.1,.1,.1,.6};
};

class HP_RscFrame
{
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0,.5,1,.8};
	colorText[] = {0,.5,1,.8};
	font = "PuristaLight";
	sizeEx = 0.02;
	text = "";
};

class HP_RscButton
{
	access = 0;
	type = 1;
	text = "";
	colorText[] = {1,1,1,0.8};
	colorDisabled[] = {0.4,0.4,0.4,1};
	colorBackground[] = {.7,.7,.7,.6};
	colorBackgroundDisabled[] = {.95,.95,.95,1};
	colorBackgroundActive[] = {.3,.3,.3,.6};
	colorFocused[] = {.7,.7,.7,.8};
	colorShadow[] = {.1,.1,.1,1};
	colorBorder[] = {.7,.7,.7,.5};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 1;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};

class HP_RscListBox
{
	access = 0;
	type = 5;
	w = 0.4;
	h = 0.4;
	rowHeight = 0;
	colorText[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	colorScrollbar[] = {1, 0, 0, 0};
	colorSelect[] = {0, 0, 0, 1};
	colorSelect2[] = {0, 0, 0, 1};
	colorSelectBackground[] = {0.95, 0.95, 0.95, 1};
	colorSelectBackground2[] = {1, 1, 1, 0.5};
	colorBackground[] = {.2,.2,.2,.6};
	pictureColor[] = {1,1,1,1}; // Picture color
	pictureColorSelect[] = {1,1,1,1}; // Selected picture color
	pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect", 0.09, 1};
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	class ListScrollBar
	{
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		shadow = 0;
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	style = 16;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	colorShadow[] = {0, 0, 0, 0.5};
	color[] = {1, 1, 1, 1};
	period = 1.2;
	maxHistoryDelay = 1;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
};

class HP_RscCheckbox
{
	idc = -1;
	type = 7;
	style = 2;
	x = "LINE_X(XVAL)";
	y = "LINE_Y";
	w = "LINE_W(WVAL)";
	h = 0.029412;
	colorText[] = {0,.5,1,1};
	color[] = {.7,.7,.7,.5};
	colorBackground[] = {.7,.7,.7,.2};
	colorTextSelect[] = {0, 0.8, 0,.8};
	colorSelectedBg[] = {.1,.1,.1,.2};
	colorSelect[] = {.7,.7,.7,.2};
	colorTextDisable[] = {0.4, 0.4, 0.4, 1};
	colorDisable[] = {0.4, 0.4, 0.4, 1};
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	rows = 1;
	columns = 1;
};

class HP_RscStructuredText
{
	access = 0;
	type = CT_STRUCTURED_TEXT;
	idc = -1;
	style = ST_LEFT;
	colorText[] = {1,1,1,1};
	colorBackground[] = {.1,.1,.1,.6};
	class Attributes
	{
		font = "PuristaMedium";
		color = "#ffffff";
		align = "center";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 1;
};

class HP_slider {
	idc = -1; 
	type = CT_XSLIDER; 
	style = SL_HORZ; 
	x = 0.4; 
	y = 0.2; 
	w = 0.3; 
	h = 0.025; 
	color[] = { 1, 1, 1, 1 }; 
	coloractive[] = { 1, 1, 1,.5 };
	colorDisabled[] = {.5,.5,.5,.2};
	colorBackground[] = {.1,.1,.1,.6};
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
	onSliderPosChanged = "_this call HALV_paintshop_slidingcolor;false";
};

class HALV_painshop_dialog
{
	idd=6666;
	moveingenabled=false;
	class controls
	{
		class HALV_paintshop_textextframe: HP_RscFrame
		{
			idc = 6672;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.246975 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_textureframe: HP_RscFrame
		{
			idc = 6670;
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.224972 * safezoneH + safezoneY;
			w = 0.165086 * safezoneW;
			h = 0.550055 * safezoneH;
		};
		class HALV_paintshop_texlistframe: HP_RscFrame
		{
			idc = 6671;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.290979 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.462046 * safezoneH;
		};
		class HALV_paintshop_textureback: HP_IGUIBack
		{
			idc = 6669;
			x = 0.128557 * safezoneW + safezoneX;
			y = 0.224973 * safezoneH + safezoneY;
			w = 0.165086 * safezoneW;
			h = 0.550055 * safezoneH;
		};
		class HALV_paintshop_mainback: HP_IGUIBack
		{
			idc = -1;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.247629 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_mainframe: HP_RscFrame
		{
			idc = -1;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.247629 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_maintxt: HP_RscStructuredText
		{
			idc = -1;
			text = "Halv's Paintshop:"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.786029 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.1)";
		};
		class HALV_paintshop_maintxtframe: HP_RscFrame
		{
			idc = -1;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.786028 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainvehframe: HP_RscFrame
		{
			idc = -1;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.786028 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainlistframe: HP_RscFrame
		{
			idc = -1;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.121012 * safezoneH;
		};
		class HALV_paintshop_mainswitchframe: HP_RscFrame
		{
			idc = -1;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainlist: HP_RscListBox
		{
			idc = 6673;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.121012 * safezoneH;
			onLBDblClick = "call HALV_paintshop_onLBDblClick2;false";
			onLBSelChanged = "call HALV_paintshop_onLBSelChanged2;false";
		};
		class HALV_paintshop_texlist: HP_RscListBox
		{
			idc = 6675;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.290979 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.462046 * safezoneH;
			onLBDblClick = "_this call HALV_paintshop_addtolist;false";
			onLBSelChanged = "_this call HALV_paintshop_onLBSelChanged;false";
		};
		class HALV_paintshop_mainswitch: HP_RscCheckbox
		{
			idc = 6674;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
			strings[] = {"Colour Mode"};
			checked_strings[] = {"Texture Mode"};
			onCheckBoxesSelChanged = "_this call HALV_paintshop_checkchanged;false";
			tooltip = "Click to switch between texture list and colour sliders"; // Tooltip text
		};
		class HALV_paintshop_textxt: HP_RscStructuredText
		{
			idc = 6676;
			text = "Select Texture"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.246975 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.0330033 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
		};
		class HALV_paintshop_mainbutacc: HP_RscButton
		{
			idc = 6677;
			text = "Accept Selected"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.918042 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
			action = "call HALV_paintshop_selected;";
			tooltip = "Accept all colors / Textures on the list"; // Tooltip text
		};
		class HALV_paintshop_mainvehtxt: HP_RscStructuredText
		{
			idc = 6678;
			text = ""; //CurrentVehicle
			x = 0.267847 * safezoneW + safezoneX;
			y = 0.786029 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.0330033 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			tooltip = "Currently Painting"; // Tooltip text
		};
		class HALV_paintshop_mainbutadd: HP_RscButton
		{
			idc = 6679;
			text = "== Add to list =>"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.874037 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
			action = "call HALV_paintshop_addtolist;";
			tooltip = "Add Current Selected Color / Texture to the list"; // Tooltip text
		};
		class HALV_paintshop_sliderback: HP_IGUIBack
		{
			idc = 6667;
			x = 0.376185 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.412715 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_sliderframe: HP_RscFrame
		{
			idc = 6668;
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.376185 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.412715 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_slider1: HP_slider
		{
			idc = 6681;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.786029 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 1, 0, 0, .5 }; 
			coloractive[] = { 1, 0, 0, 1 };
			tooltip = "Slide to increase / decrease red color"; // Tooltip text
		};
		class HALV_paintshop_slider2: HP_slider
		{
			idc = 6682;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 0, 1, 0, .5 }; 
			coloractive[] = { 0, 1, 0, 1 };
			tooltip = "Slide to increase / decrease green color"; // Tooltip text
		};
		class HALV_paintshop_slider3: HP_slider
		{
			idc = 6683;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.874037 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 0, 0, 1, .5 }; 
			coloractive[] = { 0, 0, 1, 1 };
			tooltip = "Slide to increase / decrease blue color"; // Tooltip text
		};
		class HALV_paintshop_slider4: HP_slider
		{
			idc = 6684;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.918042 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 1, 1, 1, .5 }; 
			coloractive[] = { 1, 1, 1, 1 };
			tooltip = "Slide to increase / decrease saturation"; // Tooltip text
		};
	};
};
