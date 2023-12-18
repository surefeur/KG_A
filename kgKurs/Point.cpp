#include "Point.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

void Point::namePoint(char* name) {
    int tmpX = x - 0.5 * z;
    int tmpY = y + 0.5 * z;
    outtextxy(tmpX, tmpY, name);
}


Point::Point() {}

Point::Point(float px, float py, float pz) {
    x = px;
    y = py;
    z = pz;
}

Point::Point(float px, float py, float pz, char* pname) {
    x = px;
    y = py;
    z = pz;
    name = pname;
}

Point operator - (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x - p2.x;
    p3.y = p1.y - p2.y;
    p3.z = p1.z - p2.z;
    return p3;
}

Point operator + (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    p3.z = p1.z + p2.z;
    return p3;
}

Point operator * (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x * p2.x;
    p3.y = p1.y * p2.y;
    p3.z = p1.z * p2.z;
    return p3;
}

Point operator * (Point p1, float a) {
    Point p3;
    p3.x = p1.x * a;
    p3.y = p1.y * a;
    p3.z = p1.z * a;
    return p3;
}
Point operator * (float a, Point p1) {
    Point p3;
    p3 = p1 * a;
    return p3;
}