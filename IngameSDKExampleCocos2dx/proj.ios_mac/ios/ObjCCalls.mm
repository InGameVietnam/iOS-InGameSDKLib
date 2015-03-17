//
//  ObjCCalls.cpp
//  GameBlastar
//
//  Created by Lion User on 04/04/2013.
//
//

#include "ObjCCalls.h"
#import "Supporter.h"
#import "RootViewController.h"


void ObjCCalls::makePayment()
{
    //[[AppController sharedAppController] showBannerView];
    //[RootViewController loadAdmob];
    [((RootViewController*)[Supporter getRootViewController]) makePayment];
}








