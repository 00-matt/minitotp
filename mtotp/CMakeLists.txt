add_executable(mtotp
  main.c)
target_compile_definitions(mtotp PRIVATE _XOPEN_SOURCE=600)
target_link_libraries(mtotp minitotp)
install(TARGETS mtotp
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(BUILD_TESTING)
  if(BASH_PROGRAM)
    add_test(NAME mtotp_test COMMAND ${BASH_PROGRAM}
      ${CMAKE_CURRENT_SOURCE_DIR}/mtotp_test.sh
      $<TARGET_FILE:mtotp>)
  else(BASH_PROGRAM)
    message(WARNING "Bash is required for mtotp tests but could not be found")
  endif(BASH_PROGRAM)
endif(BUILD_TESTING)
