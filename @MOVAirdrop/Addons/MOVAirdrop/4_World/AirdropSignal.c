class AirdropSignal : ItemGrenade
{
	Particle 				m_ParGreen;
	Particle 				m_ParOrange;
	Particle 				m_ParPurple;
	Particle 				m_ParRed;
	Particle 				m_ParWhite;
	
	static protected vector			m_FlameLocalPos = "0 0.28 0";
	
	int m_Color;
	
	// When the flare starts burning
	override void OnWorkStart()
	{
		if (m_Color == 0)
			m_ParGreen = Particle.Play(ParticleList.AIRDROP_GREEN, this, m_FlameLocalPos);
		if (m_Color == 1)
			m_ParGreen = Particle.Play(ParticleList.AIRDROP_ORANGE, this, m_FlameLocalPos);
		if (m_Color == 2)
			m_ParGreen = Particle.Play(ParticleList.AIRDROP_PURPLE, this, m_FlameLocalPos);
		if (m_Color == 3)
			m_ParGreen = Particle.Play(ParticleList.AIRDORP_RED, this, m_FlameLocalPos);
		if (m_Color == 4)
			m_ParGreen = Particle.Play(ParticleList.AIRDROP_WHITE, this, m_FlameLocalPos);
	}
	
	// When the flare stops burning
	override void OnWorkStop()
	{
		DestroyParticle( m_ParMainFire );
		
		Explode();
	}
	
	// Destroys the given particle
	void DestroyParticle( Particle p )
	{
		if (p)
		{
			p.Stop();
		}
	}
	
	// Inventory manipulation
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		if ( GetCompEM().IsWorking() )
		{
			vector ori_rotate = "180 0 0";
			vector ori_standing = ori_rotate + GetOrientation();
			SetOrientation(ori_standing);
		}
	}
}