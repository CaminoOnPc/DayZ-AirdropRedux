
class AirdropPlane extends House
{
	ref AirdropSettings m_ActiveAirdropSettings;
	ref AirdropPlaces m_ActiveAirdropPlaces;

	protected EffectSound m_Sound;

	protected bool m_Drop;
	protected float m_Angle;
	protected float m_Radius;
	protected vector m_Location;
	
	bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) 
	{
		if ( x > min_x && x < max_x && y > min_y && y < max_y ) return true;
		return false;
	}

	void SetupRandom(ref AirdropPlaces activeAirdropPlaces)
	{
		m_ActiveAirdropPlaces = activeAirdropPlaces;

		m_Location = Vector(m_ActiveAirdropPlaces.x, 0, m_ActiveAirdropPlaces.y);
		m_Radius = m_ActiveAirdropPlaces.Radius;

		vector position = GetPosition();
		m_Angle = Math.Atan2( m_ActiveAirdropPlaces.y - position[2], m_ActiveAirdropPlaces.x - position[0] );
	}

	void SetupPlayer(vector location)
	{
		m_ActiveAirdropPlaces = null;

		m_Location = location;
		m_Radius = 50;

		vector position = GetPosition();
		m_Angle = Math.Atan2( location[2] - position[2], location[0] - position[0] );
	}

	void AirdropPlane()
	{	
		m_ActiveAirdropSettings = AirdropSettings.Load();

		SetEventMask( EntityEvent.CONTACT | EntityEvent.SIMULATE );

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
		if (GetGame()) 
		{
			if (GetGame().GetPlayer()) 
			{
				PlaySoundLoop("c130j_loop_int", 1000);
			}
		}
	}

	override void EOnSimulate( IEntity owner, float dt )
	{
		if ( GetGame().IsServer() )
		{
			vector position = GetPosition();

			vector velocity = Vector( Math.Cos( m_Angle ), 0, Math.Sin( m_Angle ) );

			velocity[0] = velocity[0] * (m_ActiveAirdropSettings.Speed * 10) * dt;
			velocity[2] = velocity[2] * (m_ActiveAirdropSettings.Speed * 10) * dt;

			vector transform[4];
			GetTransform( transform );
			transform[3] = transform[3] + velocity;
			transform[3][1] = GetGame().SurfaceY(GetPosition()[0], GetPosition()[2]) + m_ActiveAirdropSettings.Height;

			MoveInTime( transform, dt );

			EOnBeforeDrop();
			EOnBeforeDelete();
		}
	}

	void EOnBeforeDelete()
	{
		vector position = GetPosition();
		if ( !IsInRect( position[0], position[2], -10.0, 15470.0, -10.0, 15470.0 ) )
		{
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().ObjectDelete, 0, false, this );
		}
	}

	void EOnBeforeDrop()
	{
		float dist = Math.Sqrt(Math.Pow(m_Location[0] - GetPosition()[0], 2) + Math.Pow(m_Location[2] - GetPosition()[2], 2));
		if (dist <= Math.RandomFloat(0, m_Radius)) 
		{
			if (!m_Drop)
			{
				EOnDrop();
				m_Drop = true;
			}
		}
	}

	void EOnDrop()
	{
		House drop = House.Cast( GetGame().CreateObject( m_ActiveAirdropSettings.AirdropContainers.GetRandomElement(), Vector( GetPosition()[0], GetPosition()[1] - 10, GetPosition()[2]) ));	
		drop.SetPosition(Vector( GetPosition()[0], GetPosition()[1] - 10, GetPosition()[2]));	
		drop.SetOrientation(Vector(0, 0, 0));

		for ( int z = 0; z < m_ActiveAirdropSettings.Infected; z++ ) 
		{
			GetGame().CreateObject( m_ActiveAirdropSettings.AirdropZombies.GetRandomElement(), Vector(drop.GetPosition()[0] + Math.RandomFloat(-50.0, 50.0), 0, drop.GetPosition()[2] + Math.RandomFloat(-50.0, 50.0)), false, true);
		}

		if (m_ActiveAirdropPlaces)
		{
			SendMessage("The supplies have been dropped around " + m_ActiveAirdropPlaces.Name);
		}
	}

	void SendMessage(string message)
	{
		if (m_ActiveAirdropSettings.Message == 0) 
		{
			GetNotificationSystem().CreateNotification_Old("Airdrop", message, ARGB(255, 221, 38, 38), 10);	
		}
		if (m_ActiveAirdropSettings.Message == 1)
		{
			ref array<Man> players = new array<Man>;
			GetGame().GetPlayers( players );
			foreach( auto player : players  )
			{
				Param1<string> m_MessageParam = new Param1<string>(message);
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
			}
		}
	}
}