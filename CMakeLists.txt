cmake_minimum_required(VERSION 3.13)

project(minitotp
  VERSION 1.0.0
  DESCRIPTION "Easy RFC 6238 time-based one-time passwords"
  HOMEPAGE_URL "https://offtopica.uk/projects/minitotp"
  LANGUAGES C)

include(CTest)
include(GNUInstallDirs)

option(BUILD_MTOTP "Build the mtotp program" ON)

find_package(OpenSSL REQUIRED)

add_subdirectory(libminitotp)

if(BUILD_MTOTP)
  add_subdirectory(mtotp)
endif(BUILD_MTOTP)
