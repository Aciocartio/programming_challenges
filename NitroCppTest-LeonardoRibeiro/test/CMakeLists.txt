# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(rectangle_test rectangle_test.cpp ../src/rectangle.cpp)
add_executable(intersection_detector_test intersection_detector_test.cpp ../src/intersection_detector.cpp ../src/rectangle.cpp)
add_executable(rectangle_input_manager_test rectangle_input_manager_test.cpp ../src/rectangle_input_manager.cpp ../src/rectangle.cpp)

target_include_directories(rectangle_test PRIVATE ../include)
target_include_directories(intersection_detector_test PRIVATE ../include)
target_include_directories(rectangle_input_manager_test PRIVATE ../include )

target_link_libraries(rectangle_test gtest_main)
target_link_libraries(intersection_detector_test gtest_main)
target_link_libraries(rectangle_input_manager_test gtest_main nlohmann_json::nlohmann_json)

include(GoogleTest)
gtest_discover_tests(rectangle_test)
gtest_discover_tests(intersection_detector_test)
gtest_discover_tests(rectangle_input_manager_test)
