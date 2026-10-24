##===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===##
##
##  Makefile
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

NAME              := ObjectiveCFramework
BUILD_DIRECTORY   := .build
OBJECTS_DIRECTORY := $(BUILD_DIRECTORY)/objects
PREFIX            := $(BUILD_DIRECTORY)/stage

CC      := clang
AR      := llvm-ar
C_FLAGS := -std=gnu99 -I$(PREFIX)/include -ISources/ObjectiveCFramework/Includes -ISources/ObjectiveCFramework/ObjFW -ISources/ObjectiveCFramework/ObjFW/runtime -fobjc-runtime=objfw-1.5 -fno-objc-arc

EXCLUDED_SOURCES     := Sources/ObjectiveCFramework/ObjFW/platform/POSIX/OFPlainMutex.m \
                        Sources/ObjectiveCFramework/ObjFW/OFPlainMutex.m \
                        Sources/ObjectiveCFramework/ObjFW/OFOnce.m \
                        Sources/ObjectiveCFramework/ObjFW/lookup-asm/lookup-asm-amd64-elf.S \
                        Sources/ObjectiveCFramework/ObjFW/lookup-asm/lookup-asm-arm64-elf.S
SOURCES              := $(filter-out $(EXCLUDED_SOURCES), $(shell find Sources/ObjectiveCFramework -type f \( -name '*.m' -o -name '*.S' \)))
OBJECTS              := $(patsubst Sources/%.m,$(OBJECTS_DIRECTORY)/%.o,$(patsubst Sources/%.S,$(OBJECTS_DIRECTORY)/%.o,$(SOURCES)))
LIBRARY              := $(BUILD_DIRECTORY)/library/lib$(NAME).a
COMPILATION_DATABASE := $(BUILD_DIRECTORY)/compile_commands.json

.PHONY: all install clean

all: $(LIBRARY) $(COMPILATION_DATABASE)

$(LIBRARY): $(OBJECTS)
	@mkdir -p $(@D)
	$(AR) rcs $@ $^

$(OBJECTS_DIRECTORY)/ObjectiveCFramework/%.o: Sources/ObjectiveCFramework/%.m
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) -MMD -MP -MJ $@.json -c $< -o $@

$(OBJECTS_DIRECTORY)/ObjectiveCFramework/%.o: Sources/ObjectiveCFramework/%.S
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) -MMD -MP -MJ $@.json -c $< -o $@

$(COMPILATION_DATABASE): $(OBJECTS)
	{ echo '['; cat $(OBJECTS:=.json) | sed '$$ s/,$$//'; echo ']'; } > $@

install: $(LIBRARY)
	mkdir -p $(PREFIX)/lib $(PREFIX)/include
	cp -p $(LIBRARY) $(PREFIX)/lib
	cp -pR Sources/ObjectiveCFramework/Includes/. $(PREFIX)/include

clean:
	rm -rf $(OBJECTS_DIRECTORY) $(BUILD_DIRECTORY)/library $(COMPILATION_DATABASE) $(PREFIX)

show-build-path:
	@echo $(BUILD_DIRECTORY)

-include $(OBJECTS:.o=.d)
