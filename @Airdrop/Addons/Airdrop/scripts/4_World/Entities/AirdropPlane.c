
class AirdropPlane extends House
{
	EffectSound m_Sound;
	
	void AirdropPlane()
	{	
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
			PlayLoop();
	}
	
	void ~AirdropPlane()
	{
		if (m_Sound)
			m_Sound.Stop();
	}
	
	void PlayLoop()
	{
		if (GetGame()) {
			if (GetGame().GetPlayer()) {
				/*
				//! Not working right because netsync sucks 
				PlaySoundSetLoop(m_Sound, "c130j_loop_int_SoundSet", 0, 0);
				*/
				PlaySoundLoop("c130j_loop_int", 1000);
			}
		}
	}
}