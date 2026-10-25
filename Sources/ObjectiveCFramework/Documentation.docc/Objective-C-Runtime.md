# Objective-C Runtime

Describes the Objective-C runtime library support functions and data structures.

## Overview

The Objective-C runtime is a runtime library that provides support for the dynamic properties of the Objective-C language, and as such is linked to by all Objective-C apps.

You typically don't need to use the Objective-C runtime library directly when programming in Objective-C. This API is useful primarily for developing bridge layers between Objective-C and other
languages, or for low-level debugging.

> String encoding: All ``CFramework/CString`` in the runtime API should be considered to have UTF-8 encoding.

### Who Should Read This Document

The document is intended for readers who might be interested in learning about the Objective-C runtime.

Because this isn't a document about C, it assumes some prior acquaintance with that language. However, it doesn't have to be an extensive acquaintance.

## Topics

### Class-Definition Data Structures

- ``ObjectiveCFramework/ObjectiveCMethod``

### Instance Data Types

- ``ObjectiveCFramework/ObjectiveCAnyObject``

### Constants

- <doc:Null-Values>
