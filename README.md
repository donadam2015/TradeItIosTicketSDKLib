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
    	[TradeItTicketController showTicketWithApiKey: @"YOUR-API-KEY" symbol: @"GE" viewController: self];
	}

	// portfolio ticket
	- (IBAction)launchTicket:(id)sender {
		[TradeItTicketController showPortfolioWithApiKey: @"YOUR-API-KEY" viewController: self];
	}

##Debugging/Setup
Should you want to test the full flow of the app, you can use our dummy broker as documented in TradeItIosEmsApi. To enable the dummy broker on the ticket, use the full method call and set the 'withDebug' property:

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	// debug trading ticket
	- (IBAction)launchTicket:(id)sender {
		[TradeItTicketController showTicketWithApiKey: @"YOUR-API-KEY" symbol: @"GE" orderAction: @"buy" orderQuantity: @1 viewController: self withDebug: YES onCompletion: nil];
	}

	// debug portfolio ticket
	- (IBAction)launchTicket:(id)sender {
		[TradeItTicketController showPortfolioWithApiKey: @"YOUR-API-KEY" viewController: self withDebug: YES onCompletion: nil];
	}
