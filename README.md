# LabCaveMediationSDK-iOS

The current version (2.5.1) is tested with Xcode8 or above and is compatible with iOS 8 and above.
## Download SDK

Download our sdk, add the LabCaveMediation.framework to your project in General tab Linked Frameworks and Libraries. Now you must add the following frameworks and libs to your project in General tab Linked Frameworks and Libraries. Ensure that the frameworks are linked correctly.

      AdSupport.framework
      AudioToolbox.framework
      AVFoundation.framework
      CFNetwork.framework
      CoreGraphics.framework
      CoreMedia.framework
      EventKit.framework
      EventKitUI.framework
      Foundation.framework
      libz.dylib or libz.tbd
      libc++.tbd
      libxml2.2.tbd
      MediaPlayer.framework
      QuartzCore.framework
      StoreKit.framework
      SystemConfiguration.framework
      UIKit.framework
      WebKit.framework
      WatchConnectivity.framework


Lastly, add the following values to the **Other Linker Flags** in the **Build Settings** tab: 

      -ObjC,-fobjc-arc

If your are working in swift you must create a header file (.h) and add to your project, for example called "LabCave-Bridging-Header.h", and add this line of code to it:

```objectivec
#import <LabCaveMediation/LabCaveMediation.h>
```

Now in build settings tab in "Swift Compiler - General" in the field "Objective-C Bridging Header" add the file create above. Now you are ready to use the LabCaveMediation with Swift.

## Integrate SDK

Once you have added all files it's time to initialize the sdk. **Important** you must initialize the sdk and the begining of the execution of your app and **only once**.

If you are in Objetive-C import the mediation reference to the SDK.

```objectivec
 #import <LabCaveMediation/LabCaveMediation.h> 
```

Launch the SDK with the following action setting **YOUR_APP_HASH** as parameter and **uIViewController** as delegate. Your manager will give you your **YOUR_APP_HASH**.

```objectivec
// Objective-C
[LabCaveMediation initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self];

//Swift
LabCaveMediation.initWithAppHash("YOUR_APP_HASH", delegate: self, viewController: self)
```

Below are the following methods of how to request different ad formats, the parameters are the “delegate” and the “zone” refers to where the advertising format can be kept track of. Is not a good practice call any show method immediately after the init call. When a format ad is loaded you will be warned in the "advertLoaded" delegate method, that's a good time to call any show method if you want.

```objectivec
// Objective-C
[LabCaveMediation showBannerAdWithDelegate:self zone:@"home" viewController:self];
[LabCaveMediation showInterstitialAdWithDelegate:self zone:@"home" viewController:self];
[LabCaveMediation showRewardedVideoAdWithDelegate:self zone:@"home" viewController:self];

//Swift
LabCaveMediation.showBannerAd(with: self, zone: "home", viewController: self)
LabCaveMediation.showInterstitialAd(with: self, zone: "home", viewController: self)
LabCaveMediation.showRewardedVideoAd(with: self, zone: "home", viewController: self)
```

### Advance integration

The sdk offers a delegate where you can receive the events of the ads.


```objectivec
// When the sdk is already initialized, if everything is ok, state will be true.
- (void)labCaveMediationInitialized:(BOOL)state
{
}
// Will be called when any ad is loaded, it will tell you the type MMLType.MMLBannerFormat, MMLType.MMLInterstitialFormat and MMLType.MMLRewardedVideoFormat
-(void)advertLoaded:(NSString *)provider view:(MMLBannerView *)advert type:(MMLType)type zone:(NSString *)zoneId

{
    switch (type)
    {
        case MMLBannerFormat:
        break;
        case MMLInterstitialFormat:
        break;
        case MMLRewardedVideoFormat:
        break;
        default:
        break;
    }
}

// When an ad is clicked
- (void)advertDidInteract:(NSString *)provider type:(MMLType)type zone:(NSString *)zone;
{
      NSLog("INTERACT CONTROLLER LabCave");
}
// When an ad is showed 
- (void)advertDidPresentScreen:(NSString *)provider type:(MMLType)type zone:(NSString *)zone
{
    NSLog(@"DID PRESENT CONTROLLER LabCave ");
}
// When an ad is closed
-(void)advertDidClose:(NSString *)provider type:(MMLType)type zone:(NSString *)zoneId
{
    NSLog(@"CLOSE CONTROLLER LabCave ");
}
// When we received an error loading or showing an ad
-(void)advertsRequestFail:(NSString *)provider type:(MMLType)type zone:(NSString *)zoneId
{
    NSLog(@"FAIL CONTROLLER LabCave ");
}
// When you must give a reward after a rewarded-video
-(void)rewardUser:(NSString *)provider type:(MMLType)type zone:(NSString *)zoneId
{
    NSLog(@"REWARD CONTROLLER LabCave ");
}



// Swift
 // When the sdk is already initialized, if everything is ok, state will be true.
  func labCaveMediationInitialized(_ state: Bool) {

    }
 // Will be called when any ad is loaded, it will tell you the type MMLType.MMLBannerFormat, MMLType.MMLInterstitialFormat and MMLType.MMLRewardedVideoFormat
 func  advertLoaded(_ provider: String!, view advert: MMLBannerView!, type: MMLType, zone zoneId: String!) {
      switch type {
            case .bannerFormat:
                  print("banner")
            
            case .interstitialFormat:
                  print("interstitial")
            
            case .rewardedVideoFormat:
                  print("rewarded")
                  
            case .videoFormat:
                  print("video")
             }
        }
    }

 // When an ad is clicked
 func advertDidInteract(_ provider: String!, type: MMLType, zone: String!) {
        
    }
 // When an ad is showed
 func advertDidPresentScreen(_ provider: String!, type: MMLType, zone: String!) {
        
    }
 // When an ad is closed
 func advertWebViewDidClose(_ provider: String!, type: MMLType, zone zoneId: String!) {
        
    }
 // When we received an error loading or showing an ad
 func advertsRequestFail(_ provider: String!, type: MMLType, zone zoneId: String!) {
        
    }
 // When you must give a reward after a rewarded-video
 func rewardUser(_ provider: String!, type: MMLType, zone zoneId: String!) {
        
    }
```

You can enable loggin to check what is happening

```objectivec
// Objective-C
[LabCaveMediation setLogEnabled:true];

// Swift
LabCaveMediation.setLogEnabled(true)
```
