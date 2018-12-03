// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class Airdrop_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Structures_Residential"	
		};
	};
};
class CfgVehicles 
{
	class HouseNoDestruct;
	class DropBox: HouseNoDestruct
	{
		scope=1;
		model="\DZ\structures\residential\Misc\Misc_BoxWooden.p3d";
	};
};
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class airplaneLoop: default
	{
		sound[]=
		{
			"\DZ\sounds\vehicles\v3s\v3s_Engine_Ext_Rpm0",
			0.63095737,
			1,
			1000
		};
	};
};
class CfgMods
{
	class Airdrop
	{
	    dir = "Airdrop";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Airdrop Redux";
	    credits = "philipp";
	    author = "mov3ax";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"Mission", "Game"};

	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"airdrop/3_Game"};
            };
			
	        class missionScriptModule
            {
                value = "";
                files[] = {"airdrop/5_Mission"};
            };
        };
    };
};