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

If you don't already have the Ingame Mobile SDK, grab it from the [downloads page](https://github.com/InGameVietnam/iOS-InGameSDKLib/archive/version-2.0.zip) and unzip it.

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
* MobileCoreServices
* libz.dylib
* SystemConfiguration
* CFNetwork
* StoreKit
* Security

The others (facebook framework):

* FBSDKShareKit.framework
* FBSDKLoginKit.framework
* FBSDKCoreKit.framework

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

**1. Configure Xcode Project**

Now configure the .plist for your project:

- Pick your app via the app selector below.
- In Xcode right-click your .plist file and choose "Open As Source Code".
- Copy & Paste the XML snippet into the body of your file (<dict>...</dict>).
```objc
<key>CFBundleURLTypes</key>
<array>
  <dict>
    <key>CFBundleURLSchemes</key>
    <array>
      <string>fb(The Game Facebook Id)</string>
    </array>
  </dict>
</array>
<key>FacebookAppID</key>
<string>(The game Facebook Id)</string>
<key>FacebookDisplayName</key>
<string>(The Game Name)</string>
```
```objc
<key>NSAppTransportSecurity</key>
<dict>
  <key>NSExceptionDomains</key>
  <dict>
    <key>facebook.com</key>
    <dict>
      <key>NSIncludesSubdomains</key> <true/>        
      <key>NSThirdPartyExceptionRequiresForwardSecrecy</key> <false/>
    </dict>
    <key>fbcdn.net</key>
    <dict>
      <key>NSIncludesSubdomains</key> <true/>
      <key>NSThirdPartyExceptionRequiresForwardSecrecy</key>  <false/>
    </dict>
    <key>akamaihd.net</key>
    <dict>
      <key>NSIncludesSubdomains</key> <true/>
      <key>NSThirdPartyExceptionRequiresForwardSecrecy</key> <false/>
    </dict>
  </dict>
</dict>
```

```objc
<key>LSApplicationQueriesSchemes</key>
    <array>
        <string>fbapi</string>
        <string>fbapi20130214</string>
        <string>fbapi20130410</string>
        <string>fbapi20130702</string>
        <string>fbapi20131010</string>
        <string>fbapi20131219</string>
        <string>fbapi20140410</string>
        <string>fbapi20140116</string>
        <string>fbapi20150313</string>
        <string>fbapi20150629</string>
        <string>fbauth</string>
        <string>fbauth2</string>
        <string>fb</string>
        <string>fb-messenger-api20140430</string>
        <string>fb-messenger-platform-20150128</string>
        <string>fb-messenger-platform-20150218</string>
        <string>fb-messenger-platform-20150305</string>
        <string>fb-messenger-api</string>
        <string>fbshareextension</string>
    </array>
```

**2. Connect Application Delegate**

To post process the results from Facebook Login or Facebook Dialogs (or any action that requires switching over to the native Facebook app or Safari) you need to conenct your **AppDelegate** to the **FBSDKApplicationDelegate**. In your **AppDelegate.m** add:
```objc
//  AppDelegate.m
#import <FBSDKCoreKit/FBSDKCoreKit.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [[FBSDKApplicationDelegate sharedInstance] application:application
    didFinishLaunchingWithOptions:launchOptions];
  return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
  return [[FBSDKApplicationDelegate sharedInstance] application:application
    openURL:url
    sourceApplication:sourceApplication
    annotation:annotation
  ];
}
```

**3. Add App Events and Log App Activations**

The SDK is installed and set up. To do so add the following code snippet to your **AppDelegate.m**:
```objc
//  AppDelegate.m
#import <FBSDKCoreKit/FBSDKCoreKit.h>
- (void)applicationDidBecomeActive:(UIApplication *)application {
  [FBSDKAppEvents activateApp];
}
```

##How to init the SDK

Open **AppInfor.plist** in **INGResources.bundle** and replace right information at here. Please contact to the supporter to get right infomation.

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add1_zps9wris7nu.png)

In project navigation choose **Appdelegate.m**

Import IngameSDK
```objc
#import "include/InGameSDK/IngSDK.h"
#import "include/InGameSDK/IngNavigationController.h"
```
and after that init IngameSDK on **didFinishLaunchingWithOptions** function
```objc
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
```objc
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
```objc
[[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID"];
```
or 
```objc
[[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID" andCallbackURL:@"yourCallbackURL"];
```


Example:
```objc
- (IBAction)onPayment:(id)sender {
    [[IngSDK getInstance] showPaymentWithOrder:@"12345"];
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/4_zpsmcecgsom.png)

##Ingame SDK callbacks functions

To register for Ingame SDK events, add **notifications** on a **Viewcontroller** (gameRootViewController) when it init or loaded

In this case you can see i add it in **viewDidLoad** function of **Viewcontroller** 
```objc
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLoginSuccess:) name:onUserLoginSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLogoutSuccess:) name:onUserLogoutSuccess object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserUpdateSuccess:) name:onUserUpdateSuccess object:nil];
    
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPostFacebookSuccess:) name:onPostFacebookSuccess object:nil];
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add3_zpskmtne9kq.png)

And affter that, create callback functions:
```objc
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

```objc
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

```objc
- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[IngSDK getInstance] onAppFlyerTracking];
    
    [FBSDKAppEvents activateApp];
}
```

And config two value from AppInfo.plist file:

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/Screen%20Shot%202015-09-17%20at%2010.04.09%20AM_zps8xqfxi1m.png)

- APPLE_APP_ID: this is apple app id from itunes connect
- APPFLYER_DEV_ID: this is appflyer dev id. you can get more information at (Appflyer Document)[https://support.appsflyer.com/entries/25458906-iOS-SDK-Integration-Guide-v3-3-x-New-API-]

License
----
Ingame Developer Team

**For Ingame IOS Version**
