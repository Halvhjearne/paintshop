/*
	Vehicle, uniform & backpack Paintshop
	By Halv
	
	Copyright (C) 2015  Halvhjearne > README.md
*/

if(isServer)then{
/*
	HALV_server_savetextures = {
		private ["_vehicle","_textures","_deftex","_savearr","_vehSlot","_vehHiveKey"];
		_player = _this select 0;
		_vehicle = _this select 1;
		if (!isNull _vehicle) then {
			_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
			if (_vehSlot != "ABORT") then {
				_textures = getObjectTextures _vehicle;
				_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];
				_vehicle setVariable ["VEHICLE_TEXTURE",666];
				_vehicle call EPOCH_server_save_vehicle;
				_deftex = _vehicle getVariable ["VEHICLE_DEFAULTTEX",[]];
				_savearr = [_textures,_deftex];
				["VehicleCustomTex",_vehHiveKey,_savearr]call EPOCH_server_hiveSET;
				diag_log str["VehicleCustomTex save:",_vehHiveKey, EPOCH_expiresVehicle,_savearr];
				HalvPV_player_message = ["titleText", ["[SERVER]:\n*** VEHICLE PAINTJOB SAVED! ***", "PLAIN DOWN"]];
				(owner _player) publicVariableClient "HalvPV_player_message";
			};
		};
	};
	"HALV_vehsavetex" addPublicVariableEventHandler {(_this select 1) call HALV_server_savetextures;};
*/
};
