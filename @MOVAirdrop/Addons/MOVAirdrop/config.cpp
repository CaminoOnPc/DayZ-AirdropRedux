// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVAirdropScripts
	{
		units[]={
			"AirDropContainer"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
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

	    dependencies[] = {"Mission", "Game", "World"};

	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"airdrop/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"airdrop/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"airdrop/5_Mission"};
            };
			
        };
    };
};
class CfgVehicles 
{
	class HouseNoDestruct;
	class AirDropContainer: HouseNoDestruct
	{
		scope=2;
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
			"\airdrop\airplane",
			1,
			1,
			2000
		};
	};
	class AirPlaneAlarm: default
	{
		sound[]=
		{
			"\airdrop\alarm",
			1,
			1,
			1000
		};
	};
};