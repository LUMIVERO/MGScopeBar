//
//  MGTrackingButton.h
//  MGScopeBar
//
//  Created by Darren Ford on 12/08/13. (QSR International)
//

#import <Cocoa/Cocoa.h>

#import "MGTrackingDelegateProtocol.h"

/**
 * An NSButton implementation for the MGScopeBar control that can track mouse
 * events within the button itself.  All mouse enter/exit events are reported
 * back to the delegate.
 */
@interface MGTrackingButton : NSButton

//! The mouse tracking area for the button
@property (nonatomic, strong) NSTrackingArea* trackingArea;

//! The MGScopeBar group number for the button
@property (nonatomic, assign) NSInteger groupNumber;

//! The MGScopeBar identifier for the button
@property (nonatomic, strong) NSString* identifier;

//! The button's mouse event delegate
@property (nonatomic, assign) id<MGTrackingDelegateProtocol> delegate;

/**
 * Begin to track mouse movements within the button control, and report to the delegate
 * when the mouse enters or exits the button frame.
 * \param delegate [in] the delegate to send the mouse enter/exit messages
 * \param identifier [in] the MGScopeBar identifier for the button
 * \param groupNumber [in] the MGScopeBar group for the button
 */
- (void)trackMouseMovementsToDelegate:(id<MGTrackingDelegateProtocol>)delegate forIdentifier:(NSString *)identifier inGroup:(NSInteger)groupNumber;

@end
