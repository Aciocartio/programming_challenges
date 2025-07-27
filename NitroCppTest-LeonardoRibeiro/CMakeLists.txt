cmake_minimum_required(VERSION 3.15)
project(RectangleIntersection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    json 
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(rectangle_intersections src/main.cpp src/rectangle.cpp src/rectangle_input_manager.cpp src/intersection_detector.cpp)
target_link_libraries(rectangle_intersections PRIVATE nlohmann_json::nlohmann_json)

enable_testing()

# Add subdirectories
add_subdirectory(test)
