class CfgMods
{
	class MOV_Airdrop
	{
	    dir = "MOV_Airdrop";
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

	    dependencies[] = {"Mission", "Game", "gui"};

	    class defs
	    {
			class missionScriptModule
            {
                value = "";
                files[] = {"airdrop/scripts/5_Mission"};
            };
        };
    };
};