#include <iostream>

#include "manip.cpp"

int main() {
    Manipulator manip_1, manip_2;
    Point target = {10, 10};
    manip_1.position = {1, 1};
    manip_1.radius = 1;
    manip_1.ID = 1;
    manip_2.position = {0, 0};
    manip_2.radius = 5;
    manip_2.ID = 2;
    try
    {
        std::cout << BestManip(manip_1, manip_2, target).ID << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
