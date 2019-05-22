
class AirdropContainerParticle extends House
{
	Particle m_ParticleEfx;
	
	void AirdropContainerParticle()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.AIRDROP_SMOKE, this);
	}
	
	void ~AirdropContainerParticle()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}