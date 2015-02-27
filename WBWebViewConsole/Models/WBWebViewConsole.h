//
//  WBWebViewConsole.h
//  Weibo
//
//  Created by Wutian on 14/7/23.
//  Copyright (c) 2014年 Sina. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WBWebViewConsoleMessage.h"

extern NSString * const WBWebViewConsoleDidAddMessageNotification;
extern NSString * const WBWebViewConsoleDidClearMessagesNotification;

extern NSString * const WBWebViewConsoleLastSelectionElementName;

@protocol WBWebView;

@interface WBWebViewConsole : NSObject

- (instancetype)initWithWebView:(id<WBWebView>)webView;

- (void)addMessage:(NSString *)message type:(WBWebViewConsoleMessageType)type level:(WBWebViewConsoleMessageLevel)level source:(WBWebViewConsoleMessageSource)source;
- (void)addMessage:(NSString *)message type:(WBWebViewConsoleMessageType)type level:(WBWebViewConsoleMessageLevel)level source:(WBWebViewConsoleMessageSource)source url:(NSString *)url line:(NSInteger)line column:(NSInteger)column;
- (void)addMessage:(NSString *)message level:(WBWebViewConsoleMessageLevel)level source:(WBWebViewConsoleMessageSource)source caller:(NSString *)caller;

- (void)clearMessages;
- (void)reset;

- (void)sendMessage:(NSString *)message;

@property (nonatomic, strong, readonly) NSArray * messages;
@property (nonatomic, strong, readonly) NSArray * clearedMessages;

@property (nonatomic, weak, readonly) id<WBWebView> webView;

- (void)storeCurrentSelectedElementToJavaScriptVariable:(NSString *)variable completion:(void (^)(BOOL success))completion;

- (void)fetchSuggestionsForPrompt:(NSString *)prompt cursorIndex:(NSInteger)cursorIndex completion:(void (^)(NSArray * suggestions, NSRange replacementRange))completion;

@end
