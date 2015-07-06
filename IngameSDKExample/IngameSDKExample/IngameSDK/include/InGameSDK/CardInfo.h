//
//  CardInfo.h
//  InGameSDK
//
//  Created by VuongTC on 2/4/15.
//  Copyright (c) 2015 VuongTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardInfo : NSObject

@property (strong, nonatomic) NSString* pin;
@property (strong, nonatomic) NSString* serial;
@property int type;

@end
