class AirDropContainerParticle extends House
{
	Particle m_ParticleEfx;
	
	void AirDropContainerParticle()
	{
		Print("<Airdrop> Particle created");
		m_ParticleEfx = Particle.Play(ParticleList.RDG2, this);
	}
	
	void ~AirDropContainerParticle()
	{
		Print("<Airdrop> Particle removed");
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}