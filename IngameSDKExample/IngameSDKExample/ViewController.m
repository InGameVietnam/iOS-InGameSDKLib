//
//  ViewController.m
//  IngameSDKExample
//
//  Created by Quoc Tran Cong on 3/13/15.
//  Copyright (c) 2015 Quoc Tran Cong. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    IngNavigationController *navigation = [[IngNavigationController alloc] initWithRootViewController:self];
    self.view.window.rootViewController = navigation;
    
    [navigation setNavigationBarHidden:YES];
    
    [[IngSDK getInstance] setRootViewController:self andCallbackURL:@"www.yourcallbackURL.com"];
    [[IngSDK getInstance] startSDK];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onTapLogout:(id)sender {
    [[IngSDK getInstance] logOut];
}

#pragma IGSDKDelegate
- (void) onUserLoginSuccess:(UserInfor*) userInfo {
    NSLog(@"UserName: %@",[userInfo getUserName]);
    NSLog(@"UserId: %d",[userInfo getUserId]);
}

- (void) onUserUpdateSuccess:(UserInfor *)userInfo {
    NSLog(@"UserName: %@",[userInfo getUserName]);
    NSLog(@"UserId: %d",[userInfo getUserId]);
}

- (void) onUserLogoutSuccess:(UserInfor*) userInfo {
    
}

- (void) onCloseSDKUI {
    
}

@end
