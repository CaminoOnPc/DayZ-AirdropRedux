// #include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class MOVNotificationScripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"RPC_Scripts",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class MOVNotificationFramework
	{
	    dir = "MOVNotificationFramework";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Notification Framework";
	    credits = "mov3ax";
	    author = "mov3ax";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = { "World", "Mission" };

	    class defs
	    {
			class worldScriptModule
            {
                value = "";
                files[] = {"mov/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"mov/scripts/5_Mission"};
            };
        };
    };
};