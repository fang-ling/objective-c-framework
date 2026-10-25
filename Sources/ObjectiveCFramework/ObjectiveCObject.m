/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  ObjectiveCObject.m
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

#import "ObjectiveCFramework/ObjectiveCObject.h"

#import <CFramework/CFramework.h>

#if !C_TARGET_OS_APPLE

#define _ObjectiveCRootRetain      _objc_rootRetain
#define _ObjectiveCRootRelease     _objc_rootRelease
#define _ObjectiveCRootAutorelease _objc_rootAutorelease

extern ObjectiveCAnyObject _objc_rootRetain(ObjectiveCAnyObject object);
extern void _objc_rootRelease(ObjectiveCAnyObject object);
extern ObjectiveCAnyObject _objc_rootAutorelease(ObjectiveCAnyObject object);

@interface ObjectiveCObject () {
  Class _isa;
}

@end

@implementation ObjectiveCObject

+ (instancetype)alloc {
  return _ObjectiveCClassCreateInstance(self, 0);
}

+ (Class)class {
  return self;
}

- (bool)allowsWeakReference {
  return true;
}

- (instancetype)init {
  return self;
}

- (void)_usesRuntimeRR {}

- (void)dealloc {
  _ObjectiveCObjectDispose(self);
}

- (instancetype)retain {
  return _ObjectiveCRootRetain(self);
}

- (bool)retainWeakReference {
  [self retain];

  return true;
}

- (void)release {
  _ObjectiveCRootRelease(self);
}

- (instancetype)autorelease {
  return _ObjectiveCRootAutorelease(self);
}

@end

#endif
