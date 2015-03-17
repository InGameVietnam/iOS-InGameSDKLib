//
//  Supporter.m
//
//  Created by Ingame Developer.
//
//

#import "Supporter.h"

UIViewController* rootViewController;

@implementation Supporter

+ (void) setRootViewController:(UIViewController*) view {
    rootViewController = view;
}

+ getRootViewController {
    return rootViewController;
}

@end
