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
		class HALV_paintshop_mainback: HP_IGUIBack
		{
			idc = -1;
			x = 0.149225 * safezoneW + safezoneX;
			y = 0.708947 * safezoneH + safezoneY;
			w = 0.206338 * safezoneW;
			h = 0.186953 * safezoneH;
		};
		class HALV_paintshop_mainframe: HP_RscFrame
		{
			idc = -1;
//			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.149225 * safezoneW + safezoneX;
			y = 0.708948 * safezoneH + safezoneY;
			w = 0.206338 * safezoneW;
			h = 0.186953 * safezoneH;
		};
		class HALV_paintshop_maintext: HP_RscStructuredText
		{
			idc = -1;
			text = "Halv's Paintshop:"; //--- ToDo: Localize;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.719945 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
		};
		class HALV_paintshop_maintextframe: HP_RscFrame
		{
			idc = -1;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.719945 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
		};
		class HALV_paintshop_mainlistframe: HP_RscFrame
		{
			idc = -1;
			x = 0.257553 * safezoneW + safezoneX;
			y = 0.741939 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0989751 * safezoneH;
		};
		class HALV_paintshop_checkboxframe: HP_RscFrame
		{
			idc = -1;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.763934 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
		};
		class HALV_paintshop_priceframe: HP_RscFrame
		{
			idc = -1;
			x = 0.257553 * safezoneW + safezoneX;
			y = 0.719945 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0219945 * safezoneH;
		};
		class HALV_paintshop_sliderback: HP_IGUIBack
		{
			idc = 6667;
			x = 0.355564 * safezoneW + safezoneX;
			y = 0.708948 * safezoneH + safezoneY;
			w = 0.392042 * safezoneW;
			h = 0.186953 * safezoneH;
		};
		class HALV_paintshop_sliderframe: HP_RscFrame
		{
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			idc = 6668;
			x = 0.355563 * safezoneW + safezoneX;
			y = 0.708948 * safezoneH + safezoneY;
			w = 0.392042 * safezoneW;
			h = 0.186953 * safezoneH;
		};
		class HALV_paintshop_listback: HP_IGUIBack
		{
			idc = 6669;
			x = 0.149225 * safezoneW + safezoneX;
			y = 0.225069 * safezoneH + safezoneY;
			w = 0.144437 * safezoneW;
			h = 0.483878 * safezoneH;
		};
		class HALV_paintshop_listframe1: HP_RscFrame
		{
			idc = 6670;
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.149225 * safezoneW + safezoneX;
			y = 0.225069 * safezoneH + safezoneY;
			w = 0.144437 * safezoneW;
			h = 0.483878 * safezoneH;
		};
		class HALV_paintshop_listtextframe: HP_RscFrame
		{
			idc = 6671;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.236066 * safezoneH + safezoneY;
			w = 0.123803 * safezoneW;
			h = 0.0329917 * safezoneH;
		};
		class HALV_paintshop_listframe2: HP_RscFrame
		{
			idc = 6672;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.269058 * safezoneH + safezoneY;
			w = 0.123803 * safezoneW;
			h = 0.428892 * safezoneH;
		};
		class HALV_paintshop_mainlistbox: HP_RscListBox
		{
			idc = 6673;
			x = 0.257553 * safezoneW + safezoneX;
			y = 0.741939 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0989751 * safezoneH;
			onLBDblClick = "call HALV_paintshop_onLBDblClick2;false";
			onLBSelChanged = "call HALV_paintshop_onLBSelChanged2;false";
		};
		class HALV_paintshop_checkbox: HP_RscCheckbox
		{
			idc = 6674;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.763934 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
			strings[] = {"Colour Mode"};
			checked_strings[] = {"Texture Mode"};
			onCheckBoxesSelChanged = "_this call HALV_paintshop_checkchanged;false";
			tooltip = "Click to switch between texture list and colour sliders"; // Tooltip text
		};
		class HALV_paintshop_listbox: HP_RscListBox
		{
			idc = 6675;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.269058 * safezoneH + safezoneY;
			w = 0.123803 * safezoneW;
			h = 0.428892 * safezoneH;
			onLBDblClick = "_this call HALV_paintshop_addtolist;false";
			onLBSelChanged = "_this call HALV_paintshop_onLBSelChanged;false";
		};
		class HALV_paintshop_listtext: HP_RscStructuredText
		{
			idc = 6676;
			text = "Select Texture:"; //--- ToDo: Localize;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.236066 * safezoneH + safezoneY;
			w = 0.123803 * safezoneW;
			h = 0.0329917 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
		};

		class HALV_paintshop_accept: HP_RscButton
		{
			idc = 6677;
			text = "Accept Selected"; //--- ToDo: Localize;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.851912 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
			action = "call HALV_paintshop_selected;";
			tooltip = "Accept all colors / Textures on the list"; // Tooltip text
		};
		class HALV_paintshop_clearall: HP_RscStructuredText
		{
			idc = 6678;
			text = ""; //--- ToDo: Localize;
			x = 0.257553 * safezoneW + safezoneX;
			y = 0.851912 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
			tooltip = "Current Vehicle"; // Tooltip text
		};
		class HALV_paintshop_addcurrent: HP_RscButton
		{
			idc = 6679;
			text = "Add to List"; //--- ToDo: Localize;
			x = 0.159542 * safezoneW + safezoneX;
			y = 0.807923 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0329917 * safezoneH;
			action = "call HALV_paintshop_addtolist;";
			tooltip = "Add Current Selected Color / Texture to the list"; // Tooltip text
		};

		class HALV_paintshop_price: HP_RscStructuredText
		{
			idc = 6680;
			text = "0 Crypto"; //--- ToDo: Localize;
			x = 0.257553 * safezoneW + safezoneX;
			y = 0.719945 * safezoneH + safezoneY;
			w = 0.0876937 * safezoneW;
			h = 0.0219945 * safezoneH;
		};

		class HALV_paintshop_slider1: HP_slider
		{
			idc = 6681;
			x = 0.360722 * safezoneW + safezoneX;
			y = 0.719945 * safezoneH + safezoneY;
			w = 0.381725 * safezoneW;
			h = 0.0329917 * safezoneH;
			color[] = { 1, 0, 0, .5 }; 
			coloractive[] = { 1, 0, 0, 1 };
			tooltip = "Slide to increase / decrease red color"; // Tooltip text
		};
		class HALV_paintshop_slider2: HP_slider
		{
			idc = 6682;
			x = 0.360722 * safezoneW + safezoneX;
			y = 0.763934 * safezoneH + safezoneY;
			w = 0.381725 * safezoneW;
			h = 0.0329917 * safezoneH;
			color[] = { 0, 1, 0, .5 }; 
			coloractive[] = { 0, 1, 0, 1 };
			tooltip = "Slide to increase / decrease green color"; // Tooltip text
		};
		class HALV_paintshop_slider3: HP_slider
		{
			idc = 6683;
			x = 0.360722 * safezoneW + safezoneX;
			y = 0.807923 * safezoneH + safezoneY;
			w = 0.381725 * safezoneW;
			h = 0.0329917 * safezoneH;
			color[] = { 0, 0, 1, .5 }; 
			coloractive[] = { 0, 0, 1, 1 };
			tooltip = "Slide to increase / decrease blue color"; // Tooltip text
		};
		class HALV_paintshop_slider4: HP_slider
		{
			idc = 6684;
			x = 0.360722 * safezoneW + safezoneX;
			y = 0.851912 * safezoneH + safezoneY;
			w = 0.381725 * safezoneW;
			h = 0.0329917 * safezoneH;
			color[] = { 1, 1, 1, .5 }; 
			coloractive[] = { 1, 1, 1, 1 };
			tooltip = "Slide to increase / decrease saturation"; // Tooltip text
		};
	};
};
