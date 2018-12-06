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
	ref Notification m_Notification;

	void NotificationFramework()
	{
		m_Notification = new Notification();
		
		m_Notification.m_Queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY); 
		
		m_Notification.m_Alert = GetGame().GetWorkspace().CreateWidgets( "mov/framework/notification/layouts/alert.layout" );
		m_Notification.m_AlertIcon = ImageWidget.Cast( m_Notification.m_Alert.FindAnyWidget("NotificationImage") );
		m_Notification.m_AlertText = TextWidget.Cast( m_Notification.m_Alert.FindAnyWidget("NotificationText") );
		
		m_Notification.m_AlertIcon.LoadImageFile(0, "mov/framework/notification/images/alert.paa");
		m_Notification.m_Alert.Show(false);
		m_Notification.m_AlertText.SetText("");
	}

	void OnShow()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_Notification.m_Alert.Show(true);
			m_Notification.m_AlertText.SetText(m_Notification.m_Text);	
		}
	}
	
	void OnHide()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_Notification.m_Alert.Show(false);
			m_Notification.m_Text = "";
		}	
	}
	
	void ShowAlert(string l_Text, int l_Hide = 1000, int l_Delay = 0)
	{
		m_Notification.m_Text = l_Text;
		m_Notification.m_Queue.CallLater(OnShow, l_Delay, false);
		
		if (l_Hide > 0)
		{
			HideAlert(l_Hide);	
		}
	}
	
	void HideAlert(int l_Delay = 0)
	{
		m_Notification.m_Queue.CallLater(OnHide, l_Delay, false);
	}
}