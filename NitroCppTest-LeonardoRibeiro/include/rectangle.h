#pragma once
class Rectangle {
public:
  explicit Rectangle(int x, int y, int w, int h);

  bool is_valid() const;
  void print() const;

  bool operator==(const Rectangle &other) const;

  int x, y, w, h;
};