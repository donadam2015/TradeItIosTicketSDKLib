//
//  TradeItSelectAccountRequest.h
//  TradeItIosEmsApi
//
//  Created by Serge Kreiker on 6/26/15.
//  Copyright (c) 2015 TradeIt. All rights reserved.
//

#import "TradeItRequest.h"

@interface TradeItSelectAccountRequest : TradeItRequest

@property NSString* token;
@property NSDictionary* accountInfo;

-(id) initWithToken: (NSString*)token andAccountInfo:(NSDictionary*) accountInfo;

@end