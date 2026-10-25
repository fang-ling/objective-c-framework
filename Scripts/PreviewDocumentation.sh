#!/bin/bash

##===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===##
##
##  PreviewDocumentation.sh
##  objective-c-framework
##
##  Created by Fang Ling on 2026/9/27.
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

SYMBOLS_FOLDER="/dev/shm/symbol-graphs"
OUTPUT_FOLDER="/dev/shm/docc"

clang                                                                           \
    -extract-api                                                                \
    --product-name=ObjectiveCFramework                                          \
    -o $SYMBOLS_FOLDER/ObjectiveCFramework.symbols.json                         \
    -x objective-c-header                                                       \
    Sources/ObjectiveCFramework/Includes/ObjectiveCFramework/ObjectiveCAPI.h    \
    Sources/ObjectiveCFramework/Includes/ObjectiveCFramework/ObjectiveCObject.h \
    -ISources/ObjectiveCFramework/Includes                                      \
    -I../c-framework/Sources/CFramework/Includes                                \
    -I.

docc convert Sources/ObjectiveCFramework/Documentation.docc -o $OUTPUT_FOLDER --additional-symbol-graph-dir $SYMBOLS_FOLDER

echo "========================================"
echo "Starting Local Preview Server"
echo "    Address: http://"$(ip route get 1.1.1.1 | grep -oP '(?<=src\s)\d+(\.\d+){3}')"/documentation/objectivecframework"
echo "========================================"

python3 -m http.server 80 --directory $OUTPUT_FOLDER
