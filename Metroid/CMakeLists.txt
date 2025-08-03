# CMakeList.txt : CMake project for Metroid, include source and define
# project specific logic here.
#

# Add source to this project's executable.

add_executable (Metroid "Metroid.cpp" "Metroid.h" "InputManager/Input.h" "InputManager/Input.cpp" "AssetManager/AssetManager.h" "AssetManager/AssetManager.cpp" "Renderer/Renderer.h" "Renderer/Renderer.cpp")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(Metroid SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Metroid PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
