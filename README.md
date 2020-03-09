# LabCave Mediation iOS SDK

The current version (2.11.2) is tested with Xcode11 or above and is compatible with iOS 9 and above.

>Xcode11 is mandatory for building the project


## Adding Lab Cave Mediation SDK to your Project

1. Download our SDK from the release section or clone it. 
>If you decide to clone it, you have to install [git LFS](https://git-lfs.github.com/) to clone it correctly, otherwise some ad networks will not be correctly integrated. 
2. Add the following frameworks and libs to your project in General tab Linked Frameworks and Libraries. Ensure that the frameworks are linked correctly.

```
AdSupport.framework
AudioToolbox.framework
AVFoundation.framework
CFNetwork.framework
CoreGraphics.framework
CoreMedia.framework
CoreTelephony.framework
EventKit.framework
EventKitUI.framework
Foundation.framework
JavaScriptCore.framework
libc++.tbd
libsqlite3.tbd
libxml2.2.tbd
libz.1.2.5.tbd
MediaPlayer.framework
MobileCoreServices.framework
QuartzCore.framework
SafariServices.framework
Social.framework
StoreKit.framework
SystemConfiguration.framework
UIKit.framework
VideoToolbox.framework
WebKit.framework
WatchConnectivity.framework
```

3. Lastly, add the following values to the **Other Linker Flags** in the **Build Settings** tab: 

      -ObjC,-fobjc-arc

### Swift 

If your are working in swift you have to create a header file (.h) and add to your project, for example called "LabCave-Bridging-Header.h", and add this line of code to it:

```swift
#import <LabCaveMediation/LabCaveMediation.h>
```

Now in build settings tab in "Swift Compiler - General" in the field "Objective-C Bridging Header" add the file create above. Now you are ready to use the LabCaveMediation with Swift.

### Integrate Lab Cave Mediation Network Adapters

Lab Cave Mediation supports Banners, Interstitials and Video Rewarded from various leading ad networks, with advanced functionalities like ads auto-fetching and advanced delivery optimization. Add to your project the frameworks, depending on your selected Ad Networks, as you did in the previous step.

**IMPORTANT IF YOU ARE USING ADMOB**

Realize you need to also ad the GoogleAppMeasurement.framework, GoogleUtilities.framework and nanopb.framework and add a GADApplicationIdentifier key with a string value of your AdMob app ID to your app's Info.plist file. You can find your App ID in the AdMob UI.

````xml
<key>GADApplicationIdentifier</key>
<string>YOUR_ADMOB_APP_ID</string>
````
## Initialize the SDK

Once you have added all the files, it's time to initialize the SDK. 

**Important**: you have to initialize the SDK at the begining of the execution of your app. Make sure you **initiliase it only once**.

### Init the SDK

The SDK Initialisation can be done in two ways:

1. Initialize each Ad Format separately at different points of the game. ***Recommended*** to minimise the number of ads preloaded without showing an impression.

    You can bundle them in the same method

```swift
//Objective-C
[LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self adFormats:@[LML_INTERSTITIAL, LML_REWARDED_VIDEO]];

//Swift
LabCaveMediation.initWithAppHash("", delegate: self, viewController: self, adFormats: [LML_INTERSTITIAL, LML_REWARDED_VIDEO])
```

Or each of them separately

```swift
//Objective-C

[LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self adFormats:@[LML_BANNER]];

[LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self adFormats:@[LML_INTERSTITIAL]];

[LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self adFormats:@[LML_REWARDED_VIDEO]];

//Swift

LabCaveMediation.initWithAppHash("YOUR_APP_HASH", delegate: self, viewController: self, adFormats:[LML_BANNER])

LabCaveMediation.initWithAppHash("YOUR_APP_HASH", delegate: self, viewController: self, adFormats:[LML_INTERSTITIAL])

LabCaveMediation.initWithAppHash("YOUR_APP_HASH", delegate: self, viewController: self, adFormats:[LML_REWARDED_VIDEO])
```  

2. Alternatively, you can initiliase ALL of them at the same time with this method
```swift
    //Objective-C
    [LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self];

    //Swift
    LabCaveMediation.initWithAppHash(YOUR_APP_HASH", delegate: self, viewController: self)
 ```

The appHash is the hash ID of your app, you can get it in https://mediation.labcavegames.com/panel/apps, "viewController" is your viewController.

## Set Delegate


The SDK offers a listener where you can receive the events of the ads. 

```swift
// When the sdk is already initialized, if everything is ok, state will be true.
- (void)labCaveMediationInitialized:(BOOL)state
{
}
// Will be called when any ad is loaded, it will tell you the type LMLType.LMLBannerFormat, LMLType.LMLInterstitialFormat and LMLType.LMLRewardedVideoFormat
-(void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type zone:(NSString *)zoneId

{
    switch (type)
    {
        case LMLBannerFormat:
        break;
        case LMLInterstitialFormat:
        break;
        case LMLRewardedVideoFormat:
        break;
        default:
        break;
    }
}

// When an ad is clicked
- (void)advertDidInteract:(NSString *)provider type:(LMLType)type zone:(NSString *)zone;
{
}
// When an ad is showed
- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}
// When an ad is closed
-(void)advertDidClose:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}
// When we received an error loading or showing an ad
-(void)advertsRequestFail:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}
// When you must give a reward after a rewarded-video
-(void)rewardUser:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}

// Swift
 // When the sdk is already initialized, if everything is ok, state will be true.
 func labCaveMediationInitialized(_ state: Bool) {

    }
 // Will be called when any ad is loaded, it will tell you the type LMLType.LMLBannerFormat, LMLType.LMLInterstitialFormat and LMLType.LMLRewardedVideoFormat
 func  advertLoaded(_ provider: String!, view advert: LMLBannerView!, type: LMLType, zone zoneId: String!) {
        switch type {
            case .bannerFormat:
                print("banner")
            case .interstitialFormat:
                print("interstitial")            
            case .rewardedVideoFormat:
                print("rewarded")
            case .videoFormat:
                print("video")
            case .unknownFormat:
                print("unknown")
        }
    }

 // When an ad is clicked
 func advertDidInteract(_ provider: String!, type: LMLType, zone: String!) {
        
    }
 // When an ad is showed
 func advertDidPresentScreen(_ provider: String!, type: LMLType, zone: String!) {
        
    }
 // When an ad is closed
 func advertWebViewDidClose(_ provider: String!, type: LMLType, zone zoneId: String!) {
        
    }
 // When we received an error loading or showing an ad
 func advertsRequestFail(_ provider: String!, type: LMLType, zone zoneId: String!) {
        
    }
 // When you must give a reward after a rewarded-video
 func rewardUser(_ provider: String!, type: LMLType, zone zoneId: String!) {
        
    }
```

## Showing Ads

Once you have correctly initialized the SDK and set the listeners, then you can show ads.

>**The mediation SDK auto fetch all ads for you**, when you call the init method also will fecth the first ads, so you only need to call the show methods for the selected ad format.

You have to pass the viewController of your activity and the ad placement where the ad will be shown "double-coins", "main-menu", "options", etc. It can also be an empty string but we recommend you to always define an ad placement.

**The ad placements are automatically created on the dashboard and will appear after the first call of that specific ad placement is done.**

Make sure you check that the ad has been correctly loaded by calling the following methods:

## Interstitial

```swift
 //Objective-C
if ([LabCaveMediation isInterstitialReady]){
    [LabCaveMediation showInterstitialAdWithDelegate:self adLocation:@"adLocation" viewController:self];
}

//Swift
if(LabCaveMediation.isInterstitialReady()){
    LabCaveMediation.showInterstitialAd(withAdLocation: "adLocation", viewController: self)
}
```

## Rewarded Video

```swift
    //Objective-C
if ([LabCaveMediation isRewardedVideoReady]){
        [LabCaveMediation showRewardedVideoAdWithDelegate:self adLocation:@"adLocation" viewController:self];
}

//Swift
if(LabCaveMediation.isRewardedVideoReady()){
    LabCaveMediation.showRewardedVideoAd(withAdLocation: "adLocation", viewController: self)
}
```

## Banner

The position **TOP** or **BOTTOM** and the size SMART(SCREEN_SIZEx50) or BANNER (320x50) can be set at the beggining of the execution or when you call "showBanner":

```swift
//Objective-C
if ([LabCaveMediation isBannerReady]){
    ...
}

//Swift
if (LabCaveMediation.isBannerReady()){
    ...
}
```

```swift
//Objective-C
[LabCaveMediation showBannerAdWitAdLocation:@"demo" bannerSettings:LMLBannerSettings_SMART_TOP viewController:self];
[LabCaveMediation showBannerAdWitAdLocation:@"demo" bannerSettings:LMLBannerSettings_SMART_BOTTOM viewController:self];
[LabCaveMediation showBannerAdWitAdLocation:@"demo" bannerSettings:LMLBannerSettings_BANNER_TOP viewController:self];
[LabCaveMediation showBannerAdWitAdLocation:@"demo" bannerSettings:LMLBannerSettings_BANNER_BOTTOM viewController:self];
//Swift
LabCaveMediation.showBannerAdWitAdLocation("menu", bannerSettings: LMLBannerSettings.init(size: "SMART_TOP"), viewController: self)
LabCaveMediation.showBannerAdWitAdLocation("menu", bannerSettings: LMLBannerSettings.init(size: "SMART_BOTTOM"), viewController: self)
LabCaveMediation.showBannerAdWitAdLocation("menu", bannerSettings: LMLBannerSettings.init(size: "BANNER_TOP"), viewController: self)
LabCaveMediation.showBannerAdWitAdLocation("menu", bannerSettings: LMLBannerSettings.init(size: "BANNER_BOTTOM"), viewController: self)
```

Starting from SDK 2.10, you can also set capping for your ad locations in order to tweak your monetization. You can check if an ad location has reached its capping using this method:
```swift
//Objective-C
[LabCaveMediation isAdLocationCapped:@"save-me" format:LMLType.LMLRewardedVideoFormat]

//Swift
LabCaveMediation.isAdLocationCapped("save-me", format:LMLType.LMLRewardedVideoFormat )
````
### Verify the integration

In order to check if the SDK is correct, open the test module, you have to call the "Init" method first and wait till the "onInit" listener method is called:

```swift
//Objective-C
[LabCaveMediation testMediationAds:self appHash:@"YOUR_APP_HASH"];

// Swift
LabCaveMediation.testMediationAds(self, appHash:"YOUR_APP_HASH")
```

>**Make sure you remove this test module on your release build.**

## Sample Activity

You can find here an example of an activity integrating Lab Cave Mediation.

```swift
#import "ViewController.h"
#import <LabCaveMediation/LabCaveMediation.h>

@interface ViewController () <LMLDelegate>
@property(strong, nonatomic) IBOutlet UIButton *buttonBanner;
@property(strong, nonatomic) IBOutlet UIButton *buttonInterstitial;
@property(strong, nonatomic) IBOutlet UIButton *buttonVideo;
@property(strong, nonatomic) IBOutlet UIButton *buttonRewardedVideo;
@property(nonatomic, strong) LMLBannerView *banner;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [LabCaveMediation setLogEnabled:true];
    [LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self];
    
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}
- (void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type zone:(NSString *)zoneId
{
    switch (type)
    {
        case LMLBannerFormat:
            if([LabCaveMediation isBannerReady])
            {
                self.banner = advert;
                [self.buttonBanner setHidden:NO];
            }
            break;
        case LMLInterstitialFormat:

            if([LabCaveMediation isInterstitialReady])
            {
                [self.buttonInterstitial setHidden:NO];
            }
            break;
        case LMLVideoFormat:
            [self.buttonVideo setHidden:NO];
            break;
        case LMLRewardedVideoFormat:
            if([LabCaveMediation isRewardedVideoReady])
            {
                [self.buttonRewardedVideo setHidden:NO];
            }
            break;
        default:
            break;
    }
}
- (void)labCaveMediationInitialized:(BOOL)state
{
}
- (void)advertDidInteract:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}

- (void)advertWillPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}

- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}

- (void)advertWillDismissScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}

- (void)advertDidDismissScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
}

- (void)advertDidClose:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}

- (void)advertsRequestFail:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}
- (void)rewardUser:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
}
- (IBAction)showAd:(UIButton *)sender
{
    switch (sender.tag)
    {
        case 0:
            [LabCaveMediation showBannerAdWitAdLocation:@"demo" bannerSettings:LMLBannerSettings_BANNER_BOTTOM viewController:self];
            break;
        case 1:
            [LabCaveMediation showInterstitialAdWithDelegate:self adLocation:@"score-menu" viewController:self];
            break;
        case 2:
            break;
        case 3:
            [LabCaveMediation showRewardedVideoAdWithDelegate:self adLocation:@"free-cash" viewController:self];
            break;
        default:
            break;
    }
}

- (IBAction)showTest:(UIButton *)sender
{
    [LabCaveMediation testMediationAds:self appHash:@""];
}

@end

```

## Advance integration

### Debugging

You can enable logging to get additional information by using the following method:

```swift
// Objective-C
[LabCaveMediation setLogEnabled:true];

// Swift
LabCaveMediation.setLogEnabled(true)
```

### GDPR
>Make sure you set the GDPR user consent before initiliazing the Mediation.

You can set the user consent to the sdk if you manage it. If you don't, the mediation will ask the user for the consent. 

You can use the following methods:

```swift
[LabCaveMediation setUserConsent:true];

[LabCaveMediation getUserConsent];
```
