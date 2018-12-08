modded class MissionServer
{
	ref AirDrop_Base m_Airdrop;
	
    void MissionServer()
    {
		Print("<AirDrop> MissionServer::MissionServer()");
		
		m_Airdrop = null;
        m_Airdrop = new AirDrop_Base();
    }
}

modded class MissionGameplay
{
	ref AirDrop_Base m_Airdrop;
	
    void MissionGameplay()
    {
		Print("<AirDrop> MissionGameplay::MissionGameplay()");
		
		m_Airdrop = null;
        m_Airdrop = new AirDrop_Base();
    }
}