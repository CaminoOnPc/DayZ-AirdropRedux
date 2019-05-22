
modded class MissionServer
{
    void MissionServer()
    {
        if (GetGame().IsServer()) 
        {
		    g_AirdropBase = null;
            GetAirdropBase();
        }
    }
}

modded class MissionGameplay
{
    void MissionGameplay()
    {
        if (GetGame().IsServer()) 
        {
            g_AirdropBase = null;
            GetAirdropBase();
        }	
    }
}