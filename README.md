# AirDrop Redux mod for DayZ

AirDrop Redux is overwork of original [AirDrop](https://github.com/mov3ax/airdrop) mod. AirDrop Redux is a mod from now and it's required to be installed on both client and server.

## How To Use

This is how you would use this mod. 

### Setup

First of all you have to download [Notification Framework](https://github.com/mov3ax/DayZ-NotificationFramework/releases) and [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework/releases) to make it work. Then download [AirDrop Redux](https://github.com/mov3ax/DayZ-AirdropRedux/releases) itself and follow installation tutorial of [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework) and install AirDrop Redux same way.

### Configuration

Open the **@AirdropRedux** folder and there you would see **Settings** folder. In that **Settings** folder you can adjust following variables from **AirDrop_Settings.json** file.

* Array Loot return type of items which will spawn in AirDrop.
* Variable Interval return how ofter AirDrop will fly.
* Variable Initial return how much time will pass from server start to first AirDrop spawn.
* Variable Items return how many items will spawn in AirDrop.
* Variable Infected return how many infected will spawn around AirDrop.
* Variable Mass return mass of AirDrop container.
* Variable Speed return how fast Airplane will fly.
* Variable Height return how high Airplane will fly above the surface.

### Call an airdrop function

You can call different airdrop functions from your mod or mission, for example you can spawn airplane using this code:

```cpp
GetAirdropBase().CustomPlane(true, 0, 9000, 5000, "my airdrop place");
```

* For the bool variable 'true' you would enable or dissable custom plane.
* For the int variable '0' you would select direction from where plane would fly.
* For the int variable '9000' you would select x axis where airdrop should land.
* For the int variable '5000' you would select y axis where airdrop should land.
* For the string variable 'my airdrop place' you would select name of your location.

## Contributors

* [mov3ax](https://github.com/mov3ax)
* [philippj](https://github.com/philippj)
* Mr9099





