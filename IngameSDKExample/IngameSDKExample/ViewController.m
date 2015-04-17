//
//  ViewController.m
//  IngameSDKExample
//
//  Created by Quoc Tran Cong on 3/13/15.
//  Copyright (c) 2015 Quoc Tran Cong. All rights reserved.
//

#import "ViewController.h"

//import ingameSDK
#import "SDKViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    //init ingame SDK on rootviewcontroller
    NSString* deviceID = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    NSLog(@"getted device ID: %@",deviceID);
    SDKViewController *sdkIngame = [[SDKViewController getInstance] initWithMainView:self];
    //set your callback url
    [sdkIngame setGameCallbackURL:@"www.yourcallbackURL.com"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
