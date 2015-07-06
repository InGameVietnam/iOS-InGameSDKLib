//
//  LoginController.h
//  InGameSDK
//
//  Created by Quoc Tran Cong on 6/19/15.
//  Copyright (c) 2015 Ingame. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FacebookSDK/FacebookSDK.h>

#import "IngSDK.h"

#import "PublicVars.h"
#import "ServiceAPI.h"

@interface LoginController : UIViewController <ServiceAPIDelegate, UITextFieldDelegate> {
    PublicVars *PublicInstance;
    ServiceAPI *ServiceInstance;
    
    UserInfor* currentUser;
    NSMutableArray * allPreviousUsers;

    UITextField* activeTextField;
}

@property (nonatomic, weak) id <IngSDKDelegate> IGDelegate; //define MyClassDelegate as delegate
@property (weak, nonatomic) IBOutlet UIImageView *IM_Loading;

@property (weak, nonatomic) IBOutlet UITextField *TF_Username;
@property (weak, nonatomic) IBOutlet UITextField *TF_Password;
@property (weak, nonatomic) IBOutlet UILabel *LB_Version;
@property (weak, nonatomic) IBOutlet UILabel *LB_Title;
@property (weak, nonatomic) IBOutlet UIButton *BT_DangNhap;
@property (weak, nonatomic) IBOutlet UIButton *BT_Fogotpass;
@property (weak, nonatomic) IBOutlet UILabel *LB_quicklogin;
@property (weak, nonatomic) IBOutlet UIButton *BT_DangKy;
@property (weak, nonatomic) IBOutlet UIButton *BT_Language;

@property (weak, nonatomic) IBOutlet UIScrollView *SV_Container;


- (void) requestLoginWithUserInfor:(UserInfor*) _userinfor;
- (void) requestRegisterWithUserInfor:(UserInfor*) _userinfor;
- (void) reRequestWithCaptcha;

@end
