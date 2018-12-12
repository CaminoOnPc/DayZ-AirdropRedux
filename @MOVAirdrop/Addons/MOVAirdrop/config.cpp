// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVAirdropScripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"RPC_Scripts",
			"MOVNotificationScripts",
			"DZ_Data",
			"DZ_Structures_Residential"	
		};
	};
};
class CfgMods
{
	class MOVAirdrop
	{
	    dir = "MOVAirdrop";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "AirDrop Redux";
	    credits = "mov3ax, philipp";
	    author = "mov3ax, philipp";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"Mission", "World"};

	    class defs
	    {
			class worldScriptModule
            {
                value = "";
                files[] = {"airdrop/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"airdrop/scripts/5_Mission"};
            };
        };
    };
};
class CfgVehicles 
{
	class HouseNoDestruct;
	class AirDropPlane: HouseNoDestruct
	{
		scope=1;
		model="\DZ\structures\wrecks\Aircraft\Wreck_C130J.p3d";
	};
	class AirDropContainer: HouseNoDestruct
	{
		scope=1;
		model="\airdrop\container.p3d";
		/*
		displayName="AirDrop";
		descriptionShort="AirDrop container was recently dropped by a plane, may contain loot in it";	
		itemsCargoSize[]={10,60};
		openable=0;
		allowOwnedCargoManipulation=1;
		*/
	};
};
class CfgSoundShaders
{
	class BaseEngineAirPlane_SoundShader
	{
		rangeCurve = "defaultAmpAttenuationCurve";
		range = 2000;
	};
	class BaseAlarmAirPlane_SoundShader
	{
		rangeCurve = "defaultAmpAttenuationCurve";
		range = 1000;
	};
	class AirPlaneLoop_SoundShader: BaseEngineAirPlane_SoundShader
	{
		samples[] = {{"\airdrop\sounds\airplane",1}};
		volume = 1;
	};
	class AirPlaneAlarm_SoundShader: BaseAlarmAirPlane_SoundShader
	{
		samples[] = {{"\airdrop\sounds\alarm",1}};
		volume = 1;
	};
};
class CfgSoundSets
{
	class AirPlaneLoopBase_SoundSet
	{
		sound3DProcessingType = "VehicleExt_3DProcessingType";
		spatial = 1;
		doppler = 0;
		loop = 1;
	};
	class AirPlaneAlarmBase_SoundSet
	{
		sound3DProcessingType = "VehicleExt_3DProcessingType";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class AirPlaneLoop_SoundSet: AirPlaneLoopBase_SoundSet
	{
		soundShaders[] = {"AirPlaneLoop_SoundShader"};
	};
	class AirPlaneAlarm_SoundSet: AirPlaneAlarmBase_SoundSet
	{
		soundShaders[] = {"AirPlaneAlarm_SoundShader"};
	};
};