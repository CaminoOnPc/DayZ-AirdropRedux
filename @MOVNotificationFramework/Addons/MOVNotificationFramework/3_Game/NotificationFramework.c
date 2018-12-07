protected const int FRAMEWORK_RPC_ID = 10042;

enum NotificationType
{
    Show = 0,
    Hide
}

class NotificationMeta
{
	ImageWidget m_AlertBackground;
	
	TextWidget m_AlertText;
	ImageWidget m_AlertIcon;
	
	Widget m_Alert;
	
	string m_Text;
	int m_Delay;
	int m_Hide;
	
	ScriptCallQueue m_Queue;
}

class NotificationFramework
{
	ref NotificationMeta m_Notification;
	
	void NotificationFramework()
	{
		Print("<NotificationFramework> Server");
		
		GetRPCManager().AddRPC( "MOVNotificationFramework", "ShowFunction", this, SingeplayerExecutionType.Server );
		GetRPCManager().AddRPC( "MOVNotificationFramework", "HideFunction", this, SingeplayerExecutionType.Server );
		
		m_Notification = new NotificationMeta;
		
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			GetDayZGame().Event_OnRPC.Insert( OnRPC );
		
			m_Notification.m_Queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY); 
		
			m_Notification.m_Alert = GetGame().GetWorkspace().CreateWidgets( "mov/scripts/layouts/alert.layout" );
			
			m_Notification.m_AlertIcon = ImageWidget.Cast( m_Notification.m_Alert.FindAnyWidget("NotificationImage") );
			m_Notification.m_AlertIcon.LoadImageFile(0, "mov/scripts/images/alert.paa");
			
			m_Notification.m_AlertText = TextWidget.Cast( m_Notification.m_Alert.FindAnyWidget("NotificationText") );
			m_Notification.m_AlertText.SetText("");
			
			m_Notification.m_Alert.Show(false);
		}
	}
	
	void OnRPC( PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx )
    {
		if( rpc_type != FRAMEWORK_RPC_ID )
        {
            return;
        }
		
		Param4< string, int, int, int > data;
		ctx.Read( data );
		
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (data.param4 == NotificationType.Show)
				ShowAlertClient(data.param1, data.param2, data.param3);
			if (data.param4 == NotificationType.Hide)
				HideAlertClient(data.param3);
		}
	}
	
	void Transfer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param4< string, int, int, int > data;
        if ( !ctx.Read( data ) ) return;
		
		if (data.param2 == 0)
		data.param2 = 1000;

        if( type == CallType.Server )
        {
			Print("<NotificationFramewok> Server");
        }
	}
	
	void OnShowAlertClient()
	{
		m_Notification.m_Alert.Show(true);
		m_Notification.m_AlertText.SetText(m_Notification.m_Text);	
	}
	
	void OnHideAlertClient()
	{
		m_Notification.m_Alert.Show(false);
		m_Notification.m_AlertText.SetText(m_Notification.m_Text);	
	}
	
	void ShowAlertClient(string l_Text, int l_Hide = 1000, int l_Delay = 0)
	{
		m_Notification.m_Text = l_Text;
		m_Notification.m_Hide = l_Hide;
		m_Notification.m_Delay = l_Delay;
		
		m_Notification.m_Queue.CallLater(OnShowAlertClient, l_Delay, false);	
		
		HideAlertClient(l_Hide);
	}
	
	void HideAlertClient(int l_Delay = 0)
	{
		m_Notification.m_Delay = l_Delay;
		
		m_Notification.m_Queue.CallLater(OnHideAlertClient, l_Delay, false);
	}
	
	void ShowAlert(string l_Text, int l_Hide = 1000, int l_Delay = 0)
	{
		GetRPCManager().SendRPC( "MOVNotificationFramework", "Transfer", new Param4< string, int, int, int >( l_Text, l_Hide, l_Delay, NotificationType.Show ) );
	}
	
	void HideAlert(int l_Delay = 0)
	{
		GetRPCManager().SendRPC( "MOVNotificationFramework", "Transfer", new Param4< string, int, int, int >( "", 1000, l_Delay, NotificationType.Hide ) );
	}
}

static ref NotificationFramework g_NotificationManager;
static ref NotificationFramework GetNotificationManager()
{
	if ( !g_NotificationManager )
    {
    	 g_NotificationManager = new ref NotificationFramework();
    }
	
	return g_NotificationManager;
}
