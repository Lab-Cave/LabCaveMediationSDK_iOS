//
//  IAUnitDelegate.h
//  IASDKCore
//
//  Created by Inneractive on 14/03/2017.
//  Copyright © 2017 Inneractive. All rights reserved.
//

#ifndef IAUnitDelegate_h
#define IAUnitDelegate_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IAUnitController;

@protocol IAUnitDelegate <NSObject>

@required

/**
 *  @brief Required delegate method for supplying parent view controller. App will crash, if it is not implemented in delegate and delegate declares itself as conforming to protocol.
 *
 *  @discussion The 'modalPresentationStyle' property of the supplied view controller will be changed to 'UIModalPresentationFullScreen';
 */
- (UIViewController * _Nonnull)IAParentViewControllerForUnitController:(IAUnitController * _Nullable)unitController; 

@optional
- (void)IAAdDidReceiveClick:(IAUnitController * _Nullable)unitController;
- (void)IAAdWillLogImpression:(IAUnitController * _Nullable)unitController;

- (void)IAUnitControllerWillPresentFullscreen:(IAUnitController * _Nullable)unitController;
- (void)IAUnitControllerDidPresentFullscreen:(IAUnitController * _Nullable)unitController;
- (void)IAUnitControllerWillDismissFullscreen:(IAUnitController * _Nullable)unitController;
- (void)IAUnitControllerDidDismissFullscreen:(IAUnitController * _Nullable)unitController;

- (void)IAUnitControllerWillOpenExternalApp:(IAUnitController * _Nullable)unitController;

@end

#endif /* IAUnitDelegate_h */
