//
//  IngNavigationController.h
//  InGameSDK
//
//  Created by Quoc Tran Cong on 7/3/15.
//  Copyright (c) 2015 Ingame. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IngNavigationController : UINavigationController {
    UIInterfaceOrientationMask AppOrientation;

}

- (void) setAppOrientation:(UIInterfaceOrientationMask) orientation;

@end
