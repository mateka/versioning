cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(versioning VERSION 1.0.0.0 LANGUAGES CXX)

find_package(catch REQUIRED)

add_library(versioning src/version.cpp)
target_include_directories(
    versioning
    PUBLIC
        $<BUILD_INTERFACE:${versioning_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/versioning/versioning-config-version.cmake"
    VERSION ${versioning_VERSION}
    COMPATIBILITY AnyNewerVersion
)
configure_file(
    cmake/versioning-config.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/versioning/versioning-config.cmake"
    COPYONLY
)

add_library(versioning::versioning ALIAS versioning)
install(
    TARGETS versioning EXPORT versioning-targets
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include DESTINATION include)
install(
    EXPORT versioning-targets
    FILE versioning-targets.cmake
    NAMESPACE versioning::
    DESTINATION lib/cmake/versioning
)
install(
    FILES cmake/versioning-config.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/versioning/versioning-config-version.cmake"
    DESTINATION lib/cmake/versioning
)

# This makes the project importable from the build directory
export(TARGETS versioning FILE versioning-targets.cmake)

enable_testing()
add_subdirectory(tests)
