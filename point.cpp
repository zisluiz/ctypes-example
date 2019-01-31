#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Point
{
    public:
        Point();
        Point(int x, int y, int z);
        int x,y,z;
};

Point::Point() {
}

Point::Point(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}