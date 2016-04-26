# Latest Version 2.1.3

Fixes:

- improve portfolio loading flow

Features:

- allow users to manually refresh quotes on price tap

# Latest Version 2.1.2

Fixes:

- launch performance issues
- cursors missing on input fields

# Latest Version 2.1.0

Fixes:

- intermittent infinite loading
- touch ID failure
- various small issues

Features:

- simplified order type flow
- now using QA api key for debug mode
- single, restricted flows now available. Choose auth, trade, or portfolio

# Latest Version 2.0.3

Fixed null holdings on portfolio screen

Fixed intermittent infinite loading on portfolio screen

Fixed account selection style not appearing on portfolio screen

# Latest Version 2.0.2

Fixed minor UI bugs

Fixed various breaking issues in new design

Various design improvements

# Latest Version 2.0.0
Complete ticket redesign

Improved authentication flow

New feature: change order symbol directly inside ticket

New feature: Portfolio View
#####What is Portfolio View?
* Real-time account aggregation
* View and trade holdings
* Ability to launch directly to Portfolio

# Version 1.0.16
Fixes iPad crash issue #30

# Version 1.0.15
Fixed support for bitcode #25
Fixed spacing display issue #23

# Version 1.0.14
Bug fix for Dummy always showing when using the auth controller link brokerage function

# 1.0.13
Added in TradeItAuthController.h to add in a handful of functions to help setup the broker association outside the normal trading ticket flow

# Version 1.0.12
Fix for iPads not correctly loading the storyboard, resulting in app crash

# TradeItIosTicketSDKLib
Framework to launch TradeIt trading tickets. This Framework is built off the TradeIt TradeItIosEmsApi library and as such exposes all the TradeItIosEmsApi headers should you want to use the TradeItIosEmsApi directly, however, this generally isn't needed.

##Including the library in your project
To use the library you'll want to drag both TradeItIosTicketSDK.framework and TradeItIosTicketSDK.bundle into your project.

Check the Copy items into destination group’s folder box, and click Finish.

You'll also need to add the LocalAuthentication.framework for TouchId. Go to your general build settings and in the "Linked Frameworks and Libraries" secion click "+" and search for it in the list.

##Full View Ticket
This is the main method for launching the TradeIt ticket.

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	// trading ticket
	- (IBAction)launchTicket:(id)sender {
    	[TradeItTicketController showTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController: self];
	}

	// portfolio ticket
	- (IBAction)launchPortfolio:(id)sender {
		[TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
	}

##Partial View Ticket
This is the method for restricting user flow to either authentication, trading, or portfolio. This will remove the bottom tab bar used for trade-portfolio navigation.

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
	
	// authentication
	- (IBAction)launchAuthOnly:(id)sender {
	[TradeItTicketController showAuthenticationWithApiKey: @"tradeit-test-api-key" viewController: self onCompletion: nil];
	}

	// trading
	- (IBAction)launchTicketOnly:(id)sender {
	[TradeItTicketController showRestrictedTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController:self];
	}
	
	// portfolio
	- (IBAction)launchPortfolioOnly:(id)sender {
	[TradeItTicketController showRestrictedPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
	}

Alternatively, if you instantiate the ticket, you can manually set the flow using presentationMode:

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
	
	// trading
	- (IBAction)launchTicket:(id)sender {
	TradeItTicketController * ticket = [[TradeItTicketController alloc] initWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController: self];
	// choose one of the following:
	ticket.presentationMode = TradeItPresentationModeAuth;
	ticket.presentationMode = TradeItPresentationModeTradeOnly;
	ticket.presentationMode = TradeItPresentationModePortfolioOnly;
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
