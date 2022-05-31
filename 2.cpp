#include "manip.cpp"

#include <vector>
#include <iostream>

void RunPoints(Manipulator& manip_1, Manipulator& manip_2, std::vector<Point>& points)
{
    for(const Point& point : points)
    {
        Manipulator& manip = Range(manip_1.position, point) <= Range(manip_2.position, point) ? manip_1 : manip_2;
        manip.history.push_back(point);
        manip.position = point;
    }
}

void PrintHistrory(Manipulator& manip)
{
    for(auto point : manip.history)
    {
        std::cout << "{" << point.x << ", " << point.y << "} ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<Point> points = {{1, 3}, {2, 1.41}, {0.2, -7}, {-5, -1}, {0, 9}};
    Manipulator manip_1, manip_2;
    manip_1.position = {0, 0};
    manip_1.radius = 4;
    manip_2.position = {2, 1};
    manip_2.radius = 3;
    try
    {
        RunPoints(manip_1, manip_2, points);
        PrintHistrory(manip_1);
        PrintHistrory(manip_2);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}