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
	    dir = "[MOV] Airdrop Redux";
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

	    dependencies[] = {"Mission", "World", "Game"};

	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"airdrop/scripts/3_Game"};
            };
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
	class AirDropContainer_Physical: HouseNoDestruct
	{
		scope=1;
		model="\airdrop\container.p3d";
	};
};
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class AirPlaneLoop: default
	{
		sound[]=
		{
			"\airdrop\sounds\airplane",
			1,
			1,
			2000
		};
	};
	class AirPlaneAlarm: default
	{
		sound[]=
		{
			"\airdrop\sounds\alarm",
			1,
			1,
			1000
		};
	};
};