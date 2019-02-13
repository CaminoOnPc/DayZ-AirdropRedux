class AirDrop_Sound
{
	void AirDrop_Sound()
	{
		GetRPCManager().AddRPC( "MOVAirdrop", "Transfer", this, SingeplayerExecutionType.Both );
	}
	
	void Transfer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param1< vector > data;
        if ( !ctx.Read( data ) ) return;
		
        if( type == CallType.Client )
        {	
			ref array<CargoBase> cargos = new array<CargoBase>;
			ref array<Object> objects = new array<Object>;
			
			vector m_Position = data.param1;
	
			GetGame().GetObjectsAtPosition(m_Position, 1, objects, cargos); 
			for ( int i = 0; i < objects.Count(); i++ ) 
			{
				Object m_Object = objects.Get(i);
				m_Object.PlaySound("AirPlaneAlarm", 1000);
			}
        }
    }
	
	void PlaySignal()
	{
		if (GetGame().IsMultiplayer())
		{
			GetRPCManager().SendRPC( "MOVAirdrop", "Transfer", new Param1< vector >( GetAirdropBase().m_Plane.GetPosition() ) );
		}
		else
		{
			GetAirdropBase().m_Plane.PlaySound("AirPlaneAlarm", 1000);
		}
	}
}

static ref AirDrop_Sound g_AirdropSound;
static ref AirDrop_Sound GetAirdropSound()
{
    if ( !g_AirdropSound )
    {
         g_AirdropSound = new ref AirDrop_Sound();
    }
    
    return g_AirdropSound;
}
