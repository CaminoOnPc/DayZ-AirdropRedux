class AirdropFlare : ItemGrenade
{
	protected SoundOnVehicle		m_LoopSoundEntity;

	protected Particle 				m_ParMainFire;
	
    protected ref AirdropCustomBase f_AirdropBase;

	protected bool m_Executed;

	void AirdropFlare()
	{
		RegisterNetSyncVariableFloat("m_EM.m_Energy"); 
	}

	void ~AirdropFlare()
	{
		if ( GetGame() )
		{
			if ( m_LoopSoundEntity != NULL )
			{
				GetGame().ObjectDelete( m_LoopSoundEntity );
			}

			if ( m_ParMainFire != NULL )
			{
				DestroyParticle(m_ParMainFire);
			}
		}
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		if( !m_Executed )
		{
			return true;
		}
		return false;
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands(parent) ) {return false;}
		if( !m_Executed )
		{
			return true;
		}
		return false;
	}
	
	override void OnWorkStart()
	{
		m_Executed = true;
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer())
		{
			m_LoopSoundEntity = PlaySoundLoop("roadflareLoop", 30);
			m_ParMainFire = Particle.PlayOnObject(ParticleList.RDG2, this, "0 0.28 0");
		}
        if ( GetGame().IsServer() )
		{
            if (f_AirdropBase) {
				f_AirdropBase = null;
			}

			f_AirdropBase = new ref AirdropCustomBase();
			f_AirdropBase.OnSpawnPlane(GetPosition()[0], GetPosition()[2]);
        }
	}
	
	override void OnWorkStop()
	{
		DestroyParticle( m_ParMainFire );
		
		if ( m_LoopSoundEntity != NULL )
		{
			GetGame().ObjectDelete( m_LoopSoundEntity );
		}
	}
	
	void DestroyParticle( Particle p )
	{
		if (p)
		{
			p.Stop();
		}
	}
	
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
	
	override void OnActivatedByTripWire()
	{
		GetCompEM().SwitchOn();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTurnOnWhileInHands);
	}
};
