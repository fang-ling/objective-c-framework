// swift-tools-version: 6.3

//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//
//
//  Package.swift
//  objective-c-framework
//
//  Created by Fang Ling on 2026/9/25.
//
//  This source file is part of the ObjectiveCFramework open source project
//
//  Copyright (c) 2026 Fang Ling <fangling@fangl.ing>
//  Licensed under GNU Lesser General Public License v3.0
//
//  See LICENSE for license information
//
//  SPDX-License-Identifier: LGPL-3.0-only
//
//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//

import PackageDescription

let package = Package(
  name: "objective-c-framework",
  products: [
    .library(name: "ObjectiveCFramework", targets: ["ObjectiveCFramework"])
  ],
  targets: [
    .target(name: "ObjectiveCFramework")
  ]
)
