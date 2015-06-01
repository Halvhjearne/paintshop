/*
	Vehicle & backpack Paintshop
	By Halv
*/

#include "settings.sqf";

HALV_paintshop_opendialog = {
	if(isNull _this)exitWith{};
	HALV_paintshop_vehicletopaint = _this;
	_txt = (gettext (configFile >> "cfgvehicles" >> (typeOf HALV_paintshop_vehicletopaint) >> "displayName"));
	HALV_paintshop_color = [0,0,0,0];
	HALV_paintshop_defaultsides = HALV_paintshop_vehicletopaint getVariable ["HALV_DEFAULTTEX",[]];
	if(HALV_paintshop_defaultsides isEqualTo [])then{
		HALV_paintshop_defaultsides = [];
		{
			if(_x != "")then{
				HALV_paintshop_defaultsides pushBack [_forEachIndex,_x];
			};
		}forEach getObjectTextures HALV_paintshop_vehicletopaint;
		HALV_paintshop_vehicletopaint setVariable ["HALV_DEFAULTTEX",HALV_paintshop_defaultsides,true];
	};
	HALV_paintshop_sidestopaint = [];
	{
		if(_x != "")then{
			HALV_paintshop_sidestopaint pushBack [_forEachIndex,_x];
		};
	}forEach getObjectTextures HALV_paintshop_vehicletopaint;
	HALV_paintshop_currentside = 0;
	HALV_paintshop_texture = (HALV_paintshop_defaultsides select 0)select 1;
	createDialog "HALV_painshop_dialog";
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6678;_ctrl ctrlEnable false;
	{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow false;}forEach [6669,6670,6671,6672,6675,6676];
	{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl sliderSetRange [0,1];_ctrl sliderSetSpeed [0.01,0.03];}forEach [6681,6682,6683,6684];
	_ctrl = (findDisplay 6666) displayCtrl 6678;
	_ctrl ctrlSetText _txt;
	_ctrl = (findDisplay 6666) displayCtrl 6673;
	lbClear _ctrl;
	{
		_text = format["Side %1",_x select 0];
		_index = _ctrl lbAdd _text;
		_ctrl lbSetPicture [_index,_x select 1];
		_ctrl lbSetPictureColor [_index, [1, 1, 1, 1]];
		_ctrl lbSetPictureColorSelected [_index, [1, 1, 1, 1]];
		_ctrl lbSetData [_index,_x select 1];
		_ctrl lbSetValue [_index,_x select 0];
		_ctrl lbSetTooltip [_index,"Double Click to Reset Texture"];
	}forEach HALV_paintshop_sidestopaint;
};

HALV_paintshop_checkchanged = {
	disableSerialization;
	if(_this select 2 == 1)then{
		{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow false;}forEach [6667,6668,6681,6682,6683,6684];
		{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow true;}forEach [6669,6670,6671,6672,6675,6676];
		call HALV_paintshop_filllistbox;
	}else{
		{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow false;}forEach [6669,6670,6671,6672,6675,6676];
		{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow true;}forEach [6667,6668,6681,6682,6683,6684];
	};
};

HALV_paintshop_filllistbox = {
	#include "settings.sqf";
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6675;
	lbClear _ctrl;
	_colorsConfig=configFile >> "CfgVehicles" >> (typeOf HALV_paintshop_vehicletopaint) >> "availableColors";
	if(isArray(_colorsConfig))then{
//		_textureSelectionIndex=configFile >> "CfgVehicles" >> (typeOf HALV_paintshop_vehicletopaint) >> "textureSelectionIndex";
		_colors=getArray(_colorsConfig);
		{
			_fi = _forEachIndex;
			{
				_lb = _ctrl lbAdd format["Skin: %1 %2",_fi,_forEachIndex];
				_ctrl lbSetData [_lb,_x];
				_ctrl lbSetPicture [_lb,_x];
				_ctrl lbSetPictureColor [_lb, [1, 1, 1, 1]];
				_ctrl lbSetPictureColorSelected [_lb, [1, 1, 1, 1]];
				_ctrl lbSetTooltip [_lb,"Click to Test Texture"];
			}forEach _x;
		}forEach _colors;
	};
	{
		_fi = _forEachIndex;
		_color = _x select 1;
		_lb = _ctrl lbAdd format["Default: %1",_fi];
		_ctrl lbSetData [_lb,_color];
		_ctrl lbSetPicture [_lb,_color];
		_ctrl lbSetPictureColor [_lb, [1, 1, 1, 1]];
		_ctrl lbSetPictureColorSelected [_lb, [1, 1, 1, 1]];
		_ctrl lbSetTooltip [_lb,"Click to Test Texture"];
	}forEach HALV_paintshop_defaultsides;
	{
		_lb = _ctrl lbAdd (_x select 0);
		_ctrl lbSetPicture [_lb,(_x select 1)];
		_ctrl lbSetData [_lb,(_x select 1)];
		_ctrl lbSetPictureColor [_lb, [1, 1, 1, 1]];
		_ctrl lbSetPictureColorSelected [_lb, [1, 1, 1, 1]];
		_ctrl lbSetTooltip [_lb,"Click to Test Texture"];
	}forEach _textures;
	lbSort _ctrl;
};

HALV_paintshop_slidingcolor = {
	_ctrl = _this select 0;
	_val = _this select 1;
	if(_val != sliderPosition _ctrl)exitWith{};
	switch(str _ctrl)do{
		case "Control #6681":{HALV_paintshop_color set [0,_val];};
		case "Control #6682":{HALV_paintshop_color set [1,_val];};
		case "Control #6683":{HALV_paintshop_color set [2,_val];};
		case "Control #6684":{HALV_paintshop_color set [3,_val];};
	};
	HALV_paintshop_vehicletopaint setObjectTexture [HALV_paintshop_currentside,format["#(argb,8,8,3)color(%1,%2,%3,%4)",HALV_paintshop_color select 0,HALV_paintshop_color select 1,HALV_paintshop_color select 2,HALV_paintshop_color select 3]];
	hintSilent str(HALV_paintshop_color);
};

HALV_paintshop_selected = {
	#include "settings.sqf";
	closeDialog 0;
	diag_log str['HALVSETTEX:',HALV_paintshop_sidestopaint];
	{
		_tex = _x select 1;
		if(typeName (_x select 1) == "ARRAY")then{
			_tex = format["#(argb,8,8,3)color(%1,%2,%3,%4)",(_x select 1) select 0,(_x select 1) select 1,(_x select 1) select 2,(_x select 1) select 3];
			HALV_paintshop_vehicletopaint setObjectTextureGlobal [_x select 0,format["#(argb,8,8,3)color(%1,%2,%3,%4)",(_x select 1) select 0,(_x select 1) select 1,(_x select 1) select 2,(_x select 1) select 3]];
		};
		HALV_paintshop_vehicletopaint setObjectTextureGlobal [_x select 0,_tex];
		if(HALV_paintshop_vehicletopaint isKindOf "bag_base")then{
			_pname = format["%1_BAGCOLOR",_servername];
			profileNamespace setVariable [_pname,[Backpack player,_tex,HALV_paintshop_defaultsides]]
		};
	}forEach HALV_paintshop_sidestopaint;
};

HALV_paintshop_addtolist = {
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6674;
	_tex = if (ctrlChecked _ctrl)then{HALV_paintshop_texture}else{format["#(argb,8,8,3)color(%1,%2,%3,%4)",HALV_paintshop_color select 0,HALV_paintshop_color select 1,HALV_paintshop_color select 2,HALV_paintshop_color select 3]};
	{
		if(HALV_paintshop_currentside == _x select 0)exitWith{
			HALV_paintshop_sidestopaint deleteAt _forEachIndex;
		};
	}forEach HALV_paintshop_sidestopaint;
	HALV_paintshop_sidestopaint pushBack [HALV_paintshop_currentside,_tex];
	call HALV_paintshop_switchside;
	_ctrl = (findDisplay 6666) displayCtrl 6680;
	_price = (count HALV_paintshop_sidestopaint)*25;
	_ctrl ctrlSetText ""+(str _price)+" Crypto";
	_ctrl = (findDisplay 6666) displayCtrl 6673;
	lbClear _ctrl;
	{
		_text = format["Side %1",_x select 0];
		_index = _ctrl lbAdd _text;
		_ctrl lbSetPicture [_index,_x select 1];
		_ctrl lbSetPictureColor [_index, [1, 1, 1, 1]];
		_ctrl lbSetPictureColorSelected [_index, [1, 1, 1, 1]];
		_ctrl lbSetData [_index,_x select 1];
		_ctrl lbSetValue [_index,_x select 0];
		_ctrl lbSetTooltip [_index,"Double Click to Reset Texture"];
	}forEach HALV_paintshop_sidestopaint;
	lbSort _ctrl;
	diag_log str['HALVADDTEX:',_tex];
};

HALV_paintshop_onLBSelChanged = {
	_texture = (_this select 0) lbData (_this select 1);
	HALV_paintshop_vehicletopaint setObjectTexture [HALV_paintshop_currentside,_texture];
	HALV_paintshop_texture = _texture;
};

HALV_paintshop_onLBSelChanged2 = {
	_ctrl = _this select 0;
	_lb = _this select 1;
	_texture = _ctrl lbData _lb;
	_value = _ctrl lbValue _lb;
	HALV_paintshop_currentside = _value;
	HALV_paintshop_texture = _texture;
};

HALV_paintshop_onLBDblClick2 = {
	disableSerialization;
	_ctrl = _this select 0;
	_lb = _this select 1;
	_value = _ctrl lbValue _lb;
	HALV_paintshop_vehicletopaint setObjectTexture (HALV_paintshop_defaultsides select _value);
	HALV_paintshop_sidestopaint set [_value,(HALV_paintshop_defaultsides select _value)];
	diag_log str['HALVREMTEX:',[_value,(HALV_paintshop_defaultsides select _value)]];
	_ctrl = (findDisplay 6666) displayCtrl 6680;
	_price = (count HALV_paintshop_sidestopaint)*25;
	_ctrl ctrlSetText ""+(str _price)+" Crypto";
	_ctrl = (findDisplay 6666) displayCtrl 6673;
	lbClear _ctrl;
	{
		_text = format["Side %1",_x select 0];
		_index = _ctrl lbAdd _text;
		_ctrl lbSetPicture [_index,_x select 1];
		_ctrl lbSetPictureColor [_index, [1, 1, 1, 1]];
		_ctrl lbSetPictureColorSelected [_index, [1, 1, 1, 1]];
		_ctrl lbSetData [_index,_x select 1];
		_ctrl lbSetValue [_index,_x select 0];
		_ctrl lbSetTooltip [_index,"Double Click to Reset Texture"];
	}forEach HALV_paintshop_sidestopaint;
	lbSort _ctrl;
};

HALV_paintshop_switchside = {
	HALV_paintshop_currentside = HALV_paintshop_currentside + 1;
	if(HALV_paintshop_currentside >= count HALV_paintshop_defaultsides)then{HALV_paintshop_currentside = 0;};
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6673;
	_ctrl lbSetCurSel HALV_paintshop_currentside;
};

waitUntil {!isNull (findDisplay 46)};
waitUntil {!dialog};

_pname = format["%1_BAGCOLOR",_servername];
_pcolor = profileNamespace getVariable [_pname,[]];
if (!(_pcolor isEqualTo []) && !isNull (unitBackpack player) && Backpack player == _pcolor select 0)then{
	_bag = (unitBackpack player);
	_bag setObjectTextureGlobal [0,_pcolor select 1];
	_bag setVariable ["HALV_DEFAULTTEX",_pcolor select 2,true];
};

_HALV_panitshop_action1 = -1;
_HALV_panitshop_action2 = -1;

_sendmessage = true;

while{alive player}do{
	_nearpaintshops = (nearestObjects [player,["Land_CarService_F","Land_Repair_center"],15]) - [player];
	_inRange = count _nearpaintshops > 0;
	if(_inRange)then{
		if(_sendmessage)then{
			player sideChat "-- Paint Shop --";
			_sendmessage = false;
		};
		if(player == vehicle player)then{
			if(!isNull (unitBackpack player) && player distance (_nearpaintshops select 0) < 10)then{
				if(_HALV_panitshop_action2< 0)then{
					_HALV_panitshop_action2 = player addAction ["<img size='1.5'image='\a3\Ui_f\data\map\VehicleIcons\iconmanmedic_ca.paa'/> <t color='#0096ff'>Paint Backpack</t>", "addons\paintshop\openpaintshop.sqf", (unitBackpack player),1, false, true, "", ""];
				};
			}else{
				player removeAction _HALV_panitshop_action2;
				_HALV_panitshop_action2 = -1;
			};
			_ct = cursorTarget;
			if(!isNull _ct)then{
				if({_ct isKindOf _x}count ["Air","Ship","Landvehicle"] > 0 && player distance _ct < 7.5)then{
					if(_HALV_panitshop_action1 < 0)then{
						_txt = (gettext (configFile >> 'cfgvehicles' >> (typeOf _ct) >> 'displayName'));
						_HALV_panitshop_action1 = player addAction [format["<img size='1.5'image='\a3\Ui_f\data\map\VehicleIcons\iconmanmedic_ca.paa'/> <t color='#0096ff'>Paint %1</t>",_txt], "addons\paintshop\openpaintshop.sqf", _ct,1, false, true, "", ""];
					};
				}else{
					player removeAction _HALV_panitshop_action1;
					_HALV_panitshop_action1 = -1;
				};
			}else{
				player removeAction _HALV_panitshop_action1;
				_HALV_panitshop_action1 = -1;
			};
		}else{
			player removeAction _HALV_panitshop_action1;
			_HALV_panitshop_action1 = -1;
			player removeAction _HALV_panitshop_action2;
			_HALV_panitshop_action2 = -1;
		};
	}else{
		player removeAction _HALV_panitshop_action1;
		_HALV_panitshop_action1 = -1;
		_sendmessage = true;
		player removeAction _HALV_panitshop_action2;
		_HALV_panitshop_action2 = -1;
	};
	sleep 2;
};

_pname = format["%1_BAGCOLOR",_servername];
_tex = profileNamespace getVariable [_pname,[]];
profileNamespace setVariable [_pname,nil];
waitUntil{alive player};
profileNamespace setVariable [_pname,_tex];
[]execVM __FILE__;