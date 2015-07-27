//
//  MGTrackingButton.m
//  MGScopeBar
//
//  Created by Darren Ford on 12/08/13. (QSR International)
//

#import "MGTrackingButton.h"

@implementation MGTrackingButton

- (id)initWithFrame:(NSRect)frame
{
	self = [super initWithFrame:frame];
	if (self != nil)
	{
		// Initialization code here.
	}

	return self;
}

- (void)trackMouseMovementsToDelegate:(id<MGTrackingDelegateProtocol>)delegate forIdentifier:(NSString *)identifier inGroup:(NSInteger)groupNumber
{
	[self setDelegate:delegate];
	[self setIdentifier:identifier];
	[self setGroupNumber:groupNumber];

	[self updateTrackingAreas];
}

// Called by AppKit when the size of the attached view gets tweaked
// Must destroy and recreate tracking views when this happens.
- (void)updateTrackingAreas
{
	/* When the size of the button changes and the button has a tracking area,
	 * AppKit will call this method to flag the change
	 * The tracking regions must be torn down and rebuilt each time
	 * this method is called */
	NSTrackingAreaOptions focusTrackingAreaOptions = NSTrackingActiveInActiveApp;
	focusTrackingAreaOptions |= NSTrackingMouseEnteredAndExited;
	focusTrackingAreaOptions |= NSTrackingAssumeInside;
	focusTrackingAreaOptions |= NSTrackingInVisibleRect;

	if (_trackingArea != nil)
	{
		[self removeTrackingArea:_trackingArea];
		_trackingArea = nil;
	}
	_trackingArea = [[NSTrackingArea alloc] initWithRect:[self frame]
												 options:focusTrackingAreaOptions
												   owner:self
												userInfo:nil];
	[self addTrackingArea:_trackingArea];
}

//! Called via the tracking area when the cursor enters the tracking area
- (void)mouseEntered:(NSEvent *)theEvent
{
	[_delegate controlDidEnterWithControl:(id)self identifier:[self identifier] andGroupNumber:[self groupNumber]];
}

//! Called via the tracking area when the cursor leaves the tracking area
- (void)mouseExited:(NSEvent *)theEvent
{
	[_delegate controlDidExitWithControl:(id)self identifier:[self identifier] andGroupNumber:[self groupNumber]];
}

@end
