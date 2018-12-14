class AirDropContainer extends House
{
	Particle m_ParticleEfx;
	House m_Object;
	void AirDropContainer()
	{
		vector m_Position = GetWorldPosition();
		Print("<Airdrop> Container created at " + m_Position);
		
		Print("<Airdrop> Container created");
		m_Object = GetGame().CreateObject("House", m_Position, true);
		m_ParticleEfx.Play(ParticleList.RDG2, m_Object).SetPosition(m_Position);
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