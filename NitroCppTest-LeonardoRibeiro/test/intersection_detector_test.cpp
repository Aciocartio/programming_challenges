#include "../include/intersection_detector.h"
#include "rectangle.h"
#include <gtest/gtest.h>
#include <vector>

TEST(IntersectionDetectorTest, BasicIntersection) {
  Rectangle a{0, 0, 10, 10};
  Rectangle b{5, 5, 10, 10};
  Rectangle out{5, 5, 5, 5};

  std::vector<Rectangle> test_vector{a, b};

  IntersectionDetector detector(test_vector);
  EXPECT_EQ(detector.intersect(a, b).value(), out);
}

TEST(IntersectionDetectorTest, NoIntersection) {
  Rectangle a{0, 0, 2, 2};
  Rectangle b{5, 5, 10, 10};

  std::vector<Rectangle> test_vector{a, b};

  IntersectionDetector detector(test_vector);
  EXPECT_EQ(detector.intersect(a, b), std::nullopt);
}

TEST(IntersectionDetectorTest, ComputeIntersections) {
  Rectangle a{100, 100, 250, 80};
  Rectangle b{120, 200, 250, 150};
  Rectangle c{140, 160, 250, 100};
  Rectangle d{160, 140, 350, 190};

  std::vector<Rectangle> input_vector{a, b, c, d};

  IntersectionDetector detector(input_vector);
  detector.compute_intersections();
  const auto &intersections{detector.get_intersections()};

  Rectangle out0{140, 160, 210, 20};
  Rectangle out1{160, 140, 190, 40};
  Rectangle out2{140, 200, 230, 60};
  Rectangle out3{160, 200, 210, 130};
  Rectangle out4{160, 160, 230, 100};
  Rectangle out5{160, 160, 190, 20};
  Rectangle out6{160, 200, 210, 60};

  EXPECT_EQ(intersections.at(0).area, out0);
  EXPECT_EQ(intersections.at(1).area, out1);
  EXPECT_EQ(intersections.at(2).area, out2);
  EXPECT_EQ(intersections.at(3).area, out3);
  EXPECT_EQ(intersections.at(4).area, out4);
  EXPECT_EQ(intersections.at(5).area, out5);
  EXPECT_EQ(intersections.at(6).area, out6);
  EXPECT_EQ(intersections.size(), 7);
}
