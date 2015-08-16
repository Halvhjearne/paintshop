/*
	Vehicle, uniform & backpack Paintshop
	By Halv
	
	Copyright (C) 2015  Halvhjearne > README.md
*/

#include "settings.sqf";

HALV_paintshop_opendialog = {
	if(isNull _this)exitWith{};
	HALV_paintshop_vehicletopaint = _this;
	HALV_paintshop_color = [0,0,0,0.6];
	HALV_paintshop_defaultsides = HALV_paintshop_vehicletopaint getVariable ["VEHICLE_DEFAULTTEX",[]];
	if(HALV_paintshop_defaultsides isEqualTo [])then{
		HALV_paintshop_defaultsides = getObjectTextures HALV_paintshop_vehicletopaint;
		HALV_paintshop_vehicletopaint setVariable ["VEHICLE_DEFAULTTEX",HALV_paintshop_defaultsides,true];
	};
	_typeOf = typeOf HALV_paintshop_vehicletopaint;
	_txt = (gettext (configFile >> "cfgvehicles" >> _typeOf >> "displayName"));
	if(count(HALV_paintshop_defaultsides) < 1)exitWith{
		titleText [format["%1 can not be painted ...",_txt],"PLAIN DOWN"];
		diag_log format["%1 could not be painted ...",_typeOf];
	};
	HALV_paintshop_sidestopaint = [];
	{
		HALV_paintshop_sidestopaint pushBack [_forEachIndex,_x];
	}forEach getObjectTextures HALV_paintshop_vehicletopaint;
	HALV_paintshop_currentside = 0;
	HALV_paintshop_texture = HALV_paintshop_defaultsides select 0;
	createDialog "HALV_painshop_dialog";
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6678;_ctrl ctrlEnable false;
	{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl ctrlShow false;}forEach [6669,6670,6671,6672,6675,6676];
	{_ctrl = (findDisplay 6666) displayCtrl _x;_ctrl sliderSetRange [0,1];_ctrl sliderSetSpeed [0.01,0.03];}forEach [6681,6682,6683,6684];
	_ctrl sliderSetPosition 0.6;
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
	if((_this select 2) isEqualTo 1)then{
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
		_lb = _ctrl lbAdd format["Default: Side %1",_fi];
		_ctrl lbSetData [_lb,_x];
		_ctrl lbSetPicture [_lb,_x];
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
	if !(_val isEqualTo (sliderPosition _ctrl))exitWith{};
	_arr = switch(str _ctrl)do{
		case "Control #6681":{[0,_val];};
		case "Control #6682":{[1,_val];};
		case "Control #6683":{[2,_val];};
		case "Control #6684":{[3,_val];};
	};
	HALV_paintshop_color set _arr;
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
		if(_tex == "")then{
			_tex = HALV_paintshop_defaultsides select (_x select 0);
		};
		HALV_paintshop_vehicletopaint setObjectTextureGlobal [_x select 0,_tex];
	}forEach HALV_paintshop_sidestopaint;
	_alltex = getObjectTextures HALV_paintshop_vehicletopaint;
	switch(true)do{
		case (HALV_paintshop_vehicletopaint isKindOf "bag_base"):{
			if(_alltex isEqualTo HALV_paintshop_defaultsides)then{
				profileNamespace setVariable ["HALV_BAGCOLOR",nil];
				HALV_paintshop_vehicletopaint setVariable ["VEHICLE_DEFAULTTEX",nil];
			}else{
				profileNamespace setVariable ["HALV_BAGCOLOR",_alltex];
			};
		};
		case (HALV_paintshop_vehicletopaint isEqualTo player):{
			if(_alltex isEqualTo HALV_paintshop_defaultsides)then{
				profileNamespace setVariable ["HALV_UNIFORMCOLOR",nil];
				HALV_paintshop_vehicletopaint setVariable ["VEHICLE_DEFAULTTEX",nil];
			}else{
				profileNamespace setVariable ["HALV_UNIFORMCOLOR",_alltex];
			};
		};
		default{
			if (HALV_paintshop_vehicletopaint getVariable ["VEHICLE_SLOT","ABORT"] != "ABORT")then{
				if !(isPlayer HALV_paintshop_vehicletopaint)then{
/*
					HALV_vehsavetex = [player,HALV_paintshop_vehicletopaint];
					publicVariableServer "HALV_vehsavetex";
*/
				}else{
//					titleText ["[SERVER]:\n*** VEHICLE PAINTJOB NOT SAVED! ***\nThere was a player in the vehicle!","PLAIN DOWN"];
				};
			};
		};
	};
};

HALV_paintshop_addtolist = {
	disableSerialization;
	_ctrl = (findDisplay 6666) displayCtrl 6674;
	_tex = if (ctrlChecked _ctrl)then{HALV_paintshop_texture}else{format["#(argb,8,8,3)color(%1,%2,%3,%4)",HALV_paintshop_color select 0,HALV_paintshop_color select 1,HALV_paintshop_color select 2,HALV_paintshop_color select 3]};
	{
		if(HALV_paintshop_currentside isEqualTo (_x select 0))exitWith{
			HALV_paintshop_sidestopaint deleteAt _forEachIndex;
		};
	}forEach HALV_paintshop_sidestopaint;
	HALV_paintshop_sidestopaint pushBack [HALV_paintshop_currentside,_tex];
	call HALV_paintshop_switchside;
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
	HALV_paintshop_vehicletopaint setObjectTexture [HALV_paintshop_currentside,(HALV_paintshop_defaultsides select _value)];
	HALV_paintshop_sidestopaint set [_value,[HALV_paintshop_currentside,(HALV_paintshop_defaultsides select _value)]];
	diag_log str['HALVREMTEX:',[_value,[HALV_paintshop_currentside,(HALV_paintshop_defaultsides select _value)]]];
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

waitUntil {!isNuLL(uiNameSpace getVariable ["EPOCH_loadingScreen",displayNull])};
waitUntil {isNuLL(uiNameSpace getVariable ["EPOCH_loadingScreen",displayNull])};
waitUntil{!isNull (findDisplay 46) && !dialog && typeOf player != "VirtualMan_EPOCH"};

_pcolor = profileNamespace getVariable ["HALV_BAGCOLOR",[]];
if (!(_pcolor isEqualTo []) && !(Backpack player in ["","B_Parachute","B_O_Parachute_02_F","B_I_Parachute_02_F","B_B_Parachute_02_F"]))then{
	_bag = (unitBackpack player);
	_defaultsides = getObjectTextures _bag;
	if(count _defaultsides > 0)then{
		if(typeName(_pcolor select 0) == "ARRAY")then{
			{_bag setObjectTextureGlobal _x;}forEach _pcolor;
			profileNamespace setVariable ["HALV_BAGCOLOR",(getObjectTextures _bag)];
		}else{
			{_bag setObjectTextureGlobal [_forEachIndex,_x];}forEach _pcolor;
		};
		if("" in (getObjectTextures _bag))then{
			{_bag setObjectTextureGlobal [_forEachIndex,_x];}forEach _defaultsides;
			profileNamespace setVariable ["HALV_BAGCOLOR",nil];
		}else{
			_bag setVariable ["VEHICLE_DEFAULTTEX",_defaultsides,true];
		};
	}else{
		_txt = (gettext (configFile >> "cfgvehicles" >> (Backpack player) >> "displayName"));
		systemChat format["%1 could not be painted ...",_txt];
		diag_log format["%1 could not be painted ...",Backpack player];
	};
};

_pcolor = profileNamespace getVariable ["HALV_UNIFORMCOLOR",[]];
if (!(_pcolor isEqualTo []) && !(Uniform player in ["","U_Test1_uniform","U_Test_uniform"]))then{
	_defaultsides = getObjectTextures player;
	if(count _defaultsides > 0)then{
		if(typeName(_pcolor select 0) == "ARRAY")then{
			{player setObjectTextureGlobal _x;}forEach _pcolor;
			profileNamespace setVariable ["HALV_UNIFORMCOLOR",(getObjectTextures player)];
		}else{
			{player setObjectTextureGlobal [_forEachIndex,_x];}forEach _pcolor;
		};
		if("" in (getObjectTextures player))then{
			{player setObjectTextureGlobal [_forEachIndex,_x];}forEach _defaultsides;
			profileNamespace setVariable ["HALV_UNIFORMCOLOR",nil];
		}else{
			player setVariable ["VEHICLE_DEFAULTTEX",_defaultsides,true];
		};
	}else{
		_txt = (gettext (configFile >> "cfgvehicles" >> (Uniform player) >> "displayName"));
		systemChat format["%1 could not be painted ...",_txt];
		diag_log format["%1 could not be painted ...",Uniform player];
	};
};

_HALV_panitshop_bagaction = -1;
_HALV_panitshop_uniformaction = -1;
_HALV_panitshop_vehicleactions = [];
_lastsearch = [];

_sendmessage = true;

while{alive player}do{
	_nearpaintshops = (nearestObjects [player,_paintshopbuildings,15])-[player];
	_inRange = count _nearpaintshops > 0;
	if(_inRange)then{
		if(_sendmessage)then{
			player sideChat "-- Paint Shop --";
			_sendmessage = false;
		};
		if(player isEqualTo vehicle player)then{
			if !(Backpack player in ["","B_Parachute","B_O_Parachute_02_F","B_I_Parachute_02_F","B_B_Parachute_02_F"])then{
				if(_HALV_panitshop_bagaction< 0)then{
					_HALV_panitshop_bagaction = player addAction ["<img size='1.5'image='\a3\Ui_f\data\map\VehicleIcons\iconmanmedic_ca.paa'/> <t color='#0096ff'>Paint Backpack</t>", {(_this select 3) call HALV_paintshop_opendialog;}, (unitBackpack player),1, false, true, "", ""];
				};
			}else{
				player removeAction _HALV_panitshop_bagaction;
				_HALV_panitshop_bagaction = -1;
			};
			if !(Uniform player in ["","U_Test1_uniform","U_Test_uniform"])then{
				if(_HALV_panitshop_uniformaction< 0)then{
					_HALV_panitshop_uniformaction = player addAction ["<img size='1.5'image='\a3\Ui_f\data\map\VehicleIcons\iconmanmedic_ca.paa'/> <t color='#0096ff'>Paint Uniform</t>", {(_this select 3) call HALV_paintshop_opendialog;}, player,1, false, true, "", ""];
				};
			}else{
				player removeAction _HALV_panitshop_uniformaction;
				_HALV_panitshop_uniformaction = -1;
			};
			_nearvehicles = (player nearEntities [["Air","LandVehicle","Ship"],40])-[player];
			if !(_nearvehicles isEqualTo _lastsearch)then{{player removeAction _x}forEach _HALV_panitshop_vehicleactions;_HALV_panitshop_vehicleactions = [];};
			if(count _HALV_panitshop_vehicleactions < 1)then{
				{
					if !(_x isKindOf "Wreck_Base")then{
						_txt = (gettext (configFile >> 'cfgvehicles' >> (typeOf _x) >> 'displayName'));
						_action = player addAction [format["<img size='1.5'image='\a3\Ui_f\data\map\VehicleIcons\iconmanmedic_ca.paa'/> <t color='#0096ff'>Paint %1</t>",_txt], {(_this select 3) call HALV_paintshop_opendialog;}, _x,1, false, true, "", ""];
						_HALV_panitshop_vehicleactions pushBack _action;
					};
				}forEach _nearvehicles;
			};
			_lastsearch = _nearvehicles;
		}else{
			{player removeAction _x}forEach _HALV_panitshop_vehicleactions+[_HALV_panitshop_bagaction,_HALV_panitshop_uniformaction];
			_HALV_panitshop_vehicleactions = [];
			_HALV_panitshop_uniformaction = -1;
			_HALV_panitshop_bagaction = -1;
			_lastsearch = [];
		};
	}else{
		_sendmessage = true;
		{player removeAction _x}forEach _HALV_panitshop_vehicleactions+[_HALV_panitshop_bagaction,_HALV_panitshop_uniformaction];
		_HALV_panitshop_vehicleactions = [];
		_HALV_panitshop_uniformaction = -1;
		_HALV_panitshop_bagaction = -1;
		_lastsearch = [];
	};
	sleep 2;
};

waitUntil{alive player};

[]execVM __FILE__;