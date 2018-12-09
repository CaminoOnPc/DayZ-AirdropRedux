#include "$CurrentDir:@MOVAirdrop\\AirdropSettings.c"

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
}

class AirDrop_Base
{
	ref AirDrop_Settings m_Settings = new AirDrop_Settings();
	
	void SendMessage(string message) 
	{
		GetNotificationManager().ShowAlert(message, 3000);
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
		
		Print("<AirDrop> Airplane vanished");
		
		SendMessage("The airplane has been vanished");
	}
	
	House m_Drop;
	
	void ResetDrop()
	{
		 GetGame().ObjectDelete(m_Drop);
		
		 if (m_Particle)
		 	m_Particle.GetCompEM().SwitchOff();
		 //if (m_DropParticle)
		 //	m_DropParticle.GetCompEM().SwitchOff();
	}
		
	void AirDrop_Base() 
	{	
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_Settings = new AirDrop_Settings();
			
			ResetPlane();
		
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(InitPlane, m_Settings.m_Initial * 60 * 1000, false);
			Print("<AirDrop> Initializing");
		}
	}
	
	void InitPlane() 
	{
        ResetPlane();
        ResetDrop();
		
        SpawnPlane();
		
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(InitPlane, m_Settings.m_Interval * 60 * 1000, false);
    }
		
	ref AirDrop_Places m_ActiveAirDropPlaces;
	
	vector m_PlaneSpawn;
	vector m_DropPos;
	
	void SpawnPlane() 
	{
		Print("<AirDrop> Spawning plane");
		
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
		
		m_Sound = m_Plane.PlaySoundLoop("AirPlaneLoop", 2000, false);
		
		AirDrop_Places m_DefaultAirDropPlaces = new AirDrop_Places(2760.0, 5527.0, "Default");	
		
		if(m_Settings.m_SpawnCount < 1) 
		{
			Print("<AirDrop> Spawning places count is lower than one");
			m_ActiveAirDropPlaces = m_DefaultAirDropPlaces;
		}
		else
		{
			m_ActiveAirDropPlaces = m_Settings.m_AirDropPlaces[Math.RandomInt(0, m_Settings.m_SpawnCount - 1)];
		}
		
		vector m_Temp;
        m_Temp[0] = m_ActiveAirDropPlaces.x;
        m_Temp[1] = GetGame().SurfaceY(m_ActiveAirDropPlaces.x, m_ActiveAirDropPlaces.y) + 1;
        m_Temp[2] = m_ActiveAirDropPlaces.y;
			
		SendMessage("The airplane is heading towards " + m_ActiveAirDropPlaces.name);
		
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

        for(int i = 0; i < m_Settings.m_Items; i++) 
		{
            string m_Item = m_Settings.GetRandomLoot();
            m_Drop.GetInventory().CreateInInventory(m_Item);
        }
        for ( int m_Zombie = 0; m_Zombie < m_Settings.m_Infected; m_Zombie++ ) 
		{
            m_DynamicPos = m_Base;
            m_DynamicPos[0] = m_DynamicPos[0] + Math.RandomFloat(-20.0, 20.0);
            m_DynamicPos[2] = m_DynamicPos[2] + Math.RandomFloat(-20.0, 20.0);
            GetGame().CreateObject( m_Settings.WorkingZombieClasses().GetRandomElement(), m_DynamicPos, false, true );
        }
    }
	
	int m_Motion = 0;
	
	void DropSimulation() 
	{
		if (GetVelocity(m_Drop) == vector.Zero)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(DropSimulation);
			vector m_TempPos = m_Drop.GetPosition();
			vector m_TempOri = m_Drop.GetOrientation();
			GetGame().ObjectDelete(m_Drop);
			m_Drop = GetGame().CreateObject( "AirDropContainer", m_TempPos, false, true );	
			m_Drop.SetOrientation(m_TempOri);
            Print("<AirDrop> Container did hit the surface");
            AfterDrop();
		}
    }
	
	void Drop() 
	{
		m_Plane.PlaySound("AirPlaneAlarm", 1000, false);
        m_Drop = GetGame().CreateObject( "AirDropContainer", m_Plane.GetPosition() + "0 10 0" );	
		
		if ( m_Drop == NULL ) return;
		dBodyDestroy( m_Drop );	
		autoptr PhysicsGeomDef geoms[] = {PhysicsGeomDef("", dGeomCreateBox("3 2.5 3"), "material/default", 0xffffffff)};
		dBodyCreateDynamicEx( m_Drop , "0 0 0", m_Settings.m_Mass, geoms );
		SetVelocity(m_Drop, "1 -50 0");	
		
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
		
		vector m_PlanePosFixed = m_Plane.GetPosition() + (m_PlanePos * m_Settings.m_Speed);
		
		m_PlanePosFixed[1] = GetGame().SurfaceY(m_PlanePosFixed[0], m_PlanePosFixed[2]) + m_Settings.m_Height;
		
		m_Plane.SetPosition(m_PlanePosFixed);
		
		if(!m_Landed) 
		{
			float m_Dist = Math.Sqrt(Math.Pow(m_DropPos[0] - m_PlanePosFixed[0], 2) + Math.Pow(m_DropPos[1] - m_PlanePosFixed[2], 2));
			if(m_Dist <= 10.0) 
			{
				m_Landed = true;
				Drop();
				SendMessage("The supplies have been dropped around " + m_ActiveAirDropPlaces.name);
			}
			else if(m_Dist <= m_ProximityDist && !m_ProximityWarning) 
			{
				m_ProximityWarning = true;
				m_Plane.PlaySound("AirPlaneAlarm", 1000, false);
				SendMessage("The plane is closing in on " + m_ActiveAirDropPlaces.name);
			}
		}
		else 
		{
            if(!IsInRect(m_PlanePosFixed[0], m_PlanePosFixed[1], -10.0, 15470.0, -10.0, 1570.0)) {
				Print("<AirDrop> Cleaning up");
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(MovePlane);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ResetPlane, 1000, false);
            }
        }
	}
	
	bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) {
        if(x > min_x && x < max_x && y > min_y && y < max_y) return true;
        return false;
    }
}

static ref AirDrop_Base g_AirdropBase;
static ref AirDrop_Base GetAirdropBase()
{
    if ( !g_AirdropBase )
    {
         g_AirdropBase = new ref AirDrop_Base();
    }
    
    return g_AirdropBase;
}