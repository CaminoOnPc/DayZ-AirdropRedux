class AirDropContainer extends House
{
	Particle m_ParticleEfx;
	Particle m_ParticleLoc;
	House m_Object;

	void AirDropContainer()
	{
		m_ParticleLoc = Particle.Play(ParticleList.PARTICLE_TEST, this);
		vector m_Position = m_ParticleLoc.GetPosition();
		Print("<Airdrop> Container created");
		m_Object = GetGame().CreateObject("House", m_Position, true);
		m_ParticleEfx.Play(ParticleList.RDG2, m_Object).SetPosition(m_Position);
		m_ParticleLoc.Stop();
	}
	
	void ~AirDropContainer()
	{
		Print("<Airdrop> Container removed");
		if ( m_ParticleEfx )
			m_ParticleEfx.Stop();
		if ( m_Object )
			GetGame().ObjectDelete(m_Object);
	}
}