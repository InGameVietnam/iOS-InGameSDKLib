//
//  ViewController.m
//  IngameSDKExample
//
//  Created by Quoc Tran Cong on 3/13/15.
//  Copyright (c) 2015 Quoc Tran Cong. All rights reserved.
//

#import "ViewController.h"
#import "IngSDK.h"
#import "IngNavigationController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[IngSDK getInstance] startSDK];
    
    //add notification to call back sdk functions
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLoginSuccess:) name:onUserLoginSuccess object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserLogoutSuccess:) name:onUserLogoutSuccess object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onUserUpdateSuccess:) name:onUserUpdateSuccess object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPostFacebookSuccess:) name:onPostFacebookSuccess object:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

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


- (IBAction)onTapMoregame:(id)sender {
    [[IngSDK getInstance] getMoreGame];
}

- (IBAction)onTapLogout:(id)sender {
    [[IngSDK getInstance] logOut];
}

- (IBAction)onTapShare:(id)sender {
    [[IngSDK getInstance] shareGame];
}

- (IBAction)onPayment:(id)sender {
    [[IngSDK getInstance] showPaymentWithOrder:@"GameOrderID1"];
}

@end
