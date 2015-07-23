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

Open **AppInfor.plist** in **INGResources.bundle** and replace right information at here. Please contact to the supporter to get right infomation.

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add1_zps9wris7nu.png)

In project navigation choose **AppController.mm**

**Import IngameSDK**
```sh
#import "include/InGameSDK/IngSDK.h"
#import "include/InGameSDK/IngNavigationController.h"
```
And after that init IngameSDK on **didFinishLaunchingWithOptions** function
```sh
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    

    cocos2d::Application *app = cocos2d::Application::getInstance();
    app->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();
    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];

    // Init the CCEAGLView
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: [window bounds]
                                         pixelFormat: (NSString*)cocos2d::GLViewImpl::_pixelFormat
                                         depthFormat: cocos2d::GLViewImpl::_depthFormat
                                  preserveBackbuffer: NO
                                          sharegroup: nil
                                       multiSampling: NO
                                     numberOfSamples: 0 ];
    
    // Enable or disable multiple touches
    [eaglView setMultipleTouchEnabled:NO];

    // Use RootViewController manage CCEAGLView 
    _viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    _viewController.wantsFullScreenLayout = YES;
    _viewController.view = eaglView;
    [Supporter setRootViewController:_viewController];
    IngNavigationController *navigation = [[IngNavigationController alloc]initWithRootViewController:_viewController];
    //use below code to fix orientation of game screen - remember use UIInterfaceOrientationMask_XXX_
    //[navigation setAppOrientation:UIInterfaceOrientationMaskLandscapeLeft];
    [navigation setNavigationBarHidden:YES];
    window.rootViewController = navigation;
    [_viewController loadView];
    
    [window makeKeyAndVisible];
    [[UIApplication sharedApplication] setStatusBarHidden:true];
    // IMPORTANT: Setting the GLView should be done after creating the RootViewController
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView(eaglView);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    app->run();
    return YES;
}
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add5_zpskawvxqcx.png)

>In normally, Ingame SDK will be auto detect game screen orientation and fix the Ingame SDK UI for this orientation, but sometime (perhaps because the game engine) Ingame SDK cannot get right game screen orientation, in this case you will hard code to set right rotation of game screen. you can see above code:
```sh
[navigation setAppOrientation:UIInterfaceOrientationMaskLandscapeLeft];
```
##Start SDK in your project
You will call function **startSDK** just one when app or game started or loaded

For Example: I start SDK when loadView function

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add6_zpssiehevzn.png)

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
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame/add6_zpssiehevzn.png)

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


License
----
Ingame Developer Team

**For Ingame IOS Version**
