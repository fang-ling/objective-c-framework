/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  ObjectiveCObject.h
 *  objective-c-framework
 *
 *  Created by Fang Ling on 2026/10/24.
 *
 *  This source file is part of the ObjectiveCFramework open source project
 *
 *  Copyright (c) 2026 Fang Ling <fangling@fangl.ing>
 *  Licensed under GNU Lesser General Public License v3.0
 *
 *  See LICENSE for license information
 *
 *  SPDX-License-Identifier: LGPL-3.0-only
 *
 *===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*/

#ifndef OBJECTIVE_C_OBJECT_H
#define OBJECTIVE_C_OBJECT_H

#import <CFramework/CFramework.h>

#if !C_TARGET_OS_APPLE

C_ASSUME_NONNULL_BEGIN

/**
 * The group of methods that are fundamental to all Objective-C objects.
 *
 * An object that conforms to this protocol can be considered a first-class object. Such an object can be asked about its:
 *
 *   - Class, and the place of its class in the inheritance hierarchy.
 *   - Conformance to protocols.
 *   - Ability to respond to a particular message.
 *
 * The root class ``ObjectiveCObject-class`` adopts this protocol, so all objects inheriting from ``ObjectiveCObject-class`` have the features described by this protocol.
 */
@protocol ObjectiveCObject

@end

C_ASSUME_NONNULL_END

#endif

#endif
