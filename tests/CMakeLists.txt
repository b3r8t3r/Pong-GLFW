link_libraries(TYPES)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(console-tests WIN32 tests.c)
target_link_libraries(console-tests PRIVATE TYPES)
if (MSVC)
    set_target_properties(console-tests PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()
if (MINGW)
    set_target_properties(console-tests PROPERTIES LINK_FLAGS "-mconsole")
endif()