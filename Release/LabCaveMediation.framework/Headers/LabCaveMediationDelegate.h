//
//  LabCaveMediationDelegate.h
//  LabCaveMediationLayer
//
//  Created by LabCaveGames on 24/2/17.
//  Copyright © 2017 Lab Cave Apps S.L. All rights reserved.
//

#import "LMLBannerView.h"
#define DEPRECATED_ATTRIBUTE        __attribute__((deprecated))
#define DEPRECATED_MSG(msg) __attribute((deprecated((msg))))
/**
 *  Advert Type
 */
typedef NS_ENUM(NSUInteger, LMLType) {
    LMLUnknownFormat = 99,
    /**
     *  Banner
     */
    LMLBannerFormat = 0,

    /**
     *  Interstitial
     */
    LMLInterstitialFormat,

    /**
     *  Video
     */
    LMLVideoFormat,

    /**
     *  RewardedVideo
     */
    LMLRewardedVideoFormat
};

/**
 * LabCaveGamesDelegate
 */
@protocol LMLDelegate

@optional

/**
 *  Mediation Initialized
 *
  */
- (void)labCaveMediationInitialized:(BOOL)state;

/**
 *  Advert Loaded
 *
 */
- (void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type zone:(NSString *)zoneId;

/**
 *  Advert Did Present Screen
 *
 */
- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone;

/**
 *  Advert Did Interact
 *
 */
- (void)advertDidInteract:(NSString *)provider type:(LMLType)type zone:(NSString *)zone;

/**
 * Advert Web View Did Close
 */
- (void)advertDidClose:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;

/**
 * Advert Request Fail
 */
- (void)advertsRequestFail:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;

/**
 * Reward user
 */
- (void)rewardUser:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;

@end
