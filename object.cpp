#include <string>
#include <iostream>
#include <vector>
#include "point.cpp"

using namespace std;

class Object
{
    public:
        Object();
        Object(int id, int pointsLength, Point *points);
        int id;
        int pointsLength;
        Point *points; 
};

Object::Object() {

}

Object::Object(int id, int pointsLength, Point *points)
{
    this->id = id;
    this->pointsLength = pointsLength;
    this->points = points;
}

static Object* testArray() {
    printf("Calling method\n");
    Object *objs = new Object[3];

    Point *points1 = new Point[3];
    points1[0] = Point(1,2,3);
    points1[1] = Point(11,22,33);
    points1[2] = Point(111,222,333);
    Point *points2 = new Point[3];
    points2[0] = Point(4,5,6);
    points2[1] = Point(44,55,66);
    points2[2] = Point(444,555,666);
    Point *points3 = new Point[3];
    points3[0] = Point(7,8,9);
    points3[1] = Point(77,88,99);
    points3[2] = Point(777,888,999);

    objs[0] = Object(1, 3, points1);
    objs[1] = Object(2, 3, points2);
    objs[2] = Object(3, 3, points3);
    printf("Returning calling method\n");
    return objs;
} 

extern "C"
{
    using namespace std;

    Object* Object_test() {
        return new Object(1, 1, new Point(1,2,3));        
    }
    Object* Object_testArray() {      
        return testArray() ;
    }    
    void Object_cleanup_point(Object* objectToClean) {
        cout << "cleanup_point called" << endl;
        if (objectToClean) {
            delete objectToClean;
        }      
    }

    void Object_cleanup_ArrayPoint(Object* objectToClean) {
        cout << "cleanup_point called" << endl;
        if (objectToClean) {
            delete[] objectToClean;
        }      
    }        
}