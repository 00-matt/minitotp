add_executable(mtotp
  main.c)
target_link_libraries(mtotp minitotp)
install(TARGETS mtotp
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
