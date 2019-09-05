add_library(minitotp
  hotp.c
  totp.c)
set_target_properties(minitotp PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  PUBLIC_HEADER include/minitotp.h)
target_include_directories(minitotp PUBLIC include)
target_link_libraries(minitotp OpenSSL::Crypto)
install(TARGETS minitotp
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(minitotp.pc.in minitotp.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/minitotp.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

if(BUILD_TESTING)
  function(add_minitotp_test name)
    add_executable(minitotp_test_${name} tests/test_${name}.c)
    target_link_libraries(minitotp_test_${name} minitotp)
    add_test(NAME ${name} COMMAND minitotp_test_${name})
  endfunction()

  add_minitotp_test(hotp_rfc4226)
  add_minitotp_test(totp_rfc6238)
endif(BUILD_TESTING)
