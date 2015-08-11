if(isServer)then{

	HALV_server_savetextures = {
		private ["_vehicle","_textures","_deftex","_savearr","_vehSlot","_vehHiveKey"];
		_vehicle = _this;
		if (!isNull _vehicle) then {
			_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
			if (_vehSlot != "ABORT") then {
				_textures = getObjectTextures _vehicle;
				_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];
				_vehicle setVariable ["VEHICLE_TEXTURE",666];
				_vehicle call EPOCH_server_save_vehicle;
				_deftex = _vehicle getVariable ["VEHICLE_DEFAULTTEX",[]];
				_newarr = [];
				{
					_string = _x call HALV_fnc_removebackslash;
					_newarr pushBack _string;
				}forEach _deftex;
				_deftex = _newarr;
				_newarr = [];
				{
					_string = _x call HALV_fnc_removebackslash;
					_newarr pushBack _string;
				}forEach _textures;
				_textures = _newarr;
				_savearr = [_textures,_deftex];
				["VehicleCustomTex",_vehHiveKey,_savearr]call EPOCH_server_hiveSET;
				diag_log str["VehicleCustomTex save:",_vehHiveKey, EPOCH_expiresVehicle,_savearr];
			};
		};
	};

	HALV_fnc_removebackslash = {
		_txtOUT = _this;
		_txtarr = toArray _txtOUT;
		{
			if(92 isEqualTo _x)then{
				_txtarr set [_forEachIndex,32];
				_txtOUT = toString _txtarr;
			};
		}forEach _txtarr;
		_txtOUT
	};

	HALV_fnc_addbackslash = {
		_txtOUT = _this;
		_txtarr = toArray _txtOUT;
		{
			if(32 isEqualTo _x)then{
				_txtarr set [_forEachIndex,92];
				_txtOUT = toString _txtarr;
			};
		}forEach _txtarr;
		_txtOUT
	};

	"HALV_vehsavetex" addPublicVariableEventHandler {(_this select 1) call HALV_server_savetextures;};

};