cmake_minimum_required(VERSION 3.13)

project(minitotp
  VERSION 2.0.1
  DESCRIPTION "Easy RFC 6238 time-based one-time passwords"
  HOMEPAGE_URL "https://offtopica.uk/projects/minitotp"
  LANGUAGES C)

option(BUILD_MTOTP "Build the mtotp program" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTS "Build tests and enable the test target" ON)

include(GNUInstallDirs)

if(BUILD_TESTS)
  include(CTest)
endif(BUILD_TESTS)

add_subdirectory(libminitotp)

if(BUILD_MTOTP)
  add_subdirectory(mtotp)
endif(BUILD_MTOTP)
