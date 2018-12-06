// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVAirdropScripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"MOVNotificationFramework",
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