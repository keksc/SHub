# CMakeList.txt : CMake project for SHub, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (SHub "SHub.cpp" "../glad/gl.c" )
target_link_directories(SHub PUBLIC "${PROJECT_SOURCE_DIR}/lib")
target_include_directories(SHub PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(SHub "glfw3")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SHub PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
