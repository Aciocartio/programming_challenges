#include "intersection_detector.h"
#include <algorithm>
#include <iostream>

IntersectionDetector::IntersectionDetector(const std::vector<Rectangle> &rects)
    : rectangles(rects) {}

std::optional<Rectangle> IntersectionDetector::intersect(const Rectangle &a,
                                                         const Rectangle &b) {
  int left = std::max(a.x, b.x);
  int top = std::max(a.y, b.y);
  int right = std::min(a.x + a.w, b.x + b.w);
  int bottom = std::min(a.y + a.h, b.y + b.h);

  Rectangle out{left, top, right - left, bottom - top};

  return (out.is_valid()) ? std::optional<Rectangle>(out) : std::nullopt;
}

void IntersectionDetector::compute_intersections() {
  std::set<std::set<int>> seen_combinations;

  for (size_t i = 0; i < rectangles.size(); ++i) {
    for (size_t j = i + 1; j < rectangles.size(); ++j) {
      if (auto rectangle = intersect(rectangles[i], rectangles[j]); rectangle) {
        std::set<int> ids = {static_cast<int>(i), static_cast<int>(j)};
        if (seen_combinations.insert(ids).second) {
          intersections.push_back(Intersection{*rectangle, ids});
        }
      }
    }
  }
 
  // between intersections and rectangles
  bool changed = true;
  while (changed) {
    changed = false;
    std::vector<Intersection> newResults;

    for (const auto &intersection : intersections) {
      for (size_t i = 0; i < rectangles.size(); ++i) {
        if (const auto &aux = intersection.involved_rect_indices.find(i);
            aux != intersection.involved_rect_indices.end())
          continue;

        if (auto rectangle = intersect(intersection.area, rectangles[i]);
            rectangle) {
          std::set<int> ids = intersection.involved_rect_indices;
          ids.insert(static_cast<int>(i));

          if (seen_combinations.insert(ids).second) {
            newResults.push_back(Intersection{*rectangle, ids});
            changed = true;
          }
        }
      }
    }

    intersections.insert(intersections.end(), newResults.begin(),
                         newResults.end());
  }
}

void IntersectionDetector::print_intervals() const {
  std::cout << "\nIntersections:\n";
  for (const auto &i : intersections) {
    std::cout << "Between rectangles { ";
    for (int idx : i.involved_rect_indices)
      std::cout << idx + 1 << " ";
    std::cout << "} at (" << i.area.x << ", " << i.area.y
              << "), w=" << i.area.w << ", h=" << i.area.h << ".\n";
  }
}
