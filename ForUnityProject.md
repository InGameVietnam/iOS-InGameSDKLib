#Include IOS IngameSDK to Unity project

##Introduction

This tutorial shows you how to include the Ingame Mobile SDK to unity project. you can download example [at here](https://drive.google.com/file/d/0B5igvj6-bthATWFlRmQxNWhkOTA/view?usp=sharing)

##Prerequisites
* Xcode 5.1 or higher
* Deployment target of 6.0 or higher
* A unity 5.0 project or higher

##Adding the SDK to your Unity project
The first time you must have a unity project. my unity project name is **IngameSDKExampleUnity**.
###Using the SDK download
If you don't already have the Ingame Mobile SDK, grab it from the [downloads page](https://github.com/InGameVietnam/iOS-InGameSDKLib/archive/master.zip) and unzip it.

####Add the library

The first copy the library folder to your ios project navigation

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add7_zpssoqsywl6.png)

####Add other frameworks that the SDK requires

The SDK depends on the following iOS development frameworks which may not already be part of your project:

* AdSupport
* MessageUI
* FacebookSDK
* MobileCoreServices
* libz.dylib
* SystemConfiguration
* CFNetwork
* StoreKit
* Security

####Config Project Setting:
In project navigation goto **Project target > Build Settings Tab > Linking** and add **-ObjC** to **Other Linker Flags**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/Screen%20Shot%202015-07-06%20at%205.11.32%20PM_zpsjnuvxqnl.png)

####Init Facebook Login:
You need make sure **Facebook App ID**, **Facebook Display Name** and **URLSchemes**- Added your app's **.plist** file.

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-10_zpsftdwgsqi.png)

>You can [Getting Start Facebook for IOS](https://developers.facebook.com/docs/ios/getting-started) to get Infomation about how to Create a Facebook App and configure an Xcode project
>![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-15_zpsyrunzsrb.png)
>Add a **URL types** with **URLSchemes**
>![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-16_zpsedr73t0o.png)

Replace or add this code to our **Appdelegate** on function **onpenURL**
```sh
//INGAMGE this code will be implement at client appdelegate
// In order to process the response you get from interacting with the Facebook login process,
// you need to override application:openURL:sourceApplication:annotation:
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {
    
    // Call FBAppCall's handleOpenURL:sourceApplication to handle Facebook app responses
    BOOL wasHandled = [FBAppCall handleOpenURL:url sourceApplication:sourceApplication];
    
    // You can add your app-specific url handling code here if needed
    
    return wasHandled;
}
```

##How to init the SDK

In project navigation choose **UnityAppController.h** import Ingame SDK
```sh
#import "IngSDK.h"
#import "IngNavigationController.h"
#import <FacebookSDK/FacebookSDK.h>
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add8_zpsfj6eyjfv.png)

Because Ingame SDK use navigation controller, you must be change the default init _rootViewcontroller of Unity iOS project :

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add9_zpsgqyppngd.png)

You can see i replace **_window.rootViewController = _rootController** to 
```sh
_navigationController = [[IngNavigationController alloc] initWithRootViewController:_rootController];
_window.rootViewController = _navigationController;
```
on **showGameUI** function

And because unity change many viewcontroller before load game you must be get last _rootController and and set it for SDK init, i set it in **UnityAppController >> transitionToViewController** function:

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add10_zpslxavjhdx.png)

##Start Ingame SDK

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add11_zpsro5czjm8.png)

##Rebuild your project

Rebuild and run your project. You'll see after screen, you did init success ingameSDK. If not, please contact IngameSDK developer team to get Support

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/3_zpswhknm0j4.png)

##Make payment on your Game

Add this code when you will call to payment of Ingame SDK
```sh
[[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID"];
```
Example:
```sh
- (IBAction)onPayment:(id)sender {
    [[IngSDK getInstance] showPaymentWithOrder:@"12345"];
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/4_zpsmcecgsom.png)

##Ingame SDK callbacks functions

To register for Ingame SDK events, add **notifications** on a **Viewcontroller** (gameRootViewController) when it init or loaded

In this case you can see i add it in **startUnity** function of **UnityAppController** 
```sh
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLoginSuccess:) name:onUserLoginSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLogoutSuccess:) name:onUserLogoutSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserUpdateSuccess:) name:onUserUpdateSuccess object:nil];
    
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPostFacebookSuccess:) name:onPostFacebookSuccess object:nil];
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add12_zpswpdt6s4w.png)

And affter that, create callback functions:
```sh
#pragma IngameSDK Notifications
- (void) onUserLoginSuccess:(NSNotification *) NotifiUserInfo {
    NSString* username = [NotifiUserInfo.userInfo objectForKey:IGUserNameKey];
    NSNumber* userid = [NotifiUserInfo.userInfo objectForKey:IGUserIdKey];
    NSString* useraccesstoken = [NotifiUserInfo.userInfo objectForKey:IGUserAccessTokenKey];
    
    NSLog(@"Main view callback Login User:%@ and UserID is :%d and accesstoken: %@",username,[userid intValue],useraccesstoken);
}

- (void) onUserLogoutSuccess:(NSNotification *) NotifiUserInfo {
    NSString* username = [NotifiUserInfo.userInfo objectForKey:IGUserNameKey];
    NSNumber* userid = [NotifiUserInfo.userInfo objectForKey:IGUserIdKey];
    NSString* useraccesstoken = [NotifiUserInfo.userInfo objectForKey:IGUserAccessTokenKey];
    
    NSLog(@"Main view callback Logout User:%@ is and UserID is :%d and accesstoken: %@",username,[userid intValue],useraccesstoken);
}

- (void) onUserUpdateSuccess:(NSNotification *) NotifiUserInfo {
    NSString* username = [NotifiUserInfo.userInfo objectForKey:IGUserNameKey];
    NSNumber* userid = [NotifiUserInfo.userInfo objectForKey:IGUserIdKey];
    NSString* useraccesstoken = [NotifiUserInfo.userInfo objectForKey:IGUserAccessTokenKey];
    
    NSLog(@"Main view callback Update User:%@ is and UserID is :%d and accesstoken: %@",username,[userid intValue],useraccesstoken);
}

- (void) onPostFacebookSuccess:(NSNotification *) NotifiUserInfo {
    NSMutableArray* friends = [NotifiUserInfo.userInfo objectForKey:IGFriendsKey];
    
    NSLog(@"Main view callback post succcess with number of friends %d", (int)friends.count);
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add4_zps8hl7ptch.png)

##Call Function from game without use IngSDK Button
Normally, user can open more games, share game or logout account with their friends when they tap on IngSDK Button. But you can call those functions via IngSDK. For example:

```sh
- (IBAction)onTapLogout:(id)sender {
    [[IngSDK getInstance] logOut];
}

- (IBAction)onTapLogin:(id)sender {
    [[IngSDK getInstance] logIn];
}

- (IBAction)onTapShare:(id)sender {
    [[IngSDK getInstance] shareGame];
}

- (IBAction)onTapMoregame:(id)sender {
    [[IngSDK getInstance] getMoreGame];
}

- (IBAction)onTapUserInfo:(id)sender {
    [[IngSDK getInstance] showUserInfo];
}

```

##Start Appflyer Tracking

Go to **AppDelegate > applicationDidBecomeActive** function

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add13_zpssmorxeix.png)


License
----
Ingame Developer Team

**For Ingame IOS Unity Version**
