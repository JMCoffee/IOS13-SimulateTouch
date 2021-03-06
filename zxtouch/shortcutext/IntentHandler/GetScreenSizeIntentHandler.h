//
//  GetScreenSizeIntentHandler.h
//  shortcutext
//
//  Created by Jason on 2021/2/9.
//

#import <Foundation/Foundation.h>
#import <Intents/Intents.h>
#import <UIKit/UIKit.h>
#import "Socket.h"
#import "SocketDataHandler.h"
#import "SpringBoardSocketClient.h"
#import "../Task.h"

#import "GetScreenSizeIntent.h"

NS_ASSUME_NONNULL_BEGIN

@interface GetScreenSizeIntentHandler : NSObject<SpringBoardSocketClient, GetScreenSizeIntentHandling>

@end

NS_ASSUME_NONNULL_END
