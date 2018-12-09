// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVAirdropScripts
	{
		units[]={};
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

	    dependencies[] = {"Mission"};

	    class defs
	    {
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
	class Inventory_Base;
	class AirDropContainer: Inventory_Base
	{
		scope=2;
		displayName="AirDrop";
		descriptionShort="AirDrop container was recently dropped by a plane, may contain loot in it";
		model="\airdrop\container.p3d";
		class Cargo
		{
			itemsCargoSize[]={10,60};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
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