#Include IOS IngameSDK to Cocos2dx project

##Introduction

This tutorial shows you how to include the Ingame Mobile SDK to cocos2dx project.

##Prerequisites
* Xcode 5.1 or higher
* Deployment target of 6.0 or higher
* A Cocos2d-x 2.2.x project or higher ([How to create cocos2d-x Project](http://www.cocos2d-x.org/wiki/How_to_Start_A_New_Cocos2D-X_Game))

##Adding the SDK to your Cocos2d-X project
The first time you must have a cocos2d-x project. If you don't have, you can [create a new cocos2d-x project](http://www.cocos2d-x.org/wiki/How_to_Start_A_New_Cocos2D-X_Game) and use it to include Ingame Mobile SDK. In this tutorial I create new Cocos2d-x project with name **IngameSDKExampleCocos2dx**.
###Using the SDK download
If you don't already have the Ingame Mobile SDK, grab it from the [downloads page](https://github.com/InGameVietnam/iOS-InGameSDKLib/archive/master.zip) and unzip it.

####Add the library

First copy the library folder to your ios project navigation

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-00_zpsivxg2qgv.png)

Second go to **IngameSDKExampleCocos2dx project navigation > IngameSDKExampleCocos2dx iOS target > Build Phases > Link Binary With Libraries** click **Add > Add Others**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-01_zpsf30bealy.png)

Browse to **libInGameSDK.a** and add it to project

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-02_zpsnyb5o0hp.png)
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-03_zpsnjss0oz8.png)

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

####Add IngameSDK Resources to project

Go to **IngameSDKExampleCocos2dx project navigation > IngameSDKExampleCocos2dx iOS target > Build Phases > Copy Bundle Resources** click **Add button > Add Others** and browse to **INGResources.bundle**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-04_zpsokwjj0p2.png)
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-05_zpssyrycum8.png)

Next step Right click to **IngameSDKExampleCocos2dx/ios -> Add Files to IngameSDKExampleCocos2dx**, browse to **IngameSDK/include/InGameSDK** folder

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-06_zpskoj7nczn.png)

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

In project navigation choose **AppController.mm**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-07_zpsdbgcfq0f.png)

First Import **SDKViewcontroller** of IngameSDK
```sh
#import "SDKViewController.h"
```
And after init IngameSDK on **didFinishLaunchingWithOptions** function
```sh
//init ingame SDK on rootviewcontroller
SDKViewController *sdkIngame = [[SDKViewController getInstance] initWithMainView:self];
//set your callback url
[sdkIngame setGameCallbackURL:@"www.example.YourCallbackURL.com"];
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-081_zpsu7s4e7vq.png)

##Rebuild your project

Rebuild and run your project. You'll see after screen, you did init success ingameSDK. If not, please contact IngameSDK developer team to get Support

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-09_zpscfwskehl.png)

##Make payment on your Game

Add this code when you will call to payment of Ingame SDK
```sh
[[SDKViewController getInstance] showPaymentWithOrder:@"YourGameOrderID"];
```
Example:
```sh
- (IBAction)onPayment:(id)sender {
    [[SDKViewController getInstance] showPaymentWithOrder:@"YourGameOrderID"];
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-cocos2dx-11_zpsuebpnbqw.png)

##IngameSKDDelegate implementation

To register for Ingame SDK events, set the delegate property on a Viewcontroller to an object that implements the **IGDelegate** protocol. Generally, the class that implements Ingame SDK will also act as the delegate class, in which case the delegate property can be set to **self** or a **viewController**.

```sh
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    MainView *viewController = [[MainView alloc] initWithNibName:@"MainView" bundle:nil];
    //UINavigationController *navigation = [[UINavigationController alloc]initWithRootViewController:viewController];
    self.window.rootViewController = viewController;
    
    SDKViewController *sdkIngame = [[SDKViewController getInstance] initWithMainView:viewController];
    [sdkIngame setGameCallbackURL:@"www.yourCallbackURL.example.com"];
    // set a delegate for callbacks
    sdkIngame.IGDelegate = viewController;
    
    [self.window makeKeyAndVisible];
    return YES;
}
```
```sh
@interface MainView : UIViewController <IngameSDKDelegate>

@end
```

####The last
#####Hide status bar
Add **View controller-based status bar appearance** with value **NO** to our **infor.plist** file

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-19_zpsvb6b0vi7.png)


###Implementing login, logout events

Each of the methods in IGDelegate are marked as optional, so you only need to implement the methods you want. This example implements each method and logs a message to the console.
```sh
- (void) onUserLoginSuccess:(UserInfor *)userInfo {
    NSLog(@"Main view callback User:%@ is Login",[userInfo getUserName]);
}

- (void) onUserLogoutSuccess:(UserInfor *)userInfo {
    NSLog(@"Main view callback User:%@ is Logout",[userInfo getUserName]);
}
```
>Through the **userInfo** variable you can get account information by calling the following functions:<br/>
userInfo.getUserName(): Username<br/>
userInfo.getUserId(): Account ID<br/>
userInfo.getAccessToken(): Access token<br/>
userInfo.getEmail(): Email<br/>
userInfo.getPhone(): Phone number<br/>

License
----
Ingame Developer Team

**For Ingame IOS Version**
