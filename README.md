# AirDrop Redux mod for DayZ

AirDrop Redux is overwork of original [AirDrop](https://github.com/mov3ax/airdrop) mod. AirDrop Redux is a mod from now and it's required to be installed on both client and server.

## How To Use

This is how you would use this mod. 

### Setup

First of all you have to download [Notification Framework](https://github.com/mov3ax/DayZ-NotificationFramework/releases) and [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework/releases) to make it work. Then download [AirDrop Redux](https://github.com/mov3ax/DayZ-AirdropRedux/releases) itself and follow installation tutorial of [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework) and install AirDrop Redux same way.

### Configuration

Open the **@MOVAirdrop** folder and there you would see **Settings** folder. In that **Settings** folder you can adjust following variables from two different files.

File **AirdropSettings.c** contains following parameters:

* Array Loot return type of items which will spawn in AirDrop.
* Variable Interval return how ofter AirDrop will fly.
* Variable Initial return how much time will pass from server start to first AirDrop spawn.
* Variable Items return how many items will spawn in AirDrop.
* Variable Infected return how many infected will spawn around AirDrop.
* Variable Mass return mass of AirDrop container.
* Variable Speed return how fast Airplane will fly.
* Variable Height return how high Airplane will fly above the surface.

File **AirdropPlaces.c** contains following parameters:

* Array AirDropPlaces return places where AirDrop can land.
* Variable SpawnCount return amount of places where AirDrop can land.

## Contributors

* [mov3ax](https://github.com/mov3ax)
* [philippj](https://github.com/philippj)
* Mr9099





