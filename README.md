# Latest Version 1.0.13
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
This is the main method of launching the TradeIt trading ticket. 

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchTicket:(id)sender {
    	[TradeItTicketController showFullTicketWithPublisherApp: @"TESTAPP" symbol:@"GE" lastPrice:26.25 viewController:self];
	}

##Debugging/Setup
Should you want to test the full flow of the app, you can use our dummy broker as documented in TradeItIosEmsApi. To enable the dummy broker on the ticket use the debug version of the full ticket view:

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchTicket:(id)sender {
    	[TradeItTicketController debugShowFullTicketWithPublisherApp: @"TESTAPP" symbol:@"GE" lastPrice:26.25 viewController:self onCompletion:nil];
	}
