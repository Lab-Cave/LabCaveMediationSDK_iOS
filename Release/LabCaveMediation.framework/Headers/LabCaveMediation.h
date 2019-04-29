//
//  LabCaveMediation.h
//  LabCaveMediation
//
//  Created by LabCaveGames on 21/2/17.
//  Copyright © 2017 Lab Cave Apps S.L. All rights reserved.
//
// LabCaveGames SDK 2.6.0

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import <AVFoundation/AVFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <ImageIO/ImageIO.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import "LabCaveMediationDelegate.h"
#import <UIKit/UIKit.h>

/**
 *  LabCaveGames
 */
@interface LabCaveMediation : NSObject

/**
 *  Init LabCaveGames Mediation
 *  @param appHash Your application identifier
 *  @autoFecth Set
 *  @param delegate will set the delegate that will be called
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)initWithAppHash:(NSString *)appHash delegate:(id<LMLDelegate>)delegate viewController:(UIViewController *)viewController;
/**
 *  ShowLabCaveGamesMediation
 *  @param delegate will set the delegate that will be called
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;

+ (void)showInterstitialAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;

+ (void)showRewardedVideoAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;

/**
 *  ShowLabCaveGamesMediation
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWitZone:(NSString *)zone viewController:(UIViewController *)viewController;

+ (void)showInterstitialAdWithZone:(NSString *)zone viewController:(UIViewController *)viewController;

+ (void)showRewardedVideoAdWithZone:(NSString *)zone viewController:(UIViewController *)viewController;

/**
 *  Check ad state
 */
+ (BOOL)isBannerReady;

+ (BOOL)isInterstitialReady;

+ (BOOL)isRewardedVideoReady;

/**
 *  Hide Ads
 */
+ (void)hideAds;

/**
 *  Show Test UIViewController
 *
 *  @param viewController The UIViewController that will present the Test UIViewController
 *  @param appHash Your application identifier
 */
+ (void)testMediationAds:(UIViewController *)viewController appHash:(NSString *)appHash;

/**
 *  Enable Logs
 *
 *  @param enabled Enabled
 */
+ (void)setLogEnabled:(BOOL)enabled;

+ (BOOL)isMediationInitiated;

/**
 *  Set Ads Placements
 *
 *  @param placements Placements
 */
+ (void)setBannerPlacements:(NSArray *)placements;

+ (void)setInterstitialsPlacements:(NSArray *)placements;

+ (void)setRewardedVideoPlacements:(NSArray *)placements;

/**
 *  Set User Consent
 *
 *  @param consent User Consent
 */

+ (void)setUserConsent:(BOOL)consent;

+ (BOOL)getUserConsent;
@end
