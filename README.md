#IOS Ingame Sdk Quick Start

##Introduction


This quick start shows you how to create a new iOS project, include the Ingame Mobile SDK.

##Prerequisites
* Xcode 5.1 or higher
* Deployment target of 6.0 or higher

##Creating a new project


In this step, we'll create a brand new project in Xcode. If you don't already have Xcode running, go ahead and open it now.

###Create a new Xcode project
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-00_zpscvrpwyng.png)

Navigate to **File > New > Project**. Select **Single View Application** under iOS applications, and click **Next**.

###Name your project
![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-01_zpsxpixhab9.png)

Give your project the name "IngameSDKExample". Make sure you're also using the language "Objective-C". Then click **Next**.

###Select a project location

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-02_zpsfezqloul.png)

Select a location for your project, and click Create to finish creating a new project.

###Build and run your new project

To use a simulator, navigate to **Product > Destination** and select an iPhone simulator. Then select **Product > Run** to verify your app builds and runs. The app shows just a blank white screen for now. But don't worry, we'll add content in the next steps.

##Adding the SDK to your Xcode project

###Using the SDK download

If you don't already have the Ingame Mobile SDK, grab it from the [downloads page](https://github.com/InGameVietnam/iOS-InGameSDKLib/archive/master.zip) and unzip it.

####Add Library

First copy the library folder to your ios project navigation

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-03_zpsunwmsc7f.png)

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-04_zpsstzczgzb.png)

Second go to **IngameSDKExample project navigation > Build Phases > Link Binary With Libraries** click **Add > Add Others**

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-05_zpsv0i4wadw.png)

Browse to **libInGameSDK.a** and add it to project

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-06_zpslazl6fve.png)

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

####Add IngameSDK Resources to project

Go to **IngameSDKExample project navigation > Build Phases > Copy Bundle Resources** click **Add button > Add Others** and browse to **INGResources.bundle**

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-07_zpstpmoddsy.png)

Check **Copy items if needed** and choose **Create groups**

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-08_zps0bylorfz.png)

And Result

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-09_zpsoxtn14ak.png)

Next step Right click to **IngameSDKExample -> Add Files to IngameSDKExample**, browse to **IngameSDK/include/InGameSDK** folder

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-10_zpshpegbqrl.png)

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-11_zpssdqg4au1.png)

Check **Copy items if needed** and choose **Create groups**

And Result

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-12_zpscwvxcz08.png)

####Config Project Setting:
In project navigation goto **Project target > Build Settings Tab > Linking** and add **-ObjC** to **Other Linker Flags**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/Screen%20Shot%202015-07-06%20at%205.11.32%20PM_zpsjnuvxqnl.png)

####Init Facebook Login:
You need make sure **Facebook App ID**, **Facebook Display Name** and **URLSchemes**- Added your app's **.plist** file.

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

Open **AppInfor.plist** in **INGResources.bundle** and replace right information at here. Please contact to the supporter to get right infomation.

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add1_zps9wris7nu.png)

In project navigation choose **Appdelegate.m**

Import IngameSDK
```sh
#import "include/InGameSDK/IngSDK.h"
#import "include/InGameSDK/IngNavigationController.h"
```
and after that init IngameSDK on **didFinishLaunchingWithOptions** function
```sh
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    
    MainView *gameViewController = [[MainView alloc] initWithNibName:@"MainView" bundle:nil];
    
    IngNavigationController *navigation = [[IngNavigationController alloc]initWithRootViewController:gameViewController];
    //[navigation setAppOrientation:UIInterfaceOrientationMaskLandscapeLeft];
    self.window.rootViewController = navigation;
    [navigation setNavigationBarHidden:YES];
    
    [self.window makeKeyAndVisible];
    return YES;
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add2_zpsd5duyryr.png)

>In normally, Ingame SDK will be auto detect game screen orientation and fix the Ingame SDK UI for this orientation, but sometime (perhaps because the game engine) Ingame SDK cannot get right game screen orientation, in this case you will hard code to set right rotation of game screen. you can see above code:
```sh
[navigation setAppOrientation:UIInterfaceOrientationMaskLandscapeLeft];
```
##Start SDK in your project
You will call function **startSDK** just one when app or game started or loaded

For Example: I start SDK when viewDidLoad function

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add3_zpskmtne9kq.png)

##Rebuild your project

Rebuild and run your project. You'll see after screen, you did init success ingameSDK. If not, please contact IngameSDK developer team to get Support

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/3_zpswhknm0j4.png)

##Make payment on your Application

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

In this case you can see i add it in **viewDidLoad** function of **Viewcontroller** 
```sh
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLoginSuccess:) name:onUserLoginSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLogoutSuccess:) name:onUserLogoutSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserUpdateSuccess:) name:onUserUpdateSuccess object:nil];
    
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPostFacebookSuccess:) name:onPostFacebookSuccess object:nil];
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add3_zpskmtne9kq.png)

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

**For Ingame IOS Version**
