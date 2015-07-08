#Include IOS IngameSDK to Unity project

##Introduction

This tutorial shows you how to include the Ingame Mobile SDK to unity project.

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

![add](IMG_1)

The second go to **IngameSDKExampleUnity project navigation** right click on Classes group and choose **Add Files to IngameSDKExampleUnity**

![add](IMG_2)

After that, choose IngameSDK path and click add to unity project (remember choose **create groups** option in **Added folder**

![add](IMG_3)

Result:

![add](IMG_4)

####Add other frameworks that the SDK requires

The SDK depends on the following iOS development frameworks which may not already be part of your project:

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
![add](IMG_5)

Next go to **UnityAppController+ViewHandling** in **project navigation > classes > UI**
Import **IngSDK.h** and implement **IngSDKDelegate**

![add](IMG_6)

Because Ingame SDK use navigation controller, you must be change the default init _rootViewcontroller of Unity iOS project :

![add](IMG_7)

##Rebuild your project

Rebuild and run your project. You'll see after screen, you did init success ingameSDK. If not, please contact IngameSDK developer team to get Support

![add](IMG_8)

##Make payment on your Game

Add this code when you will call to payment of Ingame SDK
```sh
[[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID"];
```
Example:
```sh
- (IBAction)onPayment:(id)sender {
   [[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID"];
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-11_zpsuebpnbqw.png)

##IngameSKDDelegate implementation

To register for Ingame SDK events, set the delegate property on a Viewcontroller to an object that implements the **IGDelegate** protocol. Generally, the class that implements Ingame SDK will also act as the delegate class, in which case the delegate property can be set to **self** or a **viewController**.

And affter implement delegate of Ingame SDK int **gameRootViewController**

```sh
@interface MainView : UIViewController <IngameSDKDelegate>

@end
```
![add](IMG_9)

###Implementing login, logout events

Each of the methods in IngSDKDelegate are marked as optional, so you only need to implement the methods you want. This example implements each method and logs a message to the console.
```sh
- (void) onUserLoginSuccess:(UserInfor *)userInfo {
    NSLog(@"Main view callback User:%@ is Login",[userInfo getUserName]);
}

- (void) onUserLogoutSuccess:(UserInfor *)userInfo {
    NSLog(@"Main view callback User:%@ is Logout",[userInfo getUserName]);
}
```
>Through the **userInfo** variable you can get account information by calling the following functions:<br/>
userInfo.username: Username<br/>
userInfo.userId: Account ID<br/>
userInfo.access_token: Access token<br/>
userInfo.email: Email<br/>
userInfo.phone: Phone number<br/>

License
----
Ingame Developer Team

**For Ingame IOS Unity Version**
