//
//  MGTrackingDelegateProtocol.h
//  MGScopeBar
//
//  Created by Darren Ford on 12/08/13. (QSR International)

/**
 * Implement this protocol for mouse detection when it enters or leaves a
 * control within an MGScopeBar.
 */
@protocol MGTrackingDelegateProtocol

/**
 * Use this to detect the mouse entering a specific control within the MGScopeBar
 * \param control [out] The control that generated the action
 * \param identifier [out] the MGScopeBar control identifier that generated the action
 * \param groupNumber [out] the MGScopeBar group that contains the control that generated the action
 */
-(void)controlDidEnterWithControl:(NSControl*)control identifier:(NSString*)identifier andGroupNumber:(NSInteger)groupNumber;

/**
 * Use this to detect the mouse exiting a specific control within the MGScopeBar
 * \param control [out] The control that generated the action
 * \param identifier [out] the MGScopeBar control identifier that generated the action
 * \param groupNumber [out] the MGScopeBar group that contains the control that generated the action
 */
-(void)controlDidExitWithControl:(NSControl*)control identifier:(NSString*)identifier andGroupNumber:(NSInteger)groupNumber;

@end
