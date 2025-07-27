#pragma once

#include "rectangle.h"
#include <optional>
#include <set>
#include <vector>

struct Intersection {
  Rectangle area;
  std::set<int> involved_rect_indices; // Indices from input list
};

class IntersectionDetector {
public:
  explicit IntersectionDetector(const std::vector<Rectangle> &rects);

  std::optional<Rectangle> intersect(const Rectangle &a, const Rectangle &b);
  void compute_intersections();
  void print_intervals() const;
  const std::vector<Intersection> &get_intersections() const {
    return intersections;
  };

private:
  const std::vector<Rectangle> &rectangles;
  std::vector<Intersection> intersections{};
};