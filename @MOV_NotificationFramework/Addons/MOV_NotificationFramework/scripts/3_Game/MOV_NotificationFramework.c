class Notification
{
	ScriptCallQueue m_Queue;
	Widget m_Alert;
	TextWidget m_AlertText;
	ImageWidget m_AlertIcon;
	ImageWidget m_AlertBackground;
	string m_Text;
	
	void Notification()
	{
		m_Text = "";
	}
}

class NotificationFramework
{
	void NotificationFramework()
	{
		GetNotificationClass().m_Queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY); 
		
		GetNotificationClass().m_Alert = GetGame().GetWorkspace().CreateWidgets( "mov/framework/notification/layouts/alert.layout" );
		GetNotificationClass().m_AlertIcon = ImageWidget.Cast( GetNotificationClass().m_Alert.FindAnyWidget("NotificationImage") );
		GetNotificationClass().m_AlertText = TextWidget.Cast(  GetNotificationClass().m_Alert.FindAnyWidget("NotificationText") );
		
		GetNotificationClass().m_Alert.Show(false);
		GetNotificationClass().m_AlertIcon.LoadImageFile(0, "mov/framework/notification/images/alert.paa");
		GetNotificationClass().m_AlertText.SetText("");	
	}
	
	void OnRPC(ParamsReadContext ctx)
	{
		int code;
		string function;
		
		ctx.Read(code);
		ctx.Read(function);
		
		if (code == 1 && function == "OnShowEveryone")
		{
			OnShow();
		}
		if (code == 2 && function == "OnHideEveryone")
		{
			OnHide();
		}
	}
	
	void OnShow()
	{
		ScriptRPC rpc = new ScriptRPC();
		
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			GetNotificationClass().m_Alert.Show(true);
			GetNotificationClass().m_AlertText.SetText(GetNotificationClass().m_Text);	
		}
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			rpc.Write(1); // 1 - Show
			rpc.Write("OnShowEveryone");
		}
	}
	
	void OnHide()
	{
		ScriptRPC rpc = new ScriptRPC();
		
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			GetNotificationClass().m_Alert.Show(false);
			GetNotificationClass().m_Text = "";
		}	
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			rpc.Write(2); // 2 - Hide
			rpc.Write("OnHideEveryone");
		}
	}
	
	void ShowAlert(string l_Text, int l_Hide = 1000, int l_Delay = 0)
	{
		GetNotificationClass().m_Text = l_Text;
		GetNotificationClass().m_Queue.CallLater(OnShow, l_Delay, false);
		
		if (l_Hide > 0)
		{
			HideAlert(l_Hide);	
		}
	}
	
	void HideAlert(int l_Delay = 0)
	{
		GetNotificationClass().m_Queue.CallLater(OnHide, l_Delay, false);
	}
}

private static ref Notification g_Notification;
private static ref Notification GetNotificationClass()
{
	if ( !g_Notification )
    {
    	 g_Notification = new ref Notification;
    }
}

static ref NotificationFramework g_NotificationManager;
static ref NotificationFramework GetNotificationManager()
{
	if ( !g_NotificationManager )
    {
    	 g_NotificationManager = new ref NotificationFramework;
    }
}
