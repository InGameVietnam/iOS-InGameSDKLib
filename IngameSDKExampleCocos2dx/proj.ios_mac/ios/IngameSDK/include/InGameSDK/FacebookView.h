//
//  FacebookView.h
//  InGameSDK
//
//  Created by Quoc Tran Cong on 4/28/15.
//  Copyright (c) 2015 Ingame. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FacebookSDK/FacebookSDK.h>
#import "SDKViewController.h"

@interface FacebookView : UIViewController<SDKViewControllerDelegate,UITableViewDelegate,UITableViewDataSource,UISearchBarDelegate> {
    SDKViewController* mainView;
    UIScrollView* containerView;
    
    UIActivityIndicatorView* indicatior;
    
    NSMutableArray* tableDataArray;
    
    NSMutableArray *friendlist;
    NSMutableArray *friendselected;
    NSMutableArray *friend_searchresult;
    
    BOOL isFiltered;
}

+ (id) getInstance;

- (void) setSDKViewController:(SDKViewController*) sdkViewController;

@property (weak, nonatomic) IBOutlet UITableView *TB_FriendList;
@property (weak, nonatomic) IBOutlet UITextView *TV_FriendSelected;
@property (weak, nonatomic) IBOutlet UIButton *BT_Share;
@property (weak, nonatomic) IBOutlet UIButton *BT_Close;
@property (weak, nonatomic) IBOutlet UITableView *S_SearchName;


//- (void) getFacebookFriendList;


@end
