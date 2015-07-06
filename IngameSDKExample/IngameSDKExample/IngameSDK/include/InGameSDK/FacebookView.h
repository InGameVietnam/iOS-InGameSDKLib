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

//@protocol FacebookViewDelegate <NSObject>   //define delegate protocol
//    - (void) onGetFacebookFriendListSuccess:(NSMutableArray*) friendlist;
//@end //end protocol


@interface FacebookView : UIViewController<SDKViewControllerDelegate,UITableViewDelegate,UITableViewDataSource,UISearchBarDelegate> {
    SDKViewController* mainView;
    UIScrollView* containerView;
    
    UIActivityIndicatorView* indicatior;
    
    NSMutableArray* tableDataArray;
    
    NSMutableArray *friendlist;
    NSMutableArray *friendselected;
    NSMutableArray *friend_searchresult;
    
    BOOL isFiltered;
    
    BOOL onLogoutFb;
}

+ (id) getInstance;

- (void) setSDKViewController:(SDKViewController*) sdkViewController;

//@property (nonatomic, weak) id <FacebookViewDelegate> fbdelegate; //define MyClassDelegate as delegate

@property (weak, nonatomic) IBOutlet UITableView *TB_FriendList;
@property (weak, nonatomic) IBOutlet UITextView *TV_FriendSelected;
@property (weak, nonatomic) IBOutlet UIButton *BT_Share;
@property (weak, nonatomic) IBOutlet UIButton *BT_Close;
@property (weak, nonatomic) IBOutlet UITableView *S_SearchName;


//- (void) getFacebookFriendList;

- (void) requestFacebookFriendList;

@end
