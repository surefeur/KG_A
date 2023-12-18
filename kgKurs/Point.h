#pragma once
// класс для точек
class Point {
public:
    float x;
    float y;
    float z;
    char* name;

    void namePoint(char* name);
    
    Point();
    Point(float px, float py, float pz);
    Point(float px, float py, float pz, char* pname);

};

// перегрузки операторов
Point operator - (Point p1, Point p2);
Point operator + (Point p1, Point p2);
Point operator * (Point p1, Point p2);
Point operator * (Point p1, float a);
Point operator * (float a, Point p1);
