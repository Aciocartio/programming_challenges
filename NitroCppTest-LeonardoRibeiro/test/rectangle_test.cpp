#include "../include/rectangle.h"
#include <gtest/gtest.h>

TEST(RectangleTest, IsValid) {
  Rectangle a{0, 0, 10, 10};
  Rectangle b{2, 2, 0, 4};
  Rectangle c{2, 2, 4, 0};

  EXPECT_TRUE(a.is_valid());
  EXPECT_FALSE(b.is_valid());
  EXPECT_FALSE(c.is_valid());
}