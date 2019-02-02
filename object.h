#include <string>
#include "point.h"

class Object
{
    public:
        Object();
        Object(int id, int pointsLength, Point *points);
        int id;
        int pointsLength;
        Point *points; 
};