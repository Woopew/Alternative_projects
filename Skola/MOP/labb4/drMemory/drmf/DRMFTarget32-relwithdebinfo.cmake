#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
SET(CMAKE_IMPORT_FILE_VERSION 1)

# Compute the installation prefix relative to this file.
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)

# Make sure the targets which have been exported in some other 
# export set exist.
IF(NOT TARGET "dynamorio" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"dynamorio\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"dynamorio\" not found ! ")
  ENDIF()
ENDIF()
IF(NOT TARGET "drmgr" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"drmgr\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"drmgr\" not found ! ")
  ENDIF()
ENDIF()
IF(NOT TARGET "drcontainers" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"drcontainers\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"drcontainers\" not found ! ")
  ENDIF()
ENDIF()

# Import target "drsyscall" for configuration "RelWithDebInfo"
SET_PROPERTY(TARGET drsyscall APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
SET_TARGET_PROPERTIES(drsyscall PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/drmf/lib32/release/drsyscall.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/drmf/lib32/release/drsyscall.dll"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS drsyscall )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_drsyscall "${_IMPORT_PREFIX}/drmf/lib32/release/drsyscall.lib" "${_IMPORT_PREFIX}/drmf/lib32/release/drsyscall.dll" )

# Make sure the targets which have been exported in some other 
# export set exist.
IF(NOT TARGET "dynamorio" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"dynamorio\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"dynamorio\" not found ! ")
  ENDIF()
ENDIF()
IF(NOT TARGET "drmgr" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"drmgr\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"drmgr\" not found ! ")
  ENDIF()
ENDIF()
IF(NOT TARGET "drcontainers" )
  IF(CMAKE_FIND_PACKAGE_NAME)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    SET( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "Required imported target \"drcontainers\" not found ! ")
  ELSE()
    MESSAGE(FATAL_ERROR "Required imported target \"drcontainers\" not found ! ")
  ENDIF()
ENDIF()

# Import target "umbra" for configuration "RelWithDebInfo"
SET_PROPERTY(TARGET umbra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
SET_TARGET_PROPERTIES(umbra PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/drmf/lib32/release/umbra.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/drmf/lib32/release/umbra.dll"
  )

LIST(APPEND _IMPORT_CHECK_TARGETS umbra )
LIST(APPEND _IMPORT_CHECK_FILES_FOR_umbra "${_IMPORT_PREFIX}/drmf/lib32/release/umbra.lib" "${_IMPORT_PREFIX}/drmf/lib32/release/umbra.dll" )

# Loop over all imported files and verify that they actually exist
FOREACH(target ${_IMPORT_CHECK_TARGETS} )
  FOREACH(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    IF(NOT EXISTS "${file}" )
      MESSAGE(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    ENDIF()
  ENDFOREACH()
  UNSET(_IMPORT_CHECK_FILES_FOR_${target})
ENDFOREACH()
UNSET(_IMPORT_CHECK_TARGETS)

# Cleanup temporary variables.
SET(_IMPORT_PREFIX)

# Commands beyond this point should not need to know the version.
SET(CMAKE_IMPORT_FILE_VERSION)
