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

#import <ObjectiveCFramework/ObjectiveCAPI.h>

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

/**
 * The root class of most Objective-C class hierarchies, from which subclasses inherit a basic interface to the runtime system and the ability to behave as Objective-C objects.
 *
 * ## Topics
 *
 * ### Creating, Copying, and Deallocating Objects
 *
 * - ``alloc``
 * - ``init``
 * - ``dealloc``
 *
 * ### Identifying Classes
 *
 * - ``class``
 *
 * ### Obsolete Methods
 *
 * - ``allowsWeakReference``
 * - ``retain``
 * - ``retainWeakReference``
 * - ``release``
 * - ``autorelease``
 */
_OBJECTIVE_C_ROOT_CLASS
@interface ObjectiveCObject <ObjectiveCObject>

/**
 * A Boolean value indicating whether the object allows a weak references.
 */
@property (nonatomic, assign, readonly) CBoolean allowsWeakReference;

/**
 * Returns a new instance of the receiving class.
 *
 * This is an instance variable of the new instance that is initialized to a data structure describing the class; memory for all other instance variables is set to `0`.
 *
 * You must use an `init...` method to complete the initialization process. For example:
 *
 *    ```objective-c
 *    TheClass* newObject = [[TheClass alloc] init];
 *    ```
 *
 * Do not override ``alloc`` to include initialization code. Instead, implement class-specific versions of `init...` methods.
 *
 * - Returns: A new instance of the receiver.
 */
+ (instancetype)alloc;

/**
 * Returns the class object.
 *
 * Refer to a class only by its name when it is the receiver of a message. In all other cases, the class object must be obtained through this or a similar method. For example, here `SomeClass` is
 * passed as an argument to the ``ObjectiveCObject-protocol/isKindOfClass:`` method (declared in the ``ObjectiveCObject-protocol`` protocol):
 *
 *    ```objective-c
 *    CBoolean test = [self isKindOfClass:[SomeClass class]];
 *    ```
 *
 * - Returns: The class object.
 */
+ (Class)class;

/**
 * Implemented by subclasses to initialize a new object (the receiver) immediately after memory for it has been allocated.
 *
 * An ``init`` message is coupled with an ``alloc`` message in the same line of code:
 *
 *    ```objective-c
 *    SomeClass* object = [[SomeClass alloc] init];
 *    ```
 *
 * An object isn't ready to be used until it has been initialized.
 *
 * In a custom implementation of this method, you must invoke super's initialization then initialize and return the new object. If the new object can't be initialized, the method should return
 * ``nil-macro``.
 * For example, a hypothetical `BuiltInCamera` class might return ``nil-macro`` from its `init` method if run on a device that has no camera.
 *
 *    ```objective-c
 *    - (instancetype)init {
 *      if (!(self = [super init])) {
 *        return nil;
 *      }
 *
 *      // Initialize self.
 *
 *      return self;
 *    }
 *    ```
 *
 * In some cases, a custom implementation of the ``init`` method might return a substitute object. You must therefore always use the object returned by ``init``, and not the one returned by ``alloc``
 * in subsequent code.
 *
 * The ``init`` method defined in the ``ObjectiveCObject-class`` class does no initialization; it simply returns `self`. In terms of nullability, callers can assume that the ``ObjectiveCObject-class``
 * implementation of ``init`` does not return ``nil-macro``.
 *
 * - Returns: An initialized object, or ``nil-macro`` if an object could not be created for some reason that would not result in an exception.
 */
- (instancetype)init;

- (void)_usesRuntimeRR;

/**
 * Deallocates the memory occupied by the receiver.
 *
 * Subsequent messages to the receiver may generate an error indicating that a message was sent to a deallocated object (provided the deallocated memory hasn't been reused yet).
 *
 * You override this method to dispose of resources other than the object's instance variables, for example:
 *
 *    ```objective-c
 *    - (void)dealloc {
 *      free(myBigBlockOfMemory);
 *    }
 *    ```
 *
 * In an implementation of ``dealloc``, do not invoke the superclass's implementation. You should try to avoid managing the lifetime of limited resources such as file descriptors using ``dealloc``.
 *
 * You never send a ``dealloc`` message directly. Instead, an object's ``dealloc`` method is invoked by the runtime.
 *
 * ### Special Considerations
 *
 * When not using ARC, your implementation of ``dealloc`` must invoke the superclass's implementation as its last instruction.
 */
- (void)dealloc;

/**
 * Increments the receiver's reference count.
 *
 * You send an object a ``retain`` message when you want to prevent it from being deallocated until you have finished using it.
 *
 * An object is deallocated automatically when its reference count reaches `0`. ``retain`` messages increment the reference count, and ``release`` messages decrement it.
 *
 * As a convenience, ``retain`` returns `self` because it may be used in nested expressions.
 *
 * You would implement this method only if you were defining your own reference-counting scheme. Such implementations must return `self` and should not invoke the inherited method by sending a
 * ``retain`` message to `super`.
 *
 * ### Special Considerations
 *
 * Instead of using manual reference counting, you should adopt ARC.
 *
 * - Returns: `self`.
 */
- (instancetype)retain;

/**
 * Retains a weak reference to this object.
 *
 * - Returns: A Boolean value indicating whether a weak reference to this object has been retained
 */
- (CBoolean)retainWeakReference;

/**
 * Decrements the receiver's reference count.
 *
 * The receiver is sent a ``dealloc`` message when its reference count reaches `0`.
 *
 * You would only implement this method to define your own reference-counting scheme. Such implementations should not invoke the inherited method; that is, they should not include a release message to
 * `super`.
 *
 * ### Special Considerations
 *
 * Instead of using manual reference counting, you should adopt ARC.
 */
- (void)release;

/**
 * Decrements the receiver's retain count at the end of the current autorelease pool block.
 *
 * ### Special Considerations
 *
 * Instead of using manual reference counting, you should adopt ARC.
 *
 * - Returns: `self`.
 */
- (instancetype)autorelease;

@end

C_ASSUME_NONNULL_END

#endif

#endif
