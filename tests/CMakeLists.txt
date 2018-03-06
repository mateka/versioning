add_executable(version_tests version_tests.cpp)
target_link_libraries(version_tests versioning catch::catch)
add_test(NAME version_tests COMMAND version_tests)
