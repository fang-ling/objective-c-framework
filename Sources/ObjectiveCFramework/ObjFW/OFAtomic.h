/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  OFAtomic.h
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

#import "macros.h"

#if (defined(OF_AMD64) || defined(OF_X86)) && defined(__GNUC__)
# import "platform/x86/OFAtomic.h"
#elif defined(OF_POWERPC) && defined(__GNUC__) && !defined(__APPLE_CC__) && \
    !defined(OF_AIX)
# import "platform/PowerPC/OFAtomic.h"
#elif defined(OF_ARM64) || C_TARGET_OS_WASI
# import "platform/GCC4.7/OFAtomic.h"
#else
# error No atomic operations available!
#endif

#endif
