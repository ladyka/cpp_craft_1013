cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set( CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "Configurations" FORCE )
project( ${SOLUTION_NAME} )
include( environment.cmake required )

modules( binary_reader )
binaries( 2_4_trades_filter 2_5_small_buffer 2_6_binary_datafeed )

compile()
