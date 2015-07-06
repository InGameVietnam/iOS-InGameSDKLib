//
//  IngSDK.h
//  InGameSDK
//
//  Created by Quoc Tran Cong on 6/18/15.
//  Copyright (c) 2015 Ingame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UserInfor.h"
#import "ServiceAPI.h"
#import "AppsFlyerTracker.h"

@protocol IngSDKDelegate <NSObject>

@optional
- (void) onUserLoginSuccess:(UserInfor*) userInfo;
- (void) onUserLogoutSuccess:(UserInfor*) userInfo;
- (void) onUserUpdateSuccess:(UserInfor*) userInfo;

@end

@interface IngSDK : NSObject <ServiceAPIDelegate,AppsFlyerTrackerDelegate> {
    UIViewController* _RootViewController;
    
    UIStoryboard *mainStoryboard;
    
    UIViewController* menuViewController;
    UIViewController* loadingController;
    UIViewController* loginViewController;
    UIViewController* paymentViewController;

    UserInfor* currentUser;
}

+ (id) getInstance;

@property (nonatomic, weak) id <IngSDKDelegate> IGDelegate;

@property (nonatomic, strong) UINavigationController* navigationController;

- (void) setRootViewController:(UIViewController*) rootView andCallbackURL:(NSString*) callbackURL;
- (void) startSDK;
- (void) showPaymentWithOrder:(NSString*) gameOrder;
- (void) logOut;
- (void) logIn;
- (void) shareGame;
- (void) getMoreGame;

- (void) onAppFlyerTracking;

@end
