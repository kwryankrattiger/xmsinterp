# Import the XMS::Interp target
find_package(Boost QUIET REQUIRED log_setup log system filesystem serialization timer)
include(${CMAKE_CURRENT_LIST_DIR}/xmsinterp-targets.cmake)

# Get the root installation dir
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

include(GNUInstallDirs)

# Set the FindXMSCore variables
set(XMSInterp_FOUND TRUE)
set(XMSInterp_PREFIX ${CMAKE_CURRENT_LIST_DIR})
set(XMSInterp_LIBRARY_DIRS "${_IMPORT_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
set(XMSInterp_INCLUDE_DIRS "${_IMPORT_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
set(XMSInterp_LIBRARIES XMS::Interp)
set(XMSInterp_VERSION 5.2.0)
