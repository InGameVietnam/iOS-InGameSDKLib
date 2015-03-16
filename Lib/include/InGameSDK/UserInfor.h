//
//  UserInfor.h
//  InGameSDK
//
//  Created by VuongTC on 1/30/15.
//  Copyright (c) 2015 VuongTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserInfor : NSObject 

@property (strong, nonatomic) NSString* username;
@property (strong, nonatomic) NSString* password;
@property (strong, nonatomic) NSString* email;
@property (strong, nonatomic) NSString* phone;
@property (strong, nonatomic) NSString* access_token;
@property (strong, nonatomic) NSString* refresh_token;

- (id)init;
- (id)initWithUser:(NSString *)username andPass:(NSString*)pass;
- (id)initWithCoder:(NSCoder *)decoder;

- (void)encodeWithCoder:(NSCoder *)encoder;

- (NSString*) getUserName;
- (NSString*) getPassWord;
- (NSString*) getUserId;
- (NSString*) getAccessToken;
- (NSString*) getEmail;
- (NSString*) getPhone;

@end
