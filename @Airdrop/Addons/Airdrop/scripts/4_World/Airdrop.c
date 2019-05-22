
class AirdropPlaces
{
    float x, y;
    string Name;
    float Radius;

    void AirdropPlaces(float xx, float yy, float radius, string name) 
	{
		Print("[Airdrop] Places class created");

        x = xx;
        y = yy;
        Radius = radius;
        Name = name;
    }
}

class AirdropLoot
{
    string Name;
    ref TStringArray Loot;

    void AirdropLoot( string name, ref TStringArray loot )
    {
		Print("[Airdrop] Loot class created");

        Name = name;
        Loot = loot;
    }
}

class AirdropSettings
{
	float Interval; 
	float Update;

	int Items;
	int Infected;
	int Message;

	float Speed;
	float Height; 

	ref TStringArray AirdropContainers;

	ref TStringArray AirdropZombies;
	
	ref array< ref AirdropPlaces > DropLocations;

    ref array< ref AirdropLoot > LootTiers;

	void AirdropSettings()
	{
		Print("[Airdrop] Settings class created");

		DropLocations = new ref array< ref AirdropPlaces >;
		LootTiers = new ref array< ref AirdropLoot >;

		AirdropContainers = new ref TStringArray;
		AirdropZombies = new ref TStringArray;
	}
	
	void AirdropDefaults()
	{
		Interval = 60.0;
       	Update = 0.01;
       	Items = 20;
        Infected = 15;
		Message = 0;
    
        Speed = 1.0;
        Height = 500.0;
		
		DropLocations.Insert( new ref AirdropPlaces(4807, 9812, 100, "northwest airfield") );
		DropLocations.Insert( new ref AirdropPlaces(11464, 8908, 100, "berezino") );
		DropLocations.Insert( new ref AirdropPlaces(12159, 12583, 100, "krasnostav") );
		DropLocations.Insert( new ref AirdropPlaces(5043, 2505, 100, "balota") );
		DropLocations.Insert( new ref AirdropPlaces(2351, 5393, 100, "zelenogorks") );
		DropLocations.Insert( new ref AirdropPlaces(2036, 7491, 100, "myshkino") );
		DropLocations.Insert( new ref AirdropPlaces(11125, 14040, 100, "novodmitrovsk") );
		DropLocations.Insert( new ref AirdropPlaces(6128, 2497, 100, "chernogorks") );
		DropLocations.Insert( new ref AirdropPlaces(9371, 2229, 100, "elektrozavodsk") );
		DropLocations.Insert( new ref AirdropPlaces(13452, 3112, 100, "skalisty island") );
		DropLocations.Insert( new ref AirdropPlaces(2700, 6193, 100, "sosnovka") );
		DropLocations.Insert( new ref AirdropPlaces(7436, 7720, 100, "novy sobor") );
		DropLocations.Insert( new ref AirdropPlaces(5823, 7764, 100, "stary sobor") );

		AirdropContainers.Insert( "AirdropContainer_Medical" );
		AirdropContainers.Insert( "AirdropContainer_Military" );
		AirdropContainers.Insert( "AirdropContainer" );

		AirdropZombies.Insert( "ZmbM_HermitSkinny_Base" );
		AirdropZombies.Insert( "ZmbM_HermitSkinny_Beige" );
		AirdropZombies.Insert( "ZmbM_HermitSkinny_Black" );
		AirdropZombies.Insert( "ZmbM_HermitSkinny_Green" );
		AirdropZombies.Insert( "ZmbM_HermitSkinny_Red" );
		AirdropZombies.Insert( "ZmbM_FarmerFat_Base" );
		AirdropZombies.Insert( "ZmbM_FarmerFat_Beige" );
		AirdropZombies.Insert( "ZmbM_FarmerFat_Blue" );
		AirdropZombies.Insert( "ZmbM_FarmerFat_Brown" );
		AirdropZombies.Insert( "ZmbM_FarmerFat_Green" );
		AirdropZombies.Insert( "ZmbF_CitizenANormal_Base" );
		AirdropZombies.Insert( "ZmbF_CitizenANormal_Beige" );
		AirdropZombies.Insert( "ZmbF_CitizenANormal_Brown" );
		AirdropZombies.Insert( "ZmbF_CitizenANormal_Blue" );

		LootTiers.Insert( new ref AirdropLoot("AirdropContainer", {
        "Izh18",
        "Mossin9130",
        "AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
        "M4A1",
        "BakedBeansCan",
        "WaterBottle",
        "FNX45",
        "Mag_STANAG_30Rnd",
        "AKM",
        "Mag_AKM_30Rnd",
        "Rice",
        "PowderedMilk",
        "Vodka",
        }));

		LootTiers.Insert( new ref AirdropLoot("AirdropContainer_Medical", {
        "Canteen",
        "PowderedMilk",
        "Marmalade",
        "BakedBeansCan",
        "PeachesCan",
        "SpaghettiCan",
        "TunaCan",
        "Pot",
        "VitaminBottle",
        "BoxCerealCrunchin",
        "TacticalBaconCan",
        }));

        LootTiers.Insert( new ref AirdropLoot("AirdropContainer_Military", {
        "LandMineTrap",
        "TTSKOPants",
        "TacticalBaconCan",
        "M4A1",
        "PlateCarrierComplete",
        "MilitaryBoots_Redpunk",
        "CombatBoots_Grey",
        "FNX45",
        "Mag_STANAG_30Rnd",
        "AKM",
        "Mag_AKM_30Rnd",
        "LargeTent",
        "Izh18",
        "Mosin9130",
        "Mosin_Bayonet",
        "Mosin_Compensator",
        "AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
        }));

		if ( !FileExist( JSON_PATH_DIRECTORY_SETTINGS ) )
		{
			MakeDirectory( JSON_PATH_DIRECTORY_SETTINGS );
		}

		JsonFileLoader<AirdropSettings>.JsonSaveFile( JSON_PATH_SETTINGS, this );
	}

	static ref AirdropSettings Load()
	{
		ref AirdropSettings settings = new AirdropSettings();

		if ( FileExist( JSON_PATH_SETTINGS ) )
		{
			JsonFileLoader<AirdropSettings>.JsonLoadFile( JSON_PATH_SETTINGS, settings );
		} 
		else 
		{
			settings.AirdropDefaults();
		}

		return settings;
	}
}

class AirdropBase
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
	
	void AirdropBase() 
	{	
		Print("[Airdrop] Base class created");

		m_ActiveAirdropSettings = AirdropSettings.Load();

		OnResetPlane();

		m_MoveTimer = new Timer();
		m_SpawnTimer = new Timer();

		m_MoveTimer.Run(m_ActiveAirdropSettings.Update, this, "OnMovePlane", NULL, true);
		m_SpawnTimer.Run(m_ActiveAirdropSettings.Interval * 60, this, "OnSpawnPlane", NULL, true);
	}

	void ~AirdropBase() 
	{
		Print("[Airdrop] Base class destroyed");

		OnResetPlane();

		m_MoveTimer.Stop();
		m_SpawnTimer.Stop();
	}

	//! Dynamic Airdrop events

	void OnSpawnPlane()
	{
		Print("[Airdrop] Plane spawned");

		OnResetPlane();

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

		m_DropSpawn[0] = m_ActiveAirdropPlaces.x;
		m_DropSpawn[2] = m_ActiveAirdropPlaces.y;

		m_Plane.SetOrientation(Vector(0, 0, 0)); 
        m_Plane.SetDirection(m_PlaneSpawn - m_DropSpawn);	
		m_Plane.SetPosition(m_PlaneSpawn); 
		
		m_MovePlane = true;

		SendMessage("The airplane is heading towards " + m_ActiveAirdropPlaces.Name); 
	}

	void OnResetPlane()
	{
		m_MoveDrop = false;

		Print("[Airdrop] Plane destroyed");

		if (m_Plane) {
			GetGame().ObjectDelete(m_Plane);
		}
		
		if (GetGame())
			m_Plane = House.Cast( GetGame().CreateObject( "AirdropPlane", Vector(0, 0, 0), false, true, true) );
	}

	void OnDrop()
	{
		Print("[Airdrop] Drop spawned");

        m_Drop = House.Cast( GetGame().CreateObject( m_ActiveAirdropSettings.AirdropContainers.GetRandomElement(), m_Plane.GetPosition() + Vector(0, -10, 0)) );	
		m_Drop.SetPosition(m_Plane.GetPosition() + Vector(0, -10, 0));
		m_Drop.SetOrientation(Vector(0, 0, 0));

		Print("" + m_Drop + " [" + m_Drop.GetPosition() + "]");

		for (int a = 0; a < m_ActiveAirdropSettings.LootTiers.Count(); a++) {
			ref AirdropLoot LootTier = m_ActiveAirdropSettings.LootTiers.Get(a);
			if (LootTier.Name == m_Drop.GetType()) {
				Print("[Airdrop] Tier selected");
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
					Print("[Airdrop] Drop dropped at " + m_ActiveAirdropPlaces.Name);
					OnDrop();
					SendMessage("The supplies have been dropped around " + m_ActiveAirdropPlaces.Name);
					m_MoveDrop = true;		
				}
			}
			else if (m_Dist <= m_ProximityDist && !m_ProximityWarning) 
			{
				m_ProximityWarning = true;
				SendMessage("The plane is closing in on " + m_ActiveAirdropPlaces.Name);	
			}
		}
		if (m_MoveDrop) {
			if(IsInRect(m_PlanePosition[0], m_PlanePosition[2], 15470.0, 15470.0)) {
				Print("[Airdrop] Plane out of range");
                OnResetPlane();
				m_MovePlane = false;
            }
		}
	}

	//! Checks
	
	private bool IsInRect(float x, float z, float max_x, float max_z) {
        if(Math.AbsFloat(x) > max_x || Math.AbsFloat(z) > max_z) return true;
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

static ref AirdropBase g_AirdropBase;
static ref AirdropBase GetAirdropBase()
{
    if ( !g_AirdropBase )
    {
         g_AirdropBase = new ref AirdropBase();
    }
    
    return g_AirdropBase;
}