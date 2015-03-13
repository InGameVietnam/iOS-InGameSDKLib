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

If you don't already have the Ingame Mobile SDK, grab it from the 
If you don't already have the Ingame Mobile SDK, grab it from the [downloads page](https://github.com/InGameVietnam/iOS-InGameSDKLib/archive/master.zip) and unzip it.
 and unzip it.

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

* MessageUI
* FacebookSDK
* MobileCoreServices
* libz.dylib
* SystemConfiguration

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

####Init Facebook Login:
Add our **FacebookAppID** with value **1430402833918343** to **Info.plist**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-15_zpsyrunzsrb.png)

Add a **URL types** with **URLSchemes** is **fb1430402833918343**

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-16_zpsedr73t0o.png)

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


In project navigation choose **ViewController.m**, this is **RootViewControler** of our Application and init IngameSDK

first Import IngameSDK
```sh
#import "SDKViewController.h"
```
and after init IngameSDK on **ViewDidLoad** function
```sh
//init ingame SDK on rootviewcontroller
SDKViewController *sdkIngame = [[SDKViewController getInstance] initWithMainView:self];
//set your callback url
[sdkIngame setGameCallbackURL:@"www.example.YourCallbackURL.com"];
```
![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-13_zpsxtkxudru.png)

The quickest way to add a reference is to open up **ViewController.m**, import the library.

If you init your **RootViewController** in **Appdelegate**

![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-14_zpshp8yfasa.png)

####The last
#####Hide status bar
Add **Status bar is initially hidden** with value **YES** and **View controller-based status bar appearance** with value **NO** to our **infor.plist** file

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-19_zpsvb6b0vi7.png)

>Because Ingame main button is white color, Pretty good view if you change background color of ViewControler is Black or Blue (dark color).


##Rebuild your project

Rebuild and run your project. You'll see after screen, you did init success ingameSDK. If not, please contact IngameSDK developer team to get Support

![add](http://i757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/iOS%20Simulator%20Screen%20Shot%20Mar%2013%202015%202.13.34%20PM_zpsue3bvzhv.png)

##Make payment on your Application


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
![add](http://s757.photobucket.com/albums/xx212/ichirokudo/Ingame%20iOS/ios-quickstart-18_zps4ag7lv7j.png)
License
----
Ingame Developer Team

**For Ingame IOS Version**
 
