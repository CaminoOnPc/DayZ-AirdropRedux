enum SoundType
{
    Loop = 0,
    Alert
}

class AirDrop_Sound
{
	ScriptInvoker m_LoopQueue;
	ScriptInvoker m_SignalQueue;
	
	vector m_Position;
	
	void AirDrop_Sound()
	{
		m_LoopQueue = GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY); 
		m_SignalQueue = GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY); 
		
		GetRPCManager().AddRPC( "MOVAirdrop", "Transfer", this, SingeplayerExecutionType.Both );
	}
	
	SoundObject l_Obj;
	SoundObject l_Obj_a;
	
	void ApplyLoopPossition()
	{
		l_Obj.SetPosition(m_Position);
	}
	
	void ApplySignalPossition()
	{
		l_Obj_a.SetPosition(m_Position);
	}
	
	void AddLoopSound()
	{
		SoundObject soundObject;
		SoundParams soundParams = new SoundParams("AirPlaneLoop_SoundSet");
		SoundObjectBuilder soundBuilder = new SoundObjectBuilder(soundParams);
		soundObject = soundBuilder.BuildSoundObject();
		soundObject.SetPosition(m_Position);
		GetGame().GetSoundScene().Play3D(soundObject, soundBuilder);  
		
		l_Obj = soundObject;
		m_LoopQueue.Insert(ApplyLoopPossition);	  
	}
	
	void AddSignalSound()
	{
		SoundObject soundObject_a;
		SoundParams soundParams_a = new SoundParams("AirPlaneAlarm_SoundSet");
		SoundObjectBuilder soundBuilder_a = new SoundObjectBuilder(soundParams_a);
		soundObject_a = soundBuilder_a.BuildSoundObject();
		soundObject_a.SetPosition(m_Position);
		GetGame().GetSoundScene().Play3D(soundObject_a, soundBuilder_a);    
		
		l_Obj_a = soundObject_a;
		m_SignalQueue.Insert(ApplySignalPossition);	
	}
	
	void Transfer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param1< int > data;
        if ( !ctx.Read( data ) ) return;
		
        if( type == CallType.Client )
        {	
			if (data.param1 == SoundType.Loop)
			{	
				AddLoopSound();
			}

			if (data.param1 == SoundType.Alert)
			{	
				AddSignalSound();
			}
        }
		if( type == CallType.Server )
		{
			m_Position = GetAirdropBase().m_Plane.GetPosition();
		}
    }
	
	void PlaySignal()
	{
		GetRPCManager().SendRPC( "MOVAirdrop", "Transfer", new Param1< int >( SoundType.Alert ) );
	}
	
	void PlayLoop()
	{
		GetRPCManager().SendRPC( "MOVAirdrop", "Transfer", new Param1< int >( SoundType.Loop ) );
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
