//
//  FacebookController.h
//  InGameSDK
//
//  Created by Quoc Tran Cong on 4/27/15.
//  Copyright (c) 2015 Ingame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FacebookSDK/FacebookSDK.h>

@interface FacebookController : NSObject

+ (id) getInstance;

- (void) getFacebookFriendList;

@end
