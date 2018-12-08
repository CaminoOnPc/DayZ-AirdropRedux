# Notification Framework for DayZ

Notification Framework allows send notifications to screen of players with any text. This frameworks supports sending notifications from mods or missions to players.

# How to seutp Notification Framework

First of all you have to download [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework/releases) to make it work. Then follow installation tutorial of [RPC Framework](https://github.com/Jacob-Mango/DayZ-RPCFramework) and install Notification Framework same way.

# How to use Notification Framework

To use Notification Framework in your mod you have to add MOVNotificationScripts to required addons

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

# How to use Notification Framework functions

Notification framework currently have these functions:

* ShowAlert (Text, Hide time, Delay)
* HideAlert (Delay)
