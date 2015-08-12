# Latest Version 1.0.4
The latest version has 1 breaking change if you are currently using the completion callback. We've added in a TradeItTicketControllerResult so you're able to see where the user was at when they left the ticket. Please refer to [TradeItIosEmsApiLib](https://github.com/tradingticket/TradeItIosEmsApiLib) for more information about the TradeItIosEms result objects.

Additionally there is now a more detailed calculator screen for the user to choose or for you to default when you initialize the ticket yourself, see TradeItTicketController.h for more information.

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