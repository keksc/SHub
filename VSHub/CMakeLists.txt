# CMakeList.txt : CMake project for SHub, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (VSHub "VSHub.cpp" "../glad/gl.c" )
target_link_directories(VSHub PUBLIC "${PROJECT_SOURCE_DIR}/lib")
target_include_directories(VSHub PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(VSHub "glfw3" "freetype")

if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set_target_properties(VSHub PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    endif()
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VSHub PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
