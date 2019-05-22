
class CfgPatches
{
	class AirdropCrate
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= 
		{ 
			"DZ_Data",
			"Airdrop"
		};
	};
};

class CfgVehicles 
{
	class HouseNoDestruct;
	class ItemGrenade;

	class AirdropPlane: HouseNoDestruct
	{
		scope=1;
		model="\DZ\structures\wrecks\Aircraft\Wreck_C130J.p3d";
	};

	class AirdropContainerBase: HouseNoDestruct
	{	
		scope=0;
		displayName="Airdrop";
		model="\Airdrop\crate\container.p3d";

		forceFarBubble = "true";
		carveNavmesh = 1;

		rotationFlags = 2;
		itemSize[] = {20,20};
		weight = 1000000;

		class Cargo
		{
			itemsCargoSize[] = {10,100};
		};

		hiddenSelections[]=
		{
			"body"
		};
		hiddenSelectionsTextures[]=
		{
			"Airdrop\crate\data\Airdrop_co.paa"
		};
	};

	class AirdropContainer: AirdropContainerBase
	{
		scope=2;
		displayName="Airdrop";
		hiddenSelections[]=
		{
			"body"
		};
		hiddenSelectionsTextures[]=
		{
			"Airdrop\crate\data\Airdrop_co.paa"
		};
	};

	class AirdropContainer_Medical: AirdropContainerBase
	{
		scope=2;
		displayName="Medical Airdrop";
		hiddenSelections[]=
		{
			"body"
		};
		hiddenSelectionsTextures[]=
		{
			"Airdrop\crate\data\Airdrop_med_co.paa"
		};
	};

	class AirdropContainer_Military: AirdropContainerBase
	{
		scope=2;
		displayName="Military Airdrop";
		hiddenSelections[]=
		{
			"body"
		};
		hiddenSelectionsTextures[]=
		{
			"Airdrop\crate\data\Airdrop_mil_co.paa"
		};
	};

	class AirdropFlareBase: ItemGrenade
	{
		displayName = "Airdrop Flare";
		descriptionShort = "$STR_CfgVehicles_RDG2SmokeGrenade_ColorBase1";
		model = "\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		rotationFlags = 17;
		havePin = 0;
		lootTag[] = {"Military_east","Police"};
		ammoType = "HandGrenade_Smoke";
		simulation = "handGrenade";
		fuseDelay = 3;
		timeToLive = 60;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\smokegrenade_rdg2.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\explosives\data\smokegrenade_rdg2.rvmat","DZ\weapons\explosives\data\smokegrenade_rdg2_damage.rvmat","DZ\weapons\explosives\data\smokegrenade_rdg2_destruct.rvmat"};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Grenade_unpin
				{
					soundSet = "Grenade_unpin_SoundSet";
					id = 201;
				};
			};
		};
	};

	class AirdropFlare: AirdropFlareBase
	{
		scope = 2;
		descriptionShort = "Deploy to call an airdrop";
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_rdg2_black_co.paa"};
		hit = 60;
		indirectHit = 28;
		indirectHitRange = 7;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		ammoType = "HandGrenade_Frag";
		class EnergyManager
		{
			energyAtSpawn = 60;
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
		};
	};

	class AirdropContainerParticle: HouseNoDestruct
	{
		scope=2;
	};
};