//
//  ServiceAPI.h
//  InGameSDK
//
//  Created by VuongTC on 1/31/15.
//  Copyright (c) 2015 VuongTC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardInfo.h"
#import "UserInfor.h"

@protocol ServiceAPIDelegate <NSObject>

@required
- (void) showLoading;
- (void) hideLoading;
- (void) closeWithErrors:(int) error_code;

@optional
- (void) showCaptcha;

- (void) onRequestLoginFinish:(NSDictionary*) dict;
- (void) onRequestLoginFail:(NSString*) message;
- (void) onRequestLoginWithFaceBookFinish:(NSDictionary*) dict;
- (void) onRequestLoginWithDeviceIdFinish:(NSDictionary*) dict;

- (void) onRequestLogoutFinish:(NSDictionary*) dict;
- (void) onRequestRegisterFinish:(NSDictionary*) dict;
- (void) onRequestRegisterFail;

- (void) onRequestFogotPassFinish:(NSDictionary*) dict;

//callback user info
- (void) onRequestUpdateUserInfoFinish:(NSDictionary*) dict;
- (void) onRequestTransactionLogWithUserInfoFinish:(NSDictionary*) dict;

//callback payment
- (void) onRequestCardPaymentWithCardinfoFinish:(NSDictionary*) dict;
- (void) onRequestGetConfigWithUserInfoFinish:(NSDictionary*) dict;
- (void) onRequestBankPaymentWithAmountFinish:(NSDictionary*) dict;
- (void) onRequestApplePaymentFinish:(NSDictionary*) dict;
- (void) onRequestBankPaymentConfirmWithTransactionReceiptFinish:(NSDictionary*) dict;

- (void) onRequestCaptCharFinish:(NSData*) imgData;

- (void) onRequestFailWithAPI:(NSString*) APTString;

//callback request more game
- (void) onRequestMoreGameFinish:(NSDictionary*) dict;
- (void) onRequestShareGameFinish:(NSDictionary*) dict;

@end


@interface ServiceAPI : NSObject {
    NSString *currentRequest;
    NSString *captchaRequest;
    NSMutableDictionary* currentDictPost;
}

+ (id)shareAPI;
//+ (BOOL)extractIdentity:(SecIdentityRef *)outIdentity andTrust:(SecTrustRef*)outTrust fromPKCS12Data:(NSData *)inPKCS12Data;

@property (nonatomic, weak) id <ServiceAPIDelegate> delegate_service;


@property (strong, nonatomic) NSDictionary* SynsRequestDict;


- (NSDictionary*) requestRefreshWithUser:(UserInfor*) userinfo;

//login request
- (void) requestLoginWithUserName:(NSString*) username andPassWord:(NSString*) password;
- (void) requestLoginWithFaceBook:(NSString*) facebook_token;
- (void) requestLoginWithDeviceId;

- (void) requestLogoutWithUser:(UserInfor*)userinfor;
- (void) requestRegisterWithUser:(UserInfor*)userinfor;

- (void) requestFogotWithUserName:(NSString*)username andPhone:(NSString*)phone;
- (void) requestFogotWithUserName:(NSString*)username andEmail:(NSString*)email;

//userinfo request
- (void) requestUpdateUserInfo:(UserInfor*) userinfo;
- (void) requestTransactionLogWithUserInfo:(UserInfor*) userinfo;

//payment request
- (void) requestGetConfigWithUserInfo:(UserInfor*) userinfo;
- (void) requestCardPaymentWithCardinfo:(CardInfo*) card ofUser:(UserInfor*) user andGameOrder:(NSString*) gameOrder;
- (void) requestBankPaymentWithAmount:(NSString*) amount ofUser:(UserInfor*) user andGameOrder:(NSString*) gameOrder;
- (void) requestApplePaymentWithReceipt:(NSString*) receipt andPassword:(NSString*) password ofUser:(UserInfor*) user forProductId:(NSString*)productId andGameOrder:(NSString*) gameOrder;
- (void) requestBankPaymentConfirmWithTransactionReceipt:(NSString *)receipt ofUser:(UserInfor*) user;
- (void) requestMoreGame;
- (void) requestShareGame;

//request captcha
- (void) requestCaptChar;

- (void) reRequestToServer;


@end
