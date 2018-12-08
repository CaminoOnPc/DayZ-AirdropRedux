# Notification Framework for DayZ

Notification Framework allows send notifications to screen of players with any text. This frameworks supports sending notifications from mods or missions to players.

## How To Use

This is how you would use this framework within your mod. 

### Setup

First of all you have to download [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework/releases) to make it work. Then follow installation tutorial of [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework) and install Notification Framework same way.

When starting the game and/or server, make sure to add the mod first by using `-mod=@MOVNotificationFramework;` and then append the rest of your mods afterwards. Seperate using the `;` character.

To use the framework with your mod you would want to add the mod to the config.cpp of your scripts PBO.

e.g.

```cpp
class CfgPatches
{
    class ...
    {
        ...
        requiredAddons[]=
        {
            "MOVNotificationScripts",
            ...
        };
    };
};
```

### Call an notification function

Notification framework currently have these functions:

```java
GetNotificationManager().ShowAlert("Welcome!", 1000, 0);
```

* For the string variable 'Welcone' you would add your text.
* For the int variable '1000' you would add the hide time.
* For the int variable '0' you would add the delay. 

```java
GetNotificationManager().HideAlert(1000);
```

* For the int variable '1000' you would add the delay. 

### Example

Soon

## Projects

Here are some projects that are already planned to use this Framework.

* AirDrop Redux by mov3ax
* GPS Mod by mov3ax
* DayZ Reloaded by mov3ax

## Contributors

* [mov3ax](https://github.com/mov3ax)
* [Jacob_Mango](https://github.com/Jacob-Mango) (Thanks to him for his troubleshooting and helping with RPC Framework)

