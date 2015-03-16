//
//  SDKViewController.h
//  InGameSDK
//
//  Created by Rentracks Mac Computer on 1/14/15.
//  Copyright (c) 2015 VuongTC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UserInfor.h"

@class SDKViewController;             //define class, so protocol can see MyClass
@protocol SDKViewControllerDelegate <NSObject>   //define delegate protocol
- (void) tapScreen: (SDKViewController *) sender;  //define delegate method to be implemented within another class
- (void) adjustViewsForOrientation: (UIInterfaceOrientation) orientation;
@end //end protocol


@protocol IngameSDKDelegate <NSObject>

@optional
- (void) onUserLoginSuccess:(UserInfor*) userInfo;
- (void) onUserLogoutSuccess:(UserInfor*) userInfo;

@end

@interface SDKViewController : UIViewController {
    UIViewController* mainview;
}

+ (id) getInstance;

@property (nonatomic, weak) id <SDKViewControllerDelegate> delegate; //define MyClassDelegate as delegate
@property (nonatomic, weak) id <IngameSDKDelegate> IGDelegate; //define MyClassDelegate as delegate

@property (weak, nonatomic) IBOutlet UIView *containerLarge;
@property (weak, nonatomic) IBOutlet UIView *containerSmall;
@property (weak, nonatomic) IBOutlet UIScrollView *containerLargeScrollView;
@property (weak, nonatomic) IBOutlet UIScrollView *containerSmallScroolView;

- (id) initWithMainView:(UIViewController*) _mainview;

- (void) setGameCallbackURL:(NSString*) urlString;

//- (void) showLoginOnView:(UIViewController*) mainView enableQuiclogin:(BOOL) enableQuicklogin;
- (void) showUserInfoOnView:(UIViewController*) mainView;
- (void) showSDKView:(UIViewController*) mainView;
- (void) showCaptchaView;
- (void) showPaymentWithOrder:(NSString*) gameOrder;

- (void) onUserLogoutCallback;
- (void) onUserLoginFailCallback;
- (void) onLoginSuccessWithUserName:(NSString *)username andPassWord:(NSString *)password;
- (void) close;
- (void) closeWithErrors;

@property (strong, nonatomic) IBOutlet UILabel *LB_HelloUser;
@property (strong, nonatomic) IBOutlet UIButton *BT_Login;

@property (strong, nonatomic) UIActivityIndicatorView *spinner;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *heightConstrainsLargeView;

- (void) moveButtonToCenter;

@end
