#include "../include/rectangle_input_manager.h"
#include <fstream>
#include <gtest/gtest.h>

TEST(RectangleInputManagerTest, LoadsValidJson) {
  std::string_view filename = "test_input.json";

  std::ofstream out{filename.data()};
  out << R"({
        "rects": [
            {"x": 0, "y": 0, "w": 100, "h": 100},
            {"x": 50, "y": 50, "w": 100, "h": 100}
        ]
    })";
  out.close();

  RectangleInputManager manager;
  manager.load_input(filename);
  const auto &rects = manager.get_rectangles();

  ASSERT_EQ(rects.size(), 2);
  EXPECT_EQ(rects[0].x, 0);
  EXPECT_EQ(rects[0].y, 0);
  EXPECT_EQ(rects[0].w, 100);
  EXPECT_EQ(rects[0].h, 100);
  EXPECT_EQ(rects[1].x, 50);
  EXPECT_EQ(rects[1].y, 50);
  EXPECT_EQ(rects[1].w, 100);
  EXPECT_EQ(rects[1].h, 100);
}

TEST(RectangleInputManagerTest, LoadsInvalidJson) {
  std::string_view filename = "test_input.json";

  std::ofstream out{filename.data()};
  out << R"({
    })";
  out.close();

  RectangleInputManager manager;
  manager.load_input(filename);
  const auto &rects = manager.get_rectangles();

  ASSERT_EQ(rects.size(), 0);
}

TEST(RectangleInputManagerTest, LoadsInvalidRectangle) {
  std::string_view filename = "test_input.json";

  std::ofstream out{filename.data()};
  out << R"({
        "rects": [
            {"x": 0, "y": 0, "w": 0, "h": 100},
            {"x": 50, "y": 50, "w": 100, "h": 100}
        ]
    })";
  out.close();

  RectangleInputManager manager;
  manager.load_input(filename);
  const auto &rects = manager.get_rectangles();

  ASSERT_EQ(rects.size(), 1);
}