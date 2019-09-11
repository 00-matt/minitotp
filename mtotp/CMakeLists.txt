add_executable(mtotp
  main.c)
target_compile_definitions(mtotp PRIVATE _XOPEN_SOURCE=600)
target_link_libraries(mtotp minitotp)
install(TARGETS mtotp
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
