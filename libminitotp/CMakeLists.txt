add_library(minitotp SHARED
  minitotp.c)
set_target_properties(minitotp PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  PUBLIC_HEADER include/minitotp.h)
target_include_directories(minitotp PUBLIC include)
target_link_libraries(minitotp OpenSSL::Crypto)
install(TARGETS minitotp
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(minitotp.pc.in minitotp.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/minitotp.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
