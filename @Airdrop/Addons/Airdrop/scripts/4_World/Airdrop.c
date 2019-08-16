
class AirdropPlaces
{
    float x, y;
    string Name;
    float Radius;

    void AirdropPlaces(float xx, float yy, float radius, string name) 
	{
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
        Name = name;
        Loot = loot;
    }
}

class AirdropSettings
{
	float Interval; 

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
		DropLocations = new ref array< ref AirdropPlaces >;
		LootTiers = new ref array< ref AirdropLoot >;

		AirdropContainers = new ref TStringArray;
		AirdropZombies = new ref TStringArray;
	}
	
	void AirdropDefaults()
	{
		Interval = 60.0;
       	Items = 20;
        Infected = 20;
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
        "Mosin9130",
		"SawedoffMosin9130",
		"CZ527",
		"CZ61",
		"SKS",
		"Mosin_Bayonet",
		"Mosin_Compensator",
        "AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
		"PUScopeOptic",
		"SKS_Bayonet",
		"PlateCarrierPouches",
		"PlateCarrierVest",
		"PlateCarrierHolster",
        }));

		LootTiers.Insert( new ref AirdropLoot("AirdropContainer_Medical", {
        "Canteen",
		"BandageDressing",
		"Morphine",
		"Epinephrine",
		"TacticalBaconCan",
		"VitaminBottle",
		"PainkillerTablets",
		"CharcoalTablets",
		"FNX45",
		"Mag_FNX45_15Rnd",
		"Ammo_45ACP",
		"AmmoBox_45ACP_25rnd",
		"PistolSuppresor",
        }));

        LootTiers.Insert( new ref AirdropLoot("AirdropContainer_Military", {
		"M4A1",
		"AKM",
		"M4A1",
		"AKM",
		"M4A1",
		"AKM",
		"M4_Suppressor",
		"M4_CarryHandleOptic",
		"BUISOptic",
		"M68Optic",
		"M4_T3NRDSOptic",
		"ReflexOptic",
		"ACOGOptic",
		"M4_OEBttstck",
		"M4_MPBttstck",
		"M4_CQBBttstck",
		"M4_PlasticHndgrd",
		"M4_RISHndgrd",
		"M4_MPHndgrd",
		"KashtanOptic",
		"GrozaOptic",
		"KobraOptic",
		"AK_Bayonet",
		"AK_Suppressor",
		"AK_WoodBttstck",
		"AK_FoldingBttstck",
		"AK_PlasticBttstck",
		"AK_WoodHndgrd",
		"AK_RailHndgrd",
		"AK_PlasticHndgrd",
		"RGD2Grenade",
		"M67Grenade",
		"M18SmokeGrenade_Red",
		"M18SmokeGrenade_Green",
		"M18SmokeGrenade_Yellow",
		"M18SmokeGrenade_Purple",
		"M18SmokeGrenade_White",
		"LandMineTrap",
		"PlateCarrierPouches",
		"PlateCarrierVest",
		"PlateCarrierHolster",
        "Mag_STANAG_30Rnd",
		"Mag_AKM_30Rnd",
		"AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
		"Mag_STANAG_30Rnd",
		"Mag_AKM_30Rnd",
		"AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
		"Mag_STANAG_30Rnd",
		"Mag_AKM_30Rnd",
		"AmmoBox_762x54_20Rnd",
        "AmmoBox_762x39_20Rnd",
        }));

		if ( !FileExist( JSON_PATH_DIRECTORY_SETTINGS_AIRDROP ) )
		{
			MakeDirectory( JSON_PATH_DIRECTORY_SETTINGS_AIRDROP );
		}

		JsonFileLoader<AirdropSettings>.JsonSaveFile( JSON_PATH_SETTINGS_AIRDROP, this );
	}

	static ref AirdropSettings Load()
	{
		ref AirdropSettings settings = new AirdropSettings();

		if ( FileExist( JSON_PATH_SETTINGS_AIRDROP ) )
		{
			JsonFileLoader<AirdropSettings>.JsonLoadFile( JSON_PATH_SETTINGS_AIRDROP, settings );
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
	protected ref array< AirdropPlane > m_Planes;

	ref AirdropSettings m_ActiveAirdropSettings;
	ref AirdropPlaces m_ActiveAirdropPlaces;
	
	protected ref Timer m_SpawnTimer;

	void AirdropBase()
	{
		m_Planes = new array< AirdropPlane >;

		m_ActiveAirdropSettings = AirdropSettings.Load();
		m_ActiveAirdropPlaces = m_ActiveAirdropSettings.DropLocations.GetRandomElement();

		m_SpawnTimer = new Timer();
		m_SpawnTimer.Run(m_ActiveAirdropSettings.Interval * 60, this, "EOnRandomDrop", NULL, true);
	}

	void EOnRandomDrop()
	{
		m_ActiveAirdropPlaces = m_ActiveAirdropSettings.DropLocations.GetRandomElement();

		vector planeSpawn;
		switch(Math.RandomInt(0,4)) 
		{
            case 0: 
			{
                planeSpawn[0] = 0.0;
                planeSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 1: 
			{
                planeSpawn[0] = 15360.0;
                planeSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 2: 
			{
                planeSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                planeSpawn[2] = 0.0;
                break;
            }
            case 3: 
			{
                planeSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                planeSpawn[2] = 15360.0;
                break;
            }
        }

		AirdropPlane plane = AirdropPlane.Cast( GetGame().CreateObject( "AirdropPlane", planeSpawn, false, true, true) );
		plane.SetPosition(planeSpawn); 
		if (plane)
		{
			m_Planes.Insert( plane );
		}

		vector dropSpawn;
		dropSpawn[0] = m_ActiveAirdropPlaces.x;
		dropSpawn[2] = m_ActiveAirdropPlaces.y;

		plane.SetupRandom(m_ActiveAirdropPlaces);
        plane.SetDirection(planeSpawn - dropSpawn);	
		
		SendMessage("The supply plane is heading towards " + m_ActiveAirdropPlaces.Name);
	}

	void EOnPlayerDrop(vector position)
	{
		vector planeSpawn;
		switch(Math.RandomInt(0,4)) 
		{
            case 0: 
			{
                planeSpawn[0] = 0.0;
                planeSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 1: 
			{
                planeSpawn[0] = 15360.0;
                planeSpawn[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 2: 
			{
                planeSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                planeSpawn[2] = 0.0;
                break;
            }
            case 3: 
			{
                planeSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                planeSpawn[2] = 15360.0;
                break;
            }
        }

		AirdropPlane plane = AirdropPlane.Cast( GetGame().CreateObject( "AirdropPlane", planeSpawn, false, true, true) );
		plane.SetPosition(planeSpawn); 
		if (plane)
		{
			m_Planes.Insert( plane );
		}

		plane.SetupPlayer(position);
        plane.SetDirection(planeSpawn - position);	
		
		SendMessage("The supply plane is heading towards player");
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

static ref AirdropBase g_AirdropBase;
static ref AirdropBase GetAirdropBase()
{
    if ( !g_AirdropBase )
    {
         g_AirdropBase = new ref AirdropBase();
    }
    
    return g_AirdropBase;
}