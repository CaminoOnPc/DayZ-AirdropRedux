
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
	class Roadflare;
	class Container_Base;
	class Inventory_Base;

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

		overrideDrawArea="8.0";
		forceFarBubble = "true";
		carveNavmesh = 1;
		heavyItem=1;
		physLayer="item_large";

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
	class AirdropFlare: Roadflare
	{
		scope = 2;
		displayName = "Flare";
		descriptionShort = "Deploy to call an airdrop";
	};
};