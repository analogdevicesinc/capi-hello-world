# Copyright (c) 2026 Analog Devices, Inc.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.27)

# CAPI_DIR is the capi checkout.
# Set it as an environment variable or with -DCAPI_DIR=<path>.
if(NOT DEFINED CAPI_DIR)
    if(NOT DEFINED ENV{CAPI_DIR})
        message(FATAL_ERROR
            "CAPI_DIR not set. Export CAPI_DIR=/path/to/capi or pass -DCAPI_DIR=...")
    endif()
    set(CAPI_DIR "$ENV{CAPI_DIR}")
endif()

include("${CAPI_DIR}/sdk/cmake/capi_create_application.cmake")

# capi_resolve_platform() sets CMAKE_TOOLCHAIN_FILE for the platform that
# PLATFORM selects. Call it before project(), because CMake reads the
# toolchain file there.
# project() must be a literal call in this file. CMake does not see a
# project() inside a macro. It then runs an implicit project() with the
# host compiler first.
capi_resolve_platform()
project(hello_capi LANGUAGES C ASM)
capi_create_application(hello_capi SOURCES src/main.c)
