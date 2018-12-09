// Items which will spawn in airdrop
autoptr TStringArray m_Loot = {
	"LandMineTrap", 
	"TTSKOPants", 
	"TacticalBaconCan", 
	"M4A1", 
	"PlateCarrierComplete", 
	"BakedBeansCan", 
	"WaterBottle", 
};

float m_Interval = 5.0; // Time in minutes from server start to first airdrop spawn
float m_Initial = 0.01; // Time in mutires how ofter airdrop will spawn
	
int m_Items = 7; // Items count in airdrop
int m_Infected = 15; // Infected count around airdrop
	
float m_FallSpeed = 0.2; // Airdrop fall speed in meters per second
float m_Speed = 10.0; // Airplane speed in meters per second
float m_Height = 300; // Airplane fly height above surface
	
float m_Mass = 100; // Airdrop container mass