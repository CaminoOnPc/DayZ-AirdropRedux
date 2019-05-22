
class AirdropContainerBase extends House
{
	private ref Timer m_Timer;

	private House m_Particle;

	private bool IsGround(float height)
	{
		vector m_Start = this.GetPosition();
		vector m_End = this.GetPosition() - Vector(0, height, 0);
		
		vector m_Hit;
		vector m_HitPos;
		
		int m_HitIndex;

		return DayZPhysics.RaycastRV(m_Start, m_End, m_HitPos, m_Hit, m_HitIndex, NULL, NULL, this);
	}
	
	override void EOnInit( IEntity other, int extra)
	{
		SetAnimationPhase("parachute", 0);

		vector m_TempPos = GetPosition();
		vector m_TempOri = GetOrientation();

		if (GetGame().IsServer()) {
			SetOrientation(Vector(0, 0, 0));
			SetDirection(GetDirection());
				
			m_Particle = House.Cast(GetGame().CreateObject( "AirdropContainerParticle", ModelToWorld(GetMemoryPointPos("light")), false, true));
			m_Particle.SetPosition(WorldToModel(m_Particle.GetPosition()));
			m_Particle.SetOrientation(Vector(0, 0, 0));
			AddChild(m_Particle, 0);

			m_Timer = new Timer();
			m_Timer.Run(0.01, this, "AirdropContainerFall", NULL, true);
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 3600000, false, this);	
	}

	void AirdropContainerFall()
	{
		if (GetGame().IsServer()) {
			autoptr PhysicsGeomDef geoms[] = {PhysicsGeomDef("", dGeomCreateBox(Vector(1, 8.55, 1)), "material/default", 0xffffffff)};
			if (!IsGround(5)) {
				if (GetVelocity(this).Length() >= 0) {

					dBodyDestroy( this );	
					dBodyCreateDynamicEx( this, "0 0 0", 1, geoms );

					SetVelocity(this, Vector(0, -2, 0));
				}
			}	
			else {
				SetAnimationPhase("parachute", 1);	

				if (!dBodyIsSet( this )) {
					dBodyDestroy( this );	
					dBodyCreateDynamicEx( this, "0 0 0", 1, geoms );
				}

				//! Uncomment me when VicinityItemManager will be fixed
				//! m_Timer.Stop();
			}		
		}
	}

	void AirdropContainerBase()
	{
		SetEventMask(EntityEvent.INIT);
	}
	
	void ~AirdropContainerBase()
	{
		if ( GetGame() )
		{
			if ( m_Particle != NULL )
			{
				GetGame().ObjectDelete( m_Particle );
			}
		}

		if (m_Timer) 
		{
			m_Timer.Stop();
			delete m_Timer;
		}
	}

	override bool IsInventoryVisible()
    {
        return true;
    }

	override bool CanUseConstruction()
    {
        return true;
    }

	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	override bool CanPutInCargo ( EntityAI parent )
	{
		return false;
	}
}