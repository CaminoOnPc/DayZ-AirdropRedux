class AirDrop_Places
{
    float x, y;
    string name;
    bool disclose, send_proximity;

    void AirDrop_Places(float x, float y, string name) 
	{
        this.x = x;
        this.y = y;
        this.name = name;
    }
};

class AirDrop_Base
{
	TStringArray WorkingZombieClasses()
	{
		return {
		"ZmbM_HermitSkinny_Base","ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green",
		"ZmbM_HermitSkinny_Red","ZmbM_FarmerFat_Base","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown",
		"ZmbM_FarmerFat_Green","ZmbF_CitizenANormal_Base","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Brown",
		"ZmbF_CitizenANormal_Blue","ZmbM_CitizenASkinny_Base","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown",
		"ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Base","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Red",
		"ZmbM_CitizenBFat_Green","ZmbF_CitizenBSkinny_Base","ZmbF_CitizenBSkinny","ZmbM_PrisonerSkinny_Base","ZmbM_PrisonerSkinny",
		"ZmbM_FirefighterNormal_Base","ZmbM_FirefighterNormal","ZmbM_FishermanOld_Base","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green",
		"ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_JournalistSkinny_Base","ZmbM_JournalistSkinny","ZmbF_JournalistNormal_Base",
		"ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White",
		"ZmbM_ParamedicNormal_Base","ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red",
		"ZmbM_ParamedicNormal_Black","ZmbF_ParamedicNormal_Base","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green",
		"ZmbF_ParamedicNormal_Red","ZmbM_HikerSkinny_Base","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow",
		"ZmbF_HikerSkinny_Base","ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Red",
		"ZmbM_HunterOld_Base","ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter",
		"ZmbF_SurvivorNormal_Base","ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red",
		"ZmbF_SurvivorNormal_White","ZmbM_SurvivorDean_Base","ZmbM_SurvivorDean_Black","ZmbM_SurvivorDean_Blue","ZmbM_SurvivorDean_Grey",
		"ZmbM_PolicemanFat_Base","ZmbM_PolicemanFat","ZmbF_PoliceWomanNormal_Base","ZmbF_PoliceWomanNormal","ZmbM_PolicemanSpecForce_Base",
		"ZmbM_PolicemanSpecForce","ZmbM_SoldierNormal_Base","ZmbM_SoldierNormal","ZmbM_usSoldier_normal_Base",
		"ZmbM_usSoldier_normal_Woodland","ZmbM_usSoldier_normal_Desert","ZmbM_CommercialPilotOld_Base","ZmbM_CommercialPilotOld_Blue",
		"ZmbM_CommercialPilotOld_Olive","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey","ZmbM_PatrolNormal_Base",
		"ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_Summer","ZmbM_JoggerSkinny_Base",
		"ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbF_JoggerSkinny_Base","ZmbF_JoggerSkinny_Blue",
		"ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbM_MotobikerFat_Base","ZmbM_MotobikerFat_Beige",
		"ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_VillagerOld_Base","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green",
		"ZmbM_VillagerOld_White","ZmbM_SkaterYoung_Base","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green",
		"ZmbM_SkaterYoung_Grey","ZmbF_SkaterYoung_Base","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet",
		"ZmbF_DoctorSkinny_Base","ZmbF_DoctorSkinny","ZmbF_BlueCollarFat_Base","ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green",
		"ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_MechanicNormal_Base","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green",
		"ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbM_MechanicSkinny_Base","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Grey",
		"ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Red","ZmbM_ConstrWorkerNormal_Base","ZmbM_ConstrWorkerNormal_Beige",
		"ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey","ZmbM_HeavyIndustryWorker_Base",
		"ZmbM_HeavyIndustryWorker","ZmbM_OffshoreWorker_Base","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red",
		"ZmbM_OffshoreWorker_Yellow","ZmbF_NurseFat_Base","ZmbF_NurseFat","ZmbM_HandymanNormal_Base","ZmbM_HandymanNormal_Beige",
		"ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White","ZmbM_DoctorFat_Base",
		"ZmbM_DoctorFat","ZmbM_Jacket_Base","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks",
		"ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes",
		"ZmbF_PatientOld_Base","ZmbF_PatientOld","ZmbM_PatientSkinny_Base","ZmbM_PatientSkinny","ZmbF_ShortSkirt_Base","ZmbF_ShortSkirt_beige",
		"ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_checks",
		"ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow","ZmbF_VillagerOld_Base",
		"ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_Soldier","ZmbM_SoldierAlice",
		"ZmbM_SoldierHelmet","ZmbM_SoldierVest","ZmbM_SoldierAliceHelmet","ZmbM_SoldierVestHelmet","ZmbF_MilkMaidOld_Base",
		"ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey","ZmbM_priestPopSkinny_Base",
		"ZmbM_priestPopSkinny","ZmbM_ClerkFat_Base","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White",
		"ZmbF_Clerk_Normal_Base","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_White","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red",
		};
	}
	
	string GetRandomLoot() 
	{
		TStringArray loot = {
		"LandMineTrap", 
		"TTSKOPants", 
		"TacticalBaconCan", 
		"M4A1", 
		"PlateCarrierComplete", 
		"BakedBeansCan", 
		"WaterBottle", 
		};

		return loot.GetRandomElement();
	}
	
	int m_SpawnCount = 4;
	
	ref AirDrop_Places m_AirDropPlaces[] = {
        new AirDrop_Places(4807, 9812, "Northwest Airfield"),
		AirDrop_Places(11464, 8908, "Berezino"),
		AirDrop_Places(12159, 12583, "Krasnostav"),
		AirDrop_Places(5043, 2505, "Balota"),
    };
	
	void SendMessage(string message) 
	{
		m_NotificationFramework.ShowAlert(message, 3000);
	}
	
	Object m_Plane;
	vector m_PlanePos;
	
	bool m_Enabled = false;
    bool m_Landed = false;
	
	void ResetPlane() 
	{
		GetGame().ObjectDelete(m_Plane);
		
		m_Plane = GetGame().CreateObject( "Land_Wreck_C130J", "0 0 0", false, true, false );
		
		m_PlanePos[0] = 0;
        m_PlanePos[1] = 0;
        m_PlanePos[2] = 0;
		m_Plane.SetPosition(m_PlanePos);
		
		m_Landed = false;
		m_Enabled = false;
		
		GetGame().AdminLog("<AirDrop Redux> :ResetPlane");
		SendMessage("The airplane has been vanished");
	}
	
	House m_Drop;
	
	void ResetDrop()
	{
		 GetGame().ObjectDelete(m_Drop);
		 m_Particle.GetCompEM().SwitchOff();
		 m_DropParticle.GetCompEM().SwitchOff();
		 GetGame().ObjectDelete(m_Particle);
		 GetGame().ObjectDelete(m_DropParticle);
	}
		
	// In minutes
	float m_Interval = 60.0;
    float m_Initial = 60.0; 

	ref NotificationFramework m_NotificationFramework;
		
	void AirDrop_Base() 
	{	
		if (GetGame().ConfigIsExisting("airdropInterval"))		
			m_Interval = GetGame().ConfigGetInt("airdropInterval");
		if (GetGame().ConfigIsExisting("airdropInitial"))		
			m_Initial = GetGame().ConfigGetInt("airdropInitial");	
		if (GetGame().ConfigIsExisting("airdropSpeed"))		
			m_Speed = GetGame().ConfigGetInt("airdropSpeed");
		if (GetGame().ConfigIsExisting("airdropHeight"))		
			m_Height = GetGame().ConfigGetInt("airdropHeight");
		if (GetGame().ConfigIsExisting("airdropItems"))		
			m_Items = GetGame().ConfigGetInt("airdropItems");
		if (GetGame().ConfigIsExisting("airdropInfected"))		
			m_Infected = GetGame().ConfigGetInt("airdropInfected");	
		
		m_NotificationFramework = new NotificationFramework();
		
		ResetPlane();
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(InitPlane, m_Initial * 60 * 1000, false);
		GetGame().AdminLog("<AirDrop Redux> :Init");	
	}
	
	void InitPlane() 
	{
        ResetPlane();
        ResetDrop();
		
        SpawnPlane();
		
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(InitPlane, m_Interval * 60 * 1000, false);
    }
		
	ref AirDrop_Places m_ActiveAirDropPlaces;
	
	vector m_PlaneSpawn;
	vector m_DropPos;
	
	void SpawnPlane() 
	{
        GetGame().AdminLog("<AirDrop Redux> :SpawnPlane " + m_PlaneSpawn);

        int side = Math.RandomInt(0,4);
        switch(side) {
            case 0: {
                m_PlaneSpawn[0] = 0.0;
                m_PlaneSpawn[1] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 1: {
                m_PlaneSpawn[0] = 15360.0;
                m_PlaneSpawn[1] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 2: {
                m_PlaneSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                m_PlaneSpawn[1] = 0.0;
                break;
            }
            case 3: {
                m_PlaneSpawn[0] = Math.RandomFloat(0.0, 15360.0);
                m_PlaneSpawn[1] = 15360.0;
                break;
            }
        }
		
		vector m_PlaneStartPos;
        m_PlaneStartPos[0] = m_PlaneSpawn[0];
        m_PlaneStartPos[2] = m_PlaneSpawn[1];
        m_Plane.SetPosition(m_PlaneStartPos);
		
		AirDrop_Places m_DefaultAirDropPlaces = new AirDrop_Places(2760.0, 5527.0, "Default");	
		
		if(m_SpawnCount < 1) 
		{
			GetGame().AdminLog("<AirDrop Redux> :SpawnCount is lower than 1");	
			m_ActiveAirDropPlaces = m_DefaultAirDropPlaces;
		}
		else
		{
			m_ActiveAirDropPlaces = m_AirDropPlaces[Math.RandomInt(0, m_SpawnCount - 1)];
		}
		
		vector m_Temp;
        m_Temp[0] = m_ActiveAirDropPlaces.x;
        m_Temp[1] = GetGame().SurfaceY(m_ActiveAirDropPlaces.x, m_ActiveAirDropPlaces.y) + 1;
        m_Temp[2] = m_ActiveAirDropPlaces.y;
		
		SendMessage("The airplane is heading towards " + m_ActiveAirDropPlaces.name.ToLower());
		
		m_DropPos[0] = m_ActiveAirDropPlaces.x;
        m_DropPos[1] = m_ActiveAirDropPlaces.y;
		
		float m_Angle = Math.Atan2(m_DropPos[1] - m_PlaneSpawn[1], m_DropPos[0] - m_PlaneSpawn[0]);
        float m_FixedAngle = m_Angle * Math.RAD2DEG;
		
		vector m_Dir = m_DropPos - m_PlaneSpawn;
        float m_Dist = m_Dir.Length();
		
		vector m_Direction = Vector(m_PlaneSpawn[0], 0, m_PlaneSpawn[1]) - Vector(m_DropPos[0], 0, m_DropPos[1]);
        m_Plane.SetOrientation(Vector(m_Direction.VectorToAngles()[0], 0, 0));
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(MovePlane, 20, true);
	}
	
	int m_Items = 7;
	int m_Infected = 15;
	
	float m_Speed = 1.0;
	float m_Height = 300;
	
	EntityAI m_Physical;
	EntityAI m_Particle;
	EntityAI m_DropParticle;

	void AfterDrop() 
	{
        vector m_Base = m_Drop.GetPosition(), m_DynamicPos;
		
		/*
		TODO: Modded class for LandMineTrap to remove delay
		
		m_DropParticle = EntityAI.Cast(GetGame().CreateObject( "LandMineTrap", m_Drop.GetPosition())); 
        m_DropParticle.SetOrientation("0 0 0");
        m_DropParticle.GetCompEM().SwitchOn(); 
        m_DropParticle.Delete();
		m_DropParticle.GetCompEM().SwitchOff(); 
		*/
		
		m_Particle = EntityAI.Cast(GetGame().CreateObject( "RDG2SmokeGrenade_Black", m_Drop.GetPosition())); 
        m_Particle.SetOrientation("0 0 0");
        m_Particle.GetCompEM().SwitchOn(); 
        m_Particle.Delete();
		
        for(int i = 0; i < m_Items; i++) 
		{
            float a = Math.RandomFloat(0.4, 1.0) * 2 * Math.PI;
            float r = 5.0 * Math.Sqrt(Math.RandomFloat(0.4, 1.0));
            m_DynamicPos = m_Base;
            m_DynamicPos[0] = m_DynamicPos[0]+(r * Math.Cos(a));
            m_DynamicPos[2] = m_DynamicPos[2]+(r * Math.Sin(a));
            m_DynamicPos[1] = GetGame().SurfaceY(m_DynamicPos[0], m_DynamicPos[2]) + 0.3;
            string m_Item = GetRandomLoot();
            GetGame().CreateObject(m_Item, m_DynamicPos, false, true);
        }
        for ( int m_Zombie = 0; m_Zombie < m_Infected; m_Zombie++ ) 
		{
            m_DynamicPos = m_Base;
            m_DynamicPos[0] = m_DynamicPos[0] + Math.RandomFloat(-20.0, 20.0);
            m_DynamicPos[2] = m_DynamicPos[2] + Math.RandomFloat(-20.0, 20.0);
            GetGame().CreateObject( WorkingZombieClasses().GetRandomElement(), m_DynamicPos, false, true );
        }
    }
	
	int m_Motion = 0;
	
	void DropSimulation() 
	{
        float m_Ground = GetGame().SurfaceY(m_Drop.GetPosition()[0], m_Drop.GetPosition()[2]);
        float diff = m_Drop.GetPosition()[1]-m_Physical.GetPosition()[1];
        if(diff <= 0.0001) m_Motion += 1;
        else m_Motion = 0;
        if (m_Physical.GetPosition()[1] <= (m_Ground + 3.0) || m_Motion >= 25)
		{
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(DropSimulation);
            vector m_Temp = m_Drop.GetPosition();
            m_Temp[1] = m_Ground;
            GetGame().ObjectDelete(m_Physical);
            m_Drop.SetPosition(m_Temp);
            m_Drop.PlaceOnSurface();
            GetGame().AdminLog("<AirDrop Redux> Hit surface");
            AfterDrop();
        } else 
		{
            vector m_ObjectPos;
            m_ObjectPos[0] = m_DropPos[0];
            m_ObjectPos[1] = m_Physical.GetPosition()[1];
            m_ObjectPos[2] = m_DropPos[1];
            m_Drop.SetPosition(m_ObjectPos);
            m_Drop.SetOrientation(m_Physical.GetOrientation());
        }
    }
	
	void Drop() 
	{
        m_Motion = 0;
        GetGame().AdminLog("<AirDrop Redux> Physics init");
        m_Physical = EntityAI.Cast(GetGame().CreateObject( "OffroadHatchback", m_Plane.GetPosition(), true, true ));
        m_Physical.SetAllowDamage(false);
        m_Drop = GetGame().CreateObject( "DropBox", m_Plane.GetPosition(), false, true );
        SetVelocity(m_Physical, "10 0 0");
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DropSimulation, 10, true);
    }
	
	float m_ProximityDist = 1500.0;
	bool m_ProximityWarning = false;
	
	SoundOnVehicle m_Sound;
	
	void MovePlane() 
	{
		float m_Angle = Math.Atan2(m_DropPos[1] - m_PlaneSpawn[1], m_DropPos[0] - m_PlaneSpawn[0]);
		float m_FixedAngle = m_Angle * Math.RAD2DEG;
		
		m_PlanePos[0] = Math.Cos(m_Angle);
        m_PlanePos[2] = Math.Sin(m_Angle);
		
		vector m_PlanePosFixed = m_Plane.GetPosition() + (m_PlanePos * m_Speed);
		
		m_PlanePosFixed[1] = GetGame().SurfaceY(m_PlanePosFixed[0], m_PlanePosFixed[2]) + m_Height;
		
		m_Plane.SetPosition(m_PlanePosFixed);
		
		m_Sound = m_Plane.PlaySoundLoop("airplaneLoop", 1000, false);
		
		if(!m_Landed) 
		{
			float m_Dist = Math.Sqrt(Math.Pow(m_DropPos[0] - m_PlanePosFixed[0], 2) + Math.Pow(m_DropPos[1] - m_PlanePosFixed[2], 2));
			if(m_Dist <= 10.0) 
			{
				m_Landed = true;
				Drop();
				SendMessage("The supplies have been dropped around " + m_ActiveAirDropPlaces.name.ToLower());
			}
			else if(m_Dist <= m_ProximityDist && !m_ProximityWarning) 
			{
				m_ProximityWarning = true;
				SendMessage("The plane is closing in on " + m_ActiveAirDropPlaces.name.ToLower());
			}
		}
		else 
		{
            if(!IsInRect(m_PlanePosFixed[0], m_PlanePosFixed[1], -10.0, 15470.0, -10.0, 1570.0)) {
                GetGame().AdminLog("<AirDrop Redux> Cleaning up");
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(MovePlane);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ResetPlane, 1000, false);
            }
        }
	}
	
	bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) {
        if(x > min_x && x < max_x && y > min_y && y < max_y) return true;
        return false;
    }
};