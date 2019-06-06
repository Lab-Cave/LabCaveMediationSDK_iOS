//
//  LabCaveMediation.h
//  LabCaveMediation
//
//  Created by LabCaveGames on 21/2/17.
//  Copyright © 2017 Lab Cave Apps S.L. All rights reserved.
//
// LabCaveGames SDK 2.8.0

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
 *  @param delegate will set the delegate that will be called
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)initWithAppHash:(NSString *)appHash delegate:(id<LMLDelegate>)delegate viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Banner ad
 *  @param delegate will set the delegate that will be called
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param bannerSettings set banner size
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone bannerSettings:(LMLBannerSettings*)bannerSettings viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Banner ad
 *  @param delegate will set the delegate that will be called
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Insterstitial ad
 *  @param delegate will set the delegate that will be called
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showInterstitialAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Rewarded Video ad
 *  @param delegate will set the delegate that will be called
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showRewardedVideoAdWithDelegate:(id<LMLDelegate>)delegate zone:(NSString *)zone viewController:(UIViewController *)viewController;

/**
 *  Show LabCaveGamesMediation Banner ad
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param bannerSettings set banner size
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWitZone:(NSString *)zone bannerSettings:(LMLBannerSettings*)bannerSettings viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Banner ad
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showBannerAdWitZone:(NSString *)zone viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Insterstitial ad
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showInterstitialAdWithZone:(NSString *)zone viewController:(UIViewController *)viewController;
/**
 *  Show LabCaveGamesMediation Rewarded Video ad
 *  @param zone string tag the zone of the app the ad will be showed
 *  @param viewController The UIViewController that will present the Ad
 */
+ (void)showRewardedVideoAdWithZone:(NSString *)zone viewController:(UIViewController *)viewController;

/**
 *  Check banner state
 */
+ (BOOL)isBannerReady;
/**
 *  Check interstitial state
 */
+ (BOOL)isInterstitialReady;
/**
 *  Check rewarded video state
 */
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

/**
 *  Check if mediation is initiated
 *
 * @return true if mediation is initiated
 */
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
/**
 *  Get User Consent
 *
 *  @return The User Consent
 */
+ (BOOL)getUserConsent;
/**
 *  Set banner param position
 *
 * @param bannerSettings Position of the banner TOP or BOTTOM and size
 */
+ (void)setBannerSettings:(LMLBannerSettings*)bannerSettings;
 /**
 *  Return banner position
 *
 * @return The banner position
 */
+ (LMLBannerSettings*)getBannerSettings;
@end
