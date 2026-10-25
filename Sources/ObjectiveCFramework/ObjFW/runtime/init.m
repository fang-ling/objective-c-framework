/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  init.m
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

/*
 * Copyright (c) 2008-2026 Jonathan Schleifer <js@nil.im>
 *
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3.0 only,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3.0 along with this program. If not, see
 * <https://www.gnu.org/licenses/>.
 */

#import <CFramework/CFramework.h>

#if !C_TARGET_OS_APPLE

#import "ObjFWRT.h"
#import "private.h"

void
#if C_TARGET_OS_WASI
__objc_exec_class(struct objc_module *module, ...)
#else
__objc_exec_class(struct objc_module *module)
#endif
{
	_objc_globalMutex_lock();

	_objc_registerAllSelectors(module->symtab);
	_objc_registerAllClasses(module->symtab);
	_objc_registerAllCategories(module->symtab);
	_objc_initStaticInstances(module->symtab);

	_objc_globalMutex_unlock();
}

void
objc_deinit(void)
{
	_objc_globalMutex_lock();

	_objc_unregisterAllCategories();
	_objc_unregisterAllClasses();
	_objc_unregisterAllSelectors();
	_objc_forgetPendingStaticInstances();
	_objc_dtable_cleanup();

	_objc_globalMutex_unlock();
}

#endif
