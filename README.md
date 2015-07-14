# TradeItIosTicketSDKLib
Framework to launch TradeIt trading tickets. This Framework is built off the TradeIt TradeItIosEmsApi library and as such exposes all the TradeItIosEmsApi headers should you want to use the TradeItIosEmsApi directly, however, this generally isn't needed.

##Including the library in your project
To use the library you'll want to drag both TradeItIosTicketSDK.framework and TradeItIosTicketSDK.bundle into your project.

Check the Copy items into destination group’s folder box, and click Finish.

## Full View Ticket
This is the main method of launching the TradeIt trading ticket. 

	#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

	- (IBAction)launchTicket:(id)sender {
    	[TradeItTicketController debugShowFullTicketWithPublisherApp: @"TESTAPP" symbol:@"GE" lastPrice:26.25 viewController:self];
	}