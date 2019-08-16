class AirdropFlare: Roadflare
{
	protected bool m_Executed;

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		if( !m_Executed )
		{
			return true;
		}
		return false;
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands(parent) ) {return false;}
		if( !m_Executed )
		{
			return true;
		}
		return false;
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();

		m_Executed = true;
		if ( GetGame().IsServer() )
		{
			GetAirdropBase().EOnPlayerDrop(GetPosition());
		}
	}
}