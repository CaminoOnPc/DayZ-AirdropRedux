
class AirdropCustomBase
{
	float m_ProximityDist = 1500.0;

	bool m_ProximityWarning = false;

	bool m_MovePlane = false;

	bool m_MoveDrop = false;

	vector m_PlaneSpawn;

	vector m_PlanePos;
	
	vector m_DropSpawn;

	ref Timer m_MoveTimer;

	ref Timer m_SpawnTimer;

	House m_Plane;

	House m_Drop;

	ref AirdropPlaces m_ActiveAirdropPlaces;

	ref AirdropSettings m_ActiveAirdropSettings;

	//! Contructor
	
	void AirdropCustomBase() 
	{	
		Print("[Airdrop] Custom class created");

		m_ActiveAirdropSettings = AirdropSettings.Load();

		OnResetPlane();

		m_MoveTimer = new Timer();

		m_MoveTimer.Run(m_ActiveAirdropSettings.Update, this, "OnMovePlane", NULL, true);
	}

	void ~AirdropCustomBase() 
	{
		Print("[Airdrop] Custom class destroyed");

		OnResetPlane();

		m_MoveTimer.Stop();
	}

	//! Dynamic Airdrop events

	void OnSpawnPlane(float x, float y)
	{
		Print("[Airdrop] Plane spawned");

		m_ActiveAirdropPlaces = m_ActiveAirdropSettings.DropLocations.GetRandomElement();

		switch(Math.RandomInt(0,4)) {
            case 0: {
                m_PlaneSpawn[0] = 0.0;
                m_PlaneSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 1: {
                m_PlaneSpawn[0] = 15360.0;
                m_PlaneSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 2: {
                m_PlaneSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                m_PlaneSpawn[2] = 0.0;
                break;
            }
            case 3: {
                m_PlaneSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                m_PlaneSpawn[2] = 15360.0;
                break;
            }
        }

		m_DropSpawn[0] = x;
		m_DropSpawn[2] = y;

        m_Plane.SetDirection(m_PlaneSpawn - m_DropSpawn);
		m_Plane.SetPosition(m_PlaneSpawn); 

		m_MovePlane = true;

		SendMessage("The airplane is heading towards player"); 
	}

	void OnResetPlane()
	{
		Print("[Airdrop] Plane destroyed");

		if (m_Plane) {
			if (GetGame()) {
				GetGame().ObjectDelete(m_Plane);
			}	
		}
		
		m_Plane = House.Cast( GetGame().CreateObject( "AirdropPlane", Vector(0, 0, 0), false, true, true) );

		m_MoveDrop = false;
	}

	void OnDrop()
	{
		Print("[Airdrop] Drop spawned");

        m_Drop = House.Cast( GetGame().CreateObject( m_ActiveAirdropSettings.AirdropContainers.GetRandomElement(), m_Plane.GetPosition() + Vector(0, -10, 0)) );	
		m_Drop.SetPosition(m_Plane.GetPosition() + Vector(0, -10, 0));

		for (int a = 0; a < m_ActiveAirdropSettings.LootTiers.Count(); a++) {
			ref AirdropLoot LootTier = m_ActiveAirdropSettings.LootTiers.Get(a);
			if (LootTier.Name == m_Drop.GetType()) {
				for(int i = 0; i < m_ActiveAirdropSettings.Items; i++) {
					m_Drop.GetInventory().CreateInInventory(LootTier.Loot.GetRandomElement());
				}
			}
		}

		for ( int z = 0; z < m_ActiveAirdropSettings.Infected; z++ ) {
			GetGame().CreateObject( m_ActiveAirdropSettings.AirdropZombies.GetRandomElement(), Vector(m_Drop.GetPosition()[0] + Math.RandomFloat(-20.0, 20.0), 0, m_Drop.GetPosition()[2] + Math.RandomFloat(-20.0, 20.0)), false, true);
		}
	}

	void OnMovePlane()
	{
		if (m_MovePlane) {
			float m_Angle = Math.Atan2(m_DropSpawn[2] - m_PlaneSpawn[2], m_DropSpawn[0] - m_PlaneSpawn[0]);

			m_PlanePos[0] = Math.Cos(m_Angle);
       		m_PlanePos[2] = Math.Sin(m_Angle);

			vector m_PlanePosition = m_Plane.GetPosition() + (m_PlanePos * (m_ActiveAirdropSettings.Speed / 2));
			m_PlanePosition[1] = GetGame().SurfaceY(m_PlanePosition[0], m_PlanePosition[2]) + m_ActiveAirdropSettings.Height;

			m_Plane.SetPosition(m_PlanePosition);	

			if(!m_MoveDrop) {
				float m_Dist = Math.Sqrt(Math.Pow(m_DropSpawn[0] - m_PlanePosition[0], 2) + Math.Pow(m_DropSpawn[2] - m_PlanePosition[2], 2));
				if(m_Dist <= Math.RandomFloat(0, m_ActiveAirdropPlaces.Radius)) {
					OnDrop();
					SendMessage("The supplies have been dropped around player");
					m_MoveDrop = true;	
				}
			}
			else if (m_Dist <= m_ProximityDist && !m_ProximityWarning) 
			{
				m_ProximityWarning = true;
				SendMessage("The plane is closing in on player");	
			}
		}
		else {
            if(!IsInRect(m_PlanePosition[0], m_PlanePosition[2], -10.0, 15470.0, -10.0, 1570.0)) {
                OnResetPlane();
				m_MovePlane = false;
            }
        }
	}

	//! Checks
	
	private bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) {
        if(x > min_x && x < max_x && y > min_y && y < max_y) return true;
        return false;
    }

	//! Anouncing

	private void SendChatMessage(string message)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		foreach( auto player : players  )
		{
			Param1<string> m_MessageParam = new Param1<string>(message);
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
		}
	}

	private void SendMessage(string message)
	{
		if (m_ActiveAirdropSettings.Message == 0) 
			GetToastNotificationSystem().ShowToast("Airdrop", message, "InfoMessage", 10000);	
		if (m_ActiveAirdropSettings.Message == 1)
			SendChatMessage("(Airdrop) " + message);
	}
}

static ref AirdropCustomBase g_AirdropCustomBase;
static ref AirdropCustomBase GetAirdropCustomBase()
{
    if ( !g_AirdropCustomBase )
    {
         g_AirdropCustomBase = new ref AirdropCustomBase();
    }
    
    return g_AirdropCustomBase;
}