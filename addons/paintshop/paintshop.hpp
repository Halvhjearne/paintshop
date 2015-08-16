/*
	Vehicle, uniform & backpack Paintshop
	By Halv
	
	Copyright (C) 2015  Halvhjearne > README.md
*/

class HALV_painshop_dialog
{
	idd=6666;
	moveingenabled=false;
	class controls
	{
		class HALV_paintshop_textextframe: HALV_RscFrame
		{
			idc = 6672;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.246975 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_textureframe: HALV_RscFrame
		{
			idc = 6670;
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.224972 * safezoneH + safezoneY;
			w = 0.165086 * safezoneW;
			h = 0.550055 * safezoneH;
		};
		class HALV_paintshop_texlistframe: HALV_RscFrame
		{
			idc = 6671;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.290979 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.462046 * safezoneH;
		};
		class HALV_paintshop_textureback: HALV_IGUIBack
		{
			idc = 6669;
			x = 0.128557 * safezoneW + safezoneX;
			y = 0.224973 * safezoneH + safezoneY;
			w = 0.165086 * safezoneW;
			h = 0.550055 * safezoneH;
		};
		class HALV_paintshop_mainback: HALV_IGUIBack
		{
			idc = -1;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.247629 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_mainframe: HALV_RscFrame
		{
			idc = -1;
			x = 0.128556 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.247629 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_maintxt: HALV_RscStructuredText
		{
			idc = -1;
			text = "Halv's Paintshop:"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.786029 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.1)";
		};
		class HALV_paintshop_maintxtframe: HALV_RscFrame
		{
			idc = -1;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.786028 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainvehframe: HALV_RscFrame
		{
			idc = -1;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.786028 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainlistframe: HALV_RscFrame
		{
			idc = -1;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.121012 * safezoneH;
		};
		class HALV_paintshop_mainswitchframe: HALV_RscFrame
		{
			idc = -1;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.118656 * safezoneW;
			h = 0.0330033 * safezoneH;
		};
		class HALV_paintshop_mainlist: HALV_RscListBox
		{
			idc = 6673;
			x = 0.267848 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.0980199 * safezoneW;
			h = 0.121012 * safezoneH;
			onLBDblClick = "call HALV_paintshop_onLBDblClick2;false";
			onLBSelChanged = "call HALV_paintshop_onLBSelChanged2;false";
		};
		class HALV_paintshop_texlist: HALV_RscListBox
		{
			idc = 6675;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.290979 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.462046 * safezoneH;
			onLBDblClick = "_this call HALV_paintshop_addtolist;false";
			onLBSelChanged = "_this call HALV_paintshop_onLBSelChanged;false";
		};
		class HALV_paintshop_mainswitch: HALV_RscCheckbox
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
		class HALV_paintshop_textxt: HALV_RscStructuredText
		{
			idc = 6676;
			text = "Select Texture"; //--- ToDo: Localize;
			x = 0.138874 * safezoneW + safezoneX;
			y = 0.246975 * safezoneH + safezoneY;
			w = 0.14445 * safezoneW;
			h = 0.0330033 * safezoneH;
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
		};
		class HALV_paintshop_mainbutacc: HALV_RscButton
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
		class HALV_paintshop_mainvehtxt: HALV_RscStructuredText
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
		class HALV_paintshop_mainbutadd: HALV_RscButton
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
		class HALV_paintshop_sliderback: HALV_IGUIBack
		{
			idc = 6667;
			x = 0.376185 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.412715 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_sliderframe: HALV_RscFrame
		{
			idc = 6668;
			text = "Paintshop by Halv"; //--- ToDo: Localize;
			x = 0.376185 * safezoneW + safezoneX;
			y = 0.775027 * safezoneH + safezoneY;
			w = 0.412715 * safezoneW;
			h = 0.187019 * safezoneH;
		};
		class HALV_paintshop_slider1: HALV_RscSlider
		{
			idc = 6681;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.786029 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 1, 0, 0, .5 }; 
			coloractive[] = { 1, 0, 0, 1 };
			onSliderPosChanged = "_this call HALV_paintshop_slidingcolor;false";
			tooltip = "Slide to increase / decrease red color"; // Tooltip text
		};
		class HALV_paintshop_slider2: HALV_RscSlider
		{
			idc = 6682;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.830033 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 0, 1, 0, .5 }; 
			coloractive[] = { 0, 1, 0, 1 };
			onSliderPosChanged = "_this call HALV_paintshop_slidingcolor;false";
			tooltip = "Slide to increase / decrease green color"; // Tooltip text
		};
		class HALV_paintshop_slider3: HALV_RscSlider
		{
			idc = 6683;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.874037 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 0, 0, 1, .5 }; 
			coloractive[] = { 0, 0, 1, 1 };
			onSliderPosChanged = "_this call HALV_paintshop_slidingcolor;false";
			tooltip = "Slide to increase / decrease blue color"; // Tooltip text
		};
		class HALV_paintshop_slider4: HALV_RscSlider
		{
			idc = 6684;
			x = 0.381344 * safezoneW + safezoneX;
			y = 0.918042 * safezoneH + safezoneY;
			w = 0.397238 * safezoneW;
			h = 0.0330033 * safezoneH;
			color[] = { 1, 1, 1, .5 }; 
			coloractive[] = { 1, 1, 1, 1 };
			onSliderPosChanged = "_this call HALV_paintshop_slidingcolor;false";
			tooltip = "Slide to increase / decrease saturation"; // Tooltip text
		};
	};
};
