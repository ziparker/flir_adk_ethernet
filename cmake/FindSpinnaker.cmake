# @file FindSpinnaker.cmake
#
# Copyright 2020
# Carnegie Robotics, LLC
# 4501 Hatfield Street, Pittsburgh, PA 15201
# http://www.carnegierobotics.com
#
# Significant history (date, user, job code, action):
#   2020-10-08, jgeissinger@carnegierobotics.com, 2040, Created file.

unset(SPINNAKER_FOUND)
unset(SPINNAKER_INCLUDE_DIRS)
unset(SPINNAKER_LIB)

find_path(SPINNAKER_DIR NAMES Spinnaker.h
    HINTS
        ${CMAKE_PREFIX_PATH}/include/spinnaker
    PATH_SUFFIXES
        spinnaker)

get_filename_component(SPINNAKER_PARENT_DIR ${SPINNAKER_DIR} DIRECTORY)

set(SPINNAKER_INCLUDE_DIRS "${SPINNAKER_DIR};${SPINNAKER_PARENT_DIR}")

find_path(SPINNAKER_LIBRARIES NAMES libSpinnaker.so
    HINTS
    ${CMAKE_PREFIX_PATH}/lib)

if (SPINNAKER_INCLUDE_DIRS AND SPINNAKER_LIB)
  set(SPINNAKER_FOUND 1)
endif (SPINNAKER_INCLUDE_DIRS AND SPINNAKER_LIB)

set(Spinnaker_INCLUDE_DIRS ${SPINNAKER_INCLUDE_DIRS})
set(Spinnaker_LIBRARIES ${SPINNAKER_LIBRARIES})
