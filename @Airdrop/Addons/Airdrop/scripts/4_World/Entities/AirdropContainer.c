
class AirdropContainerBase extends House
{
	protected Particle m_ParticleEfx;
	protected Particle m_SmokeEfx;

	ref Timer m_Timer;
	ref AirdropSettings m_ActiveAirdropSettings;

	protected bool m_Loot;

	void AirdropContainerBase()
	{
		m_ActiveAirdropSettings = AirdropSettings.Load();

		RegisterNetSyncVariableBool("m_Loot");

		EOnInit();
	}
	
	void ~AirdropContainerBase()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();

		if (m_SmokeEfx)
			m_SmokeEfx.Stop();
			
		if (m_Timer) 
			m_Timer.Stop();
	}

	void EOnInit()
	{
		SetAnimationPhase("parachute", 0);

		vector m_TempPos = GetPosition();
		vector m_TempOri = GetOrientation();

		if (GetGame().IsClient() || !GetGame().IsMultiplayer()) 
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.AIRDROP_SMOKE, this, GetMemoryPointPos("light"));

		if (GetGame().IsServer()) 
		{
			SetOrientation(Vector(GetOrientation()[0], 0, 0));
			SetDirection(GetDirection());

			m_Timer = new Timer();
			m_Timer.Run(0.01, this, "AirdropContainerFall", NULL, true);
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 3600000, false, this);	
	}

	void EOnFall()
	{
		if (GetVelocity(this).Length() >= 0) 
		{
			CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM);
			EnableDynamicCCD(true);

			SetOrientation(Vector(GetOrientation()[0], 0, 0));
			SetVelocity(this, Vector(0, -2, 0));
		}
	}

	void EOnLand()
	{
		if (!m_Loot)
		{
			for (int ab = 0; ab < m_ActiveAirdropSettings.LootTiers.Count(); ab++) 
			{
				ref AirdropLoot LootTier = m_ActiveAirdropSettings.LootTiers.Get(ab);
				if (LootTier.Name == GetType()) 
				{
					for(int i = 0; i < m_ActiveAirdropSettings.Items; i++) 
					{
						vector dynamic_pos = GetPosition();
						dynamic_pos[0] = dynamic_pos[0] + (2.5 * Math.Cos(i));
						dynamic_pos[2] = dynamic_pos[2] + (2.5 * Math.Sin(i));
						dynamic_pos[1] = GetGame().SurfaceY(dynamic_pos[0], dynamic_pos[2]) + 0.3
						GetGame().CreateObject(LootTier.Loot.GetRandomElement(), dynamic_pos, false, true);
					}
				}
			}

			m_Loot = true;
			SetSynchDirty();
		}
			
		SetAnimationPhase("parachute", 1);	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( AirdropContainerUnstuck, 5000, false );
	}

	void AirdropContainerFall()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()) 
		{
			if (IsGround(1)) 
			{
				if (m_ParticleEfx)
					m_ParticleEfx.Stop();

				if (!m_SmokeEfx)
					m_SmokeEfx = Particle.PlayOnObject(ParticleList.AIRDROP_SMOKE2, this, GetMemoryPointPos("light"));
			}
		}

		if (GetGame().IsServer()) 
		{
			if (!IsGround(1)) 
				EOnFall();
			else 
				EOnLand();		
		}
	}

	void AirdropContainerUnstuck()
	{
		if (m_Timer)
			m_Timer.Stop();
		
		SetVelocity( this, Vector( 0, 0, 0 ) );

        dBodySetAngularVelocity( this, Vector( 0, 0, 0 ) );
        dBodyActive( this, ActiveState.INACTIVE );
        dBodyDynamic( this, false );
		
		SetDirection(GetDirection());
		SetOrientation(Vector(GetOrientation()[0], 0, 0));

		if (!IsObject())
		{
			PlaceOnSurface();
			SetPosition(Vector(GetPosition()[0], GetGame().SurfaceY(GetPosition()[0], GetPosition()[2]), GetPosition()[2]));	
		}
	}

	bool IsGround(float height)
	{
		vector m_Start = this.GetPosition();
		vector m_End = this.GetPosition() - Vector(0, height, 0);
		
		vector m_Hit;
		vector m_HitPos;
		
		int m_HitIndex;

		return DayZPhysics.RaycastRV(m_Start, m_End, m_HitPos, m_Hit, m_HitIndex, NULL, NULL, this);
	}

	bool IsObject()
	{
		set<Object> objects = new set<Object>;

		objects.Clear();

		vector m_Start = this.GetPosition();
		vector m_End = this.GetPosition() - Vector(0, 5, 0);
		
		vector m_Hit;
		vector m_HitPos;
		
		int m_HitIndex;

		DayZPhysics.RaycastRV(m_Start, m_End, m_HitPos, m_Hit, m_HitIndex, objects, NULL, this);

		return objects.Count() != 0;
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo ( EntityAI parent )
	{
		return false;
	}

	override bool IsInventoryVisible()
    {
        return true;
    }

	override bool CanUseConstruction()
    {
        return true;
    }
}