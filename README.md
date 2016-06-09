# Latest Version 2.3.0

- Adds customizable UI colors
- Fixes rotation issue with landscape-only applications
- Adds ability to launch directly to Open Account screen

# Version 2.2.7

- Removes info.plist flags that prevent deployment

# Version 2.2.6

- Improves handling for empty holdings values

# Version 2.2.5

- Several improvements and fixes for review screen
- Replaces N/A values with loading indicators

# TradeItIosTicketSDKLib
Framework to launch TradeIt trading tickets. This Framework is built off the TradeIt TradeItIosEmsApi library and as such exposes all the TradeItIosEmsApi headers should you want to use the TradeItIosEmsApi directly, however, this generally isn't needed.

##Including the library in your project
To use the library you'll want to drag both TradeItIosTicketSDK.framework and TradeItIosTicketSDK.bundle into your project.

Check the Copy items into destination group’s folder box, and click Finish.

You'll also need to add the LocalAuthentication.framework for TouchId. Go to your general build settings and in the "Linked Frameworks and Libraries" secion click "+" and search for it in the list.

##Specifying parameters for the TradeIt ticket
When setting order parameters in the ticket, follow the conventions listed in our API documentation:

Order Quantity: only positive integers

Order Action: buy, sell, buyToCover, sellShort

Order Type: market, limit, stopMarket, stopLimit

For more information, visit https://www.trade.it/documentation/api#PreviewTrade

#Launch Methods

##Launch to Trade screen
<img src="https://www.trade.it/images/guide/trade.png" width="200">

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchTicket:(id)sender {
    	[TradeItTicketController showTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController: self];
	}

	// restrict the ticket to only show Trade
	- (IBAction)launchTicketOnly:(id)sender {
	[TradeItTicketController showRestrictedTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController:self];
	}

##Launch to Portfolio screen
<img src="https://www.trade.it/images/guide/portfolio.png" width="200">

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchPortfolio:(id)sender {
		[TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
	}

	// restrict the ticket to only show Portfolio
	- (IBAction)launchPortfolioOnly:(id)sender {
	[TradeItTicketController showRestrictedPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
	}

##Launch to Account Selection screen
<img src="https://www.trade.it/images/guide/account_select.png" width="200">

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchAccountSelection:(id)sender {
	[TradeItTicketController showAccountsWithApiKey: @"tradeit-test-api-key" viewController: self onCompletion: nil];
	}

##Launch Login flow
<img src="https://www.trade.it/images/guide/onboarding.png" width="200">

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchAuthOnly:(id)sender {
	[TradeItTicketController showAuthenticationWithApiKey: @"tradeit-test-api-key" viewController: self onCompletion: nil];
	}

##Launch via instantiation

Alternatively, if you instantiate the ticket, you can manually set the flow using presentationMode:

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
	
	// trading
	- (IBAction)launchTicket:(id)sender {
	TradeItTicketController * ticket = [[TradeItTicketController alloc] initWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController: self];
	// choose one of the following:
	ticket.presentationMode = TradeItPresentationModeAuth;
	ticket.presentationMode = TradeItPresentationModeTradeOnly;
	ticket.presentationMode = TradeItPresentationModePortfolioOnly;
	[ticket showTicket];
	}

##Debugging/Setup
Should you want to test the full flow of the app, you can use our dummy broker as documented in TradeItIosEmsApi. To enable the dummy broker on the ticket, use the full method call and set the 'withDebug' property. Keep in mind that you must use your QA api key when in debug mode. Also, you will need to reset your NSUserDefaults between debug and production sessions, as your saved authentication data is particular to the server environment:

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	// debug trading ticket
	- (IBAction)launchTicket:(id)sender {
		[TradeItTicketController showTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" orderAction: @"buy" orderQuantity: @1 viewController: self withDebug: YES onCompletion: nil];
	}

	// debug portfolio ticket
	- (IBAction)launchPortfolio:(id)sender {
		[TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self withDebug: YES onCompletion: nil];
	}
