modded class MissionServer extends MissionBase
{
	ref AirDrop_Base Airdrop;
	
	void MissionServer()
	{
		Airdrop = new AirDrop_Base();
	}
}