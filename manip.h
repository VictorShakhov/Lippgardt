#pragma once

#include <vector>

struct Point {
    double x = 0;
    double y = 0;
};

struct Manipulator {
    Point position;
    double radius;
    int ID;
    std::vector<Point> history;
};

double Range(const Point& first, const Point& second);

const Manipulator& BestManip(const Manipulator& first_manip, const Manipulator& second_manip, const Point& target);
