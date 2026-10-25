/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  ObjectiveCAPI.h
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

#ifndef OBJECTIVE_C_API_H
#define OBJECTIVE_C_API_H

#import <CFramework/CFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * A pointer to an instance of a class.
 *
 * When you create an instance of a particular class, the allocated memory contains an `objc_object` data structure, which is directly followed by the data for the instance variables of the class.
 *
 * The ``ObjectiveCObject-class/alloc`` methodsof the class ``ObjectiveCObject-class`` use the function ``class_createInstance`` to create `objc_object` data structures.
 */
typedef id ObjectiveCAnyObject;

#define nil (id)0
#define Nil (Class)0

C_ASSUME_NONNULL_END

#endif
