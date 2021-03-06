//
//  YXFeedAdManager.h
//  LunchAd
//
//  Created by shuai on 2018/10/12.
//  Copyright © 2018年 YX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "YXFeedAdData.h"
#import "YXLaunchAdManager.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YXFeedAdManagerDelegate<NSObject>
@optional

/**
 加载成功的回调
 
 @param data  回调的广告素材
 */
- (void)didLoadFeedAd:(NSArray<YXFeedAdData*>*_Nullable)data;

/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadFeedAd:(NSError* _Nonnull)error;

/**
 广告点击后回调
 */
- (void)didClickedFeedAd;

@end

@interface YXFeedAdManager : NSObject

@property(nonatomic,weak) id<YXFeedAdManagerDelegate> delegate;


@property (nonatomic,assign) YXADSize adSize;

/**
 当adSize类型为YXADSizeCustom时，宽高必传，其余模式不用传
 */
@property (nonatomic, assign) CGFloat s2sWidth;
@property (nonatomic, assign) CGFloat s2sHeight;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/**
 广告数量 默认为1
 */
@property (nonatomic,assign) NSInteger adCount;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**  开始加载广告  */
- (void)loadFeedAd;

/**
 定义原生广告视图中可以点击的 视图区域，行为由SDK控制
 @param view 原生广告的视图，完整区域
 @param adData 广告数据
 @param views 可点击的视图
 */
- (void)registerAdViewForInteraction:(UIView *)view adData:(YXFeedAdData*)adData clickableViews:(NSArray *)views;

@end

NS_ASSUME_NONNULL_END
