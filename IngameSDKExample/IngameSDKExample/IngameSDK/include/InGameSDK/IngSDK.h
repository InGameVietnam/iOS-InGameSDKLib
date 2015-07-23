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
//appflyer tracking
#import "AppsFlyerTracker.h"

#define IGUserNameKey @"username"
#define IGUserIdKey @"userid"
#define IGUserAccessTokenKey @"useraccesstoken"
#define IGFriendsKey @"friends"

extern NSString *const onUserLoginSuccess;
extern NSString *const onUserLogoutSuccess;
extern NSString *const onUserUpdateSuccess;

extern NSString *const onPostFacebookSuccess;

@interface IngSDK : NSObject <ServiceAPIDelegate,AppsFlyerTrackerDelegate> {
    UIViewController* _RootViewController;
    
    UIStoryboard *mainStoryboard;
    
    UIViewController* menuViewController;
    UIViewController* loadingController;
    UIViewController* loginViewController;
    UIViewController* paymentViewController;
}

+ (id) getInstance;

@property (strong, nonatomic) UserInfor* currentUser;

@property (nonatomic, strong) UINavigationController* navigationController;

- (void) setRootViewController:(UIViewController*) rootView;
- (void) startSDK;
- (void) startSDKWithoutAutoLogin;
- (void) showPaymentWithOrder:(NSString*) gameOrder;
- (void) logOut;
- (void) logInWithAuto:(BOOL) autoLogin;
- (void) shareGame;
- (void) getMoreGame;
- (void) showUserInfor;

- (void) onAppFlyerTracking;

@end
