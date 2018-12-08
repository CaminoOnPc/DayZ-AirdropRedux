modded class MissionServer
{
	ref AirDrop_Base m_Airdrop;
	
    void MissionServer()
    {
        m_Airdrop = new AirDrop_Base();
    }
}

modded class MissionGameplay
{
	ref AirDrop_Base m_Airdrop;
	
    void MissionGameplay()
    {
        m_Airdrop = new AirDrop_Base();
    }
}