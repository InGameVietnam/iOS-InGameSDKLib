//
//  IngameButtonBoard.h
//  ButtonBoardTest

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol IngameButtonBoardDelegate <NSObject>

@optional

- (void)buttonBoardWillOpen;
- (void)buttonBoardDidOpen;
- (void)buttonBoardWillClose;
- (void)buttonBoardDidClose;

- (void)buttonBoardClickButtonAtIndex:(int)index;


@end

@class BoardView;

@interface IngameButtonBoard : NSObject<UIGestureRecognizerDelegate>{
    UIWindow        *_boardWindow;
    BOOL            _running;
    BoardView       *_boardView;
    CGRect          _boardRect;
    NSMutableArray  *_buttonArray;
    BOOL            _animating;
    BOOL            _movedWithKeyboard;
}

+ (IngameButtonBoard *)defaultButtonBoard;

@property bool canOpen;

@property (nonatomic,assign) id<IngameButtonBoardDelegate> delegate;

@property (nonatomic,assign)int     buttonNumber;

@property (nonatomic,assign)UIImage *boardImage;

@property (nonatomic,retain)NSArray *buttonImageArray;

@property (nonatomic,retain)NSArray *buttonTitleArray;

@property (nonatomic,assign)float boardSize;

@property (nonatomic,assign)BOOL    autoPosition;

@property (nonatomic,readonly)BOOL    running;

@property (nonatomic,readonly)BOOL      isOpen;

@property (nonatomic,readonly)CGRect    currentFrame;

- (void)startRunning;

- (void)stopRunning;

- (void)setBoardPosition:(CGPoint)point animate:(BOOL)animate;

- (void)setupDefault;

- (void)setUpButtons:(NSArray*) arrayButtons withTitles:(NSArray*) arrayTitles;

- (void)setTitleForButtons:(NSArray*) titleArray;

//for test bug
- (void)activeButton;

@end

extern NSString *const IngameButtonBoardWillOpenNotification;

extern NSString *const IngameButtonBoardDidOpenNotification;

extern NSString *const IngameButtonBoardWillCloseNotification;

extern NSString *const IngameButtonBoarDidCloseNotification;


//notification
extern NSString *const IngameButtonBoarButtonClickNotification;

//-------------------------------------------------------------------------//

@interface BoardView : UIView{
    CGPoint     _beginPoint;
    CGPoint     _selfBeginCenter;
    unsigned long     _direction;
}

@property unsigned long     _currentDir;
@property bool      isActive;

@property (nonatomic,assign)IngameButtonBoard *selfBoard;
@property (nonatomic,readonly)BOOL moving;
@property (nonatomic,retain)UIImageView *backgroundImageView;

- (int)directByPoint:(CGPoint)point;

- (CGFloat) getRightScreen;
- (CGFloat) getBottomScreen;

@end








