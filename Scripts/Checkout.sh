#!/bin/bash

##===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===##
##
##  Checkout.sh
##  objective-c-framework
##
##  Created by Fang Ling on 2026/10/24.
##
##  This file is part of the ObjectiveCFramework open source project
##
##  Copyright (c) 2026 Fang Ling <fangling@fangl.ing>
##  Licensed under GNU Lesser General Public License v3.0
##
##  See LICENSE for license information
##
##  SPDX-License-Identifier: LGPL-3.0-only
##
##===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===##

mkdir -p .build/stage/include .build/stage/lib

cp -r ../c-framework/.build/stage/include/CFramework .build/stage/include/
cp -p ../c-framework/.build/stage/lib/libCFramework.a .build/stage/lib/
