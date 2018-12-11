enum SoundType
{
    Loop = 0,
    Alert
}

class AirDrop_Sound
{
	/*
	void AirDrop_Sound()
	{
		GetRPCManager().AddRPC( "MOVAirdrop", "Transfer", this, SingeplayerExecutionType.Client );
	}
	
	void Transfer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param2< ref House, int > data;
        if ( !ctx.Read( data ) ) return;

        if( type == CallType.Client )
        {
			if (data.param2 == SoundType.Loop)
			{
				GetAirdropSound().PlayLoop(data.param1);
			}
			if (data.param2 == SoundType.Alert)
			{
				GetAirdropSound().PlaySignal(data.param1);
			}
        }
    }
	
	void PlaySignal(House object)
	{
		Print("<AirDrop> Play signal");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())		
		{
			object.PlaySound("AirPlaneAlarm", 1000);
		}
		else
		{
			GetRPCManager().SendRPC( "MOVAirdrop", "Transfer", new Param2< House, int >( GetAirdropBase().m_Plane, SoundType.Alert ) );
		}
	}
	
	void PlayLoop(House object)
	{
		Print("<AirDrop> Play loop");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())		
		{
			object.PlaySoundLoop("AirPlaneLoop", 2000);
		}
		else
		{
			GetRPCManager().SendRPC( "MOVAirdrop", "Transfer", new Param2< House, int >( GetAirdropBase().m_Plane, SoundType.Loop ) );
		}
	}
	*/
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
