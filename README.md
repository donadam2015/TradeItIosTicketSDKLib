# Latest Version 2.3.3

- Support for SGX

# Version 2.3.2

- Adds ability to retrieve sessions for every linked account

# Version 2.3.1

- Adds ability to launch portfolio with specific account selected

# Version 2.3.0

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

##Launch the Trade screen
<img src="https://www.trade.it/images/guide/trading-flow.png">

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

- (IBAction)launchTicket:(id)sender {
    [TradeItTicketController showTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController: self];
}

// restrict the ticket to only show Trade.Use this method if yur app does not want to show the TradeIT portfolio from the trading ticket
- (IBAction)launchTicketOnly:(id)sender {
    [TradeItTicketController showRestrictedTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" viewController:self];
}
~~~~

##Launch the Portfolio screen
<img src="https://www.trade.it/images/guide/portfolio-flow.png">

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

- (IBAction)launchPortfolio:(id)sender {
    [TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
}

// restrict the ticket to only show Portfolio. Use this method if yur app does not want to show the TradeIT trading ticket for the portfolio
- (IBAction)launchPortfolioOnly:(id)sender {
    [TradeItTicketController showRestrictedPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self];
}
~~~~

#### Launch the Portfolio screen, with specific account selected: This is useful if you app displays a list of all the accounts that user can click on

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
    
- (void)viewDidLoad {
    NSArray * linkedAccounts = [TradeItTicketController getLinkedAccounts];
    NSDictionary * firstAccount = [linkedAccounts objectAtIndex: 0];
    self.selectedAccountNumber = [firstAccount valueForKey: @"accountNumber"];
}

- (IBAction)launchPortfolio:(id)sender {
    [TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self accountNumber: self.selectedAccountNumber];
}
~~~~

#### If you would like to pull in a users holdings/portfolio data to screens outside of the SDK, then use the code below.
Note: that this code will launch the authentication flow and handle any security questions if the user is not already authenticated.

~~~~
- [TradeItTicketController getSessions: self withApiKey:@"tradeit-test-api-key"
    onCompletion:^(NSArray *sessions) {
    NSDictionary * firstSession = [sessions objectAtIndex: 0];
    NSString * sessionToken = [firstSession valueForKey:@"token"];
    NSString * accountNumber = [firstSession valueForKey:@"accountNumber"];
    
    //use sessionToken with anything here:  https://www.trade.it/documentation/api
    //or to use with the existing services in the library
    
    TradeItConnector * myConnector = [[TradeItConnector alloc] initWithApiKey: @"tradeit-test-api-key"];
    
    TradeItSession * mySession = [[TradeItSession alloc] initWithConnector: myConnector];
    mySession.token = sessionToken;
    
    TradeItGetPositionsRequest * positionRequest = [[TradeItGetPositionsRequest alloc] initWithAccountNumber:accountNumber];
    
    TradeItPositionService * positionRequester = [[TradeItPositionService alloc] initWithSession: mySession];
    
    [positionRequester getAccountPositions: positionRequest withCompletionBlock:^(TradeItResult * result) {
         //update UI with position data
    }]; 
}];
~~~~

##Launch the Account Setup screen
<img src="https://www.trade.it/images/guide/login flow.png">
~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
    
- (IBAction)launchAccountSelection:(id)sender {
    [TradeItTicketController showAccountsWithApiKey: @"tradeit-test-api-key" viewController: self onCompletion: nil];
}
~~~~

##Launch the Promotional Broker Center.
Any account opening revenues from the Broker Center will be shared with the app developper. Please contact TradeIt for more details

<img src="https://www.trade.it/images/guide/broker_center.jpg" width="200">

Before launching the Broker Center, TradeIt needs to retrieve configuration data. For best performance, call the following method sometime before launching the screen:

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [TradeItTicketController initializePublisherData: @"tradeit-test-api-key" onLoad: ^(BOOL brokerCenterActive){
        // use boolean*
    }];
    return YES;
}
~~~~

*The onLoad callback passes a boolean that determines whether the Open Account feature is available.

To launch the Broker Center screen itself:

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
    
[TradeItTicketController showBrokerCenterWithApiKey:@"tradeit-test-api-key" viewController:self];
~~~~

##Launch via instantiation

Alternatively, if you instantiate the ticket, you can manually set the flow using presentationMode:

~~~~
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
~~~~

##Debugging/Setup
Should you want to test the full flow of the app, you can use our dummy broker as documented in TradeItIosEmsApi. To enable the dummy broker on the ticket, use the full method call and set the 'withDebug' property. Keep in mind that you must use your QA api key when in debug mode. Also, you will need to reset your NSUserDefaults between debug and production sessions, as your saved authentication data is particular to the server environment:

~~~~
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>

// debug trading ticket
- (IBAction)launchTicket:(id)sender {
    [TradeItTicketController showTicketWithApiKey: @"tradeit-test-api-key" symbol: @"GE" orderAction: @"buy" orderQuantity: @1 viewController: self withDebug: YES onCompletion: nil];
}

// debug portfolio ticket
- (IBAction)launchPortfolio:(id)sender {
    [TradeItTicketController showPortfolioWithApiKey: @"tradeit-test-api-key" viewController: self withDebug: YES onCompletion: nil];
}
~~~~
