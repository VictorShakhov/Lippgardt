#include "manip.h"

#include <math.h>
#include <stdexcept>

double Range(const Point& first, const Point& second)
{
    return std::sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

Manipulator& BestManip(Manipulator& first_manip, Manipulator& second_manip, const Point& target)
{
    double range_from_first = Range(first_manip.position, target);
    double range_from_second = Range(second_manip.position, target);
    if(range_from_first <= first_manip.radius && range_from_second <= second_manip.radius)
    {
        return range_from_first < range_from_second ? first_manip : second_manip;
    }
    if(range_from_first <= first_manip.radius)
    {
        return first_manip;
    }
    if(range_from_second <= second_manip.radius)
    {
        return second_manip;
    }
    throw std::range_error("OUT OF RANGE");
}