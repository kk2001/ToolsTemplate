//
//  ToolsTemplateAppController.h
//  ToolsTemplate
//
//  Created by cesc on 14-3-21.
//  Copyright __MyCompanyName__ 2014年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

