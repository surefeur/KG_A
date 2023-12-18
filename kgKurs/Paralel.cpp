
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Paralel.h"
#include "Colours.h"

using namespace std;


// отрисовка линии попиксельно
void line_DDA(float x1, float y1, float z1, float x2, float y2, float z2, COLORREF cColor) {
    // Учёт координаты z при отрисовке в двумерном пространстве
    x1 -= 0.5 * z1;
    y1 += 0.5 * z1;
    x2 -= 0.5 * z2;
    y2 += 0.5 * z2;

    // Целочисленные значения координат начала и конца отрезка, округлённые до ближайшего целого
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);

    // Длина и высота линии
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);

    // Считаем минимальное количество итераций, необходимое для отрисовки отрезка
    // Выбирая максимум из длины и высоты линии, обеспечиваем связность линии
    int length = max(deltaX, deltaY);

    // особый случай, на экране закрашивается ровно один пиксель
    if (length == 0) {
        putpixel(iX1, iY1, cColor);
        return;
    }
    // Вычисляем приращения на каждом шаге по осям абсцисс и ординат
    double dX = (x2 - x1) / length;
    double dY = (y2 - y1) / length;

    // Начальные значения
    double x = x1;
    double y = y1;

    // Основной цикл
    length++;
    while (length--) {
        x += dX;
        y += dY;
        putpixel(roundf(x), roundf(y), cColor);
    }
}


// имена точек
char name_P1[3] = "1";
char name_P2[3] = "2";
char name_P3[3] = "3";
char name_P4[3] = "4";
char name_P5[3] = "5";
char name_P6[3] = "6";
char name_P7[3] = "7";
char name_P8[3] = "8";
char name_P9[3] = "9";
char name_P10[3] = "10";
char name_P11[3] = "11";
char name_P12[3] = "12";
char name_P13[3] = "13";
char name_P14[3] = "14";
char name_P15[3] = "15";
char name_P16[3] = "16";


// конструктор от 16 точек сразу для двух фигур
Piramid::Piramid(Point P_1, Point P_2, Point P_3, Point P_4,
    Point P_5, Point P_6, Point P_7, Point P_8,
    Point P_9, Point P_10, Point P_11, Point P_12,
    Point P_13, Point P_14, Point P_15, Point P_16) {
    
    P1.x = P_1.x; P1.y = P_1.y; P1.z = P_1.z; P1.name = name_P1;
    P2.x = P_2.x; P2.y = P_2.y; P2.z = P_2.z; P2.name = name_P2;
    P3.x = P_3.x; P3.y = P_3.y; P3.z = P_3.z; P3.name = name_P3;
    P4.x = P_4.x; P4.y = P_4.y; P4.z = P_4.z; P4.name = name_P4;
    P5.x = P_5.x; P5.y = P_5.y; P5.z = P_5.z; P5.name = name_P5;
    P6.x = P_6.x; P6.y = P_6.y; P6.z = P_6.z; P6.name = name_P6;
    P7.x = P_7.x; P7.y = P_7.y; P7.z = P_7.z; P7.name = name_P7;
    P8.x = P_8.x; P8.y = P_8.y; P8.z = P_8.z; P8.name = name_P8;
    P9.x = P_9.x; P9.y = P_9.y; P9.z = P_9.z; P9.name = name_P9;
    P10.x = P_10.x; P10.y = P_10.y; P10.z = P_10.z; P10.name = name_P10;
    P11.x = P_11.x; P11.y = P_11.y; P11.z = P_11.z; P11.name = name_P11;
    P12.x = P_12.x; P12.y = P_12.y; P12.z = P_12.z; P12.name = name_P12;
    P13.x = P_13.x; P13.y = P_13.y; P13.z = P_13.z; P13.name = name_P13;
    P14.x = P_14.x; P14.y = P_14.y; P14.z = P_14.z; P14.name = name_P14;
    P15.x = P_15.x; P15.y = P_15.y; P15.z = P_15.z; P15.name = name_P15;
    P16.x = P_16.x; P16.y = P_16.y; P16.z = P_16.z; P16.name = name_P16;
    drawParaGram();
}


// отрисовка
void Piramid::drawParaGram() {
    // оси
    setcolor(WHITE);
    line(700, 350, 730, 350); char xCoord[2] = "x"; outtextxy(735, 350, xCoord);
    line(700, 350, 700, 320); char yCoord[2] = "y"; outtextxy(700, 300, yCoord);
    line(700, 350, 685, 365); char zCoord[2] = "z"; outtextxy(680, 370, zCoord);

    // инструкции
    char w[20] = "W - Up";
    char a[20] = "A - Left";
    char s[20] = "S - Down";
    char d[20] = "D - Right";
    char z[20] = "Z - Forward";
    char x[20] = "X - Backward";
    char qrf[30] = "Q, R, F - Counter clockwise";
    char etg[20] = "E, T, G - Clockwise";
    char plus[20] = "+ - Scale up";
    char minus[20] = "- - Scale down";
    char other[20] = "Any other - Exit";

    // вывод инструкций
    outtextxy(1140, 20, w);
    outtextxy(1140, 40, a);
    outtextxy(1140, 60, s);
    outtextxy(1140, 80, d);
    outtextxy(1140, 100, z);
    outtextxy(1140, 120, x);
    outtextxy(1140, 140, qrf);
    outtextxy(1140, 160, etg);
    outtextxy(1140, 180, plus);
    outtextxy(1140, 200, minus);
    outtextxy(1140, 220, other);
    
    // вывод имён точек
    setcolor(TEXTCOL);
    P1.namePoint(P1.name);
    P2.namePoint(P2.name);
    P3.namePoint(P3.name);
    P4.namePoint(P4.name);
    P5.namePoint(P5.name);
    P6.namePoint(P6.name);
    P7.namePoint(P7.name);
    P8.namePoint(P8.name);
    P9.namePoint(P9.name);
    P10.namePoint(P10.name);
    P11.namePoint(P11.name);
    P12.namePoint(P12.name);
    P13.namePoint(P13.name);
    P14.namePoint(P14.name);
    P15.namePoint(P15.name);
    P16.namePoint(P16.name);

    //Для первой фигуры
    /*
    * 1-2+
    * 2-3+
    * 3-4+
    * 4-1+
    * 1-5+
    * 2-6+
    * 3-7+
    * 4-8+
    * 5-6+
    * 6-7+
    * 7-8+
    * 8-5+
    */
    // 1-2-3-4
    line_DDA(P1.x, P1.y, P1.z, P2.x, P2.y, P2.z, col); // линия 1
    line_DDA(P2.x, P2.y, P2.z, P3.x, P3.y, P3.z, col); // линия 2
    line_DDA(P3.x, P3.y, P3.z, P4.x, P4.y, P4.z, col); // линия 3
    line_DDA(P4.x, P4.y, P4.z, P1.x, P1.y, P1.z, col); // линия 4
    line_DDA(P5.x, P5.y, P5.z, P1.x, P1.y, P1.z, col); // линия 8
    line_DDA(P2.x, P2.y, P2.z, P6.x, P6.y, P6.z, col); // линия 9
    line_DDA(P3.x, P3.y, P3.z, P7.x, P7.y, P7.z, col); // линия 13
    line_DDA(P8.x, P8.y, P8.z, P4.x, P4.y, P4.z, col); // линия 19
    line_DDA(P5.x, P5.y, P5.z, P6.x, P6.y, P6.z, col); // линия 21
    line_DDA(P6.x, P6.y, P6.z, P7.x, P7.y, P7.z, col); // линия 22
    line_DDA(P7.x, P7.y, P7.z, P8.x, P8.y, P8.z, col); // линия 23
    line_DDA(P8.x, P8.y, P8.z, P5.x, P5.y, P5.z, col); // линия 24

    //Для второй фигуры
    /*
    * 9-10+
    * 10-11+
    * 11-12+
    * 12-9+
    * 9-13
    * 10-14
    * 11-15
    * 12-16
    * 13-14
    * 14-15
    * 15-16
    * 16-13
    */
    line_DDA(P9.x, P9.y, P9.z, P10.x, P10.y, P10.z, col); // линия 1
    line_DDA(P10.x, P10.y, P10.z, P11.x, P11.y, P11.z, col); // линия 2
    line_DDA(P11.x, P11.y, P11.z, P12.x, P12.y, P12.z, col); // линия 3
    line_DDA(P12.x, P12.y, P12.z, P9.x, P9.y, P9.z, col); // линия 4
    line_DDA(P13.x, P13.y, P13.z, P9.x, P9.y, P9.z, col); // линия 4
    line_DDA(P10.x, P10.y, P10.z, P14.x, P14.y, P14.z, col); // линия 1
    line_DDA(P11.x, P11.y, P11.z, P15.x, P15.y, P15.z, col); // линия 1
    line_DDA(P16.x, P16.y, P16.z, P12.x, P12.y, P12.z, col); // линия 3
    line_DDA(P13.x, P13.y, P13.z, P14.x, P14.y, P14.z, col); // линия 1
    line_DDA(P14.x, P14.y, P14.z, P15.x, P15.y, P15.z, col); // линия 2
    line_DDA(P15.x, P15.y, P15.z, P16.x, P16.y, P16.z, col); // линия 3
    line_DDA(P16.x, P16.y, P16.z, P13.x, P13.y, P13.z, col); // линия 4


    // построение теней
    setcolor(WHITE);
    shadowAll(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16);

    // закраска граней фигуры
    zBuff(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16);
}

// пермещение
void Piramid::moveX(float amt) {
    P1.x += amt;
    P2.x += amt;
    P3.x += amt;
    P4.x += amt;
    P5.x += amt;
    P6.x += amt;
    P7.x += amt;
    P8.x += amt;
    P9.x += amt;
    P10.x += amt;
    P11.x += amt;
    P12.x += amt;
    P13.x += amt;
    P14.x += amt;
    P15.x += amt;
    P16.x += amt;
}
void Piramid::moveY(float amt) {
    P1.y += amt;
    P2.y += amt;
    P3.y += amt;
    P4.y += amt;
    P5.y += amt;
    P6.y += amt;
    P7.y += amt;
    P8.y += amt;
    P9.y += amt;
    P10.y += amt;
    P11.y += amt;
    P12.y += amt;
    P13.y += amt;
    P14.y += amt;
    P15.y += amt;
    P16.y += amt;
}
void Piramid::moveZ(float amt) {
    P1.z += amt;
    P2.z += amt;
    P3.z += amt;
    P4.z += amt;
    P5.z += amt;
    P6.z += amt;
    P7.z += amt;
    P8.z += amt;
    P9.z += amt;
    P10.z += amt;
    P11.z += amt;
    P12.z += amt;
    P13.z += amt;
    P14.z += amt;
    P15.z += amt;
    P16.z += amt;
}

// поворот одной точки вокруг z
Point Piramid::rotDotZ(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // расстояние от а до центра по х
    L.y = L.y - Cen.y; // по у

    float tmpX = L.x * cos(ang) + L.y * sin(ang);
    float tmpY = -L.x * sin(ang) + L.y * cos(ang);
    L.x = tmpX + Cen.x;
    L.y = tmpY + Cen.y;

    return L;
}
// поворот фигуры вокруг z
void Piramid::rotateZ(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра 
    Cen.x = (P1.x + P2.x + P3.x + P4.x + 
             P5.x + P6.x + P7.x + P8.x + 
             P9.x + P10.x + P11.x + P12.x + 
             P13.x + P14.x + P15.x + P16.x) / 16;

    Cen.y = (P1.y + P2.y + P3.y + P4.y +
        P5.y + P6.y + P7.y + P8.y +
        P9.y + P10.y + P11.y + P12.y +
        P13.y + P14.y + P15.y + P16.y) / 16;
    
    Cen.z = (P1.z + P2.z + P3.z + P4.z +
        P5.z + P6.z + P7.z + P8.z +
        P9.z + P10.z + P11.z + P12.z +
        P13.z + P14.z + P15.z + P16.z) / 16;

    P1 = rotDotZ(u, ang, Cen, P1);
    P2 = rotDotZ(u, ang, Cen, P2);
    P3 = rotDotZ(u, ang, Cen, P3);
    P4 = rotDotZ(u, ang, Cen, P4);
    P5 = rotDotZ(u, ang, Cen, P5);
    P6 = rotDotZ(u, ang, Cen, P6);
    P7 = rotDotZ(u, ang, Cen, P7);
    P8 = rotDotZ(u, ang, Cen, P8);
    P9 = rotDotZ(u, ang, Cen, P9);
    P10 = rotDotZ(u, ang, Cen, P10);
    P11 = rotDotZ(u, ang, Cen, P11);
    P12 = rotDotZ(u, ang, Cen, P12);
    P13 = rotDotZ(u, ang, Cen, P13);
    P14 = rotDotZ(u, ang, Cen, P14);
    P15 = rotDotZ(u, ang, Cen, P15);
    P16 = rotDotZ(u, ang, Cen, P16);
}

// поворот одной точки вокруг y
Point Piramid::rotDotY(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // расстояние от а до центра по y
    L.z = L.z - Cen.z; // по z

    float tmpX = L.x * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.x * sin(ang) + L.z * cos(ang);
    L.x = tmpX + Cen.x;
    L.z = tmpZ + Cen.z;

    return L;
}
// поворот фигуры вокруг y
void Piramid::rotateY(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра 
    Cen.x = (P1.x + P2.x + P3.x + P4.x +
        P5.x + P6.x + P7.x + P8.x +
        P9.x + P10.x + P11.x + P12.x +
        P13.x + P14.x + P15.x + P16.x) / 16;

    Cen.y = (P1.y + P2.y + P3.y + P4.y +
        P5.y + P6.y + P7.y + P8.y +
        P9.y + P10.y + P11.y + P12.y +
        P13.y + P14.y + P15.y + P16.y) / 16;

    Cen.z = (P1.z + P2.z + P3.z + P4.z +
        P5.z + P6.z + P7.z + P8.z +
        P9.z + P10.z + P11.z + P12.z +
        P13.z + P14.z + P15.z + P16.z) / 16;

    P1 = rotDotY(u, ang, Cen, P1);
    P2 = rotDotY(u, ang, Cen, P2);
    P3 = rotDotY(u, ang, Cen, P3);
    P4 = rotDotY(u, ang, Cen, P4);
    P5 = rotDotY(u, ang, Cen, P5);
    P6 = rotDotY(u, ang, Cen, P6);
    P7 = rotDotY(u, ang, Cen, P7);
    P8 = rotDotY(u, ang, Cen, P8);
    P9 = rotDotY(u, ang, Cen, P9);
    P10 = rotDotY(u, ang, Cen, P10);
    P11 = rotDotY(u, ang, Cen, P11);
    P12 = rotDotY(u, ang, Cen, P12);
    P13 = rotDotY(u, ang, Cen, P13);
    P14 = rotDotY(u, ang, Cen, P14);
    P15 = rotDotY(u, ang, Cen, P15);
    P16 = rotDotY(u, ang, Cen, P16);
}

// поворот одной точки вокруг x
Point Piramid::rotDotX(int u, float ang, Point Cen, Point L) {
    L.y = L.y - Cen.y; // расстояние от а до центра по y
    L.z = L.z - Cen.z; // по z

    float tmpY = L.y * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.y * sin(ang) + L.z * cos(ang);
    L.y = tmpY + Cen.y;
    L.z = tmpZ + Cen.z;

    return L;
}
// поворот фигуры вокруг x
void Piramid::rotateX(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра
    Cen.x = (P1.x + P2.x + P3.x + P4.x +
        P5.x + P6.x + P7.x + P8.x +
        P9.x + P10.x + P11.x + P12.x +
        P13.x + P14.x + P15.x + P16.x) / 16;

    Cen.y = (P1.y + P2.y + P3.y + P4.y +
        P5.y + P6.y + P7.y + P8.y +
        P9.y + P10.y + P11.y + P12.y +
        P13.y + P14.y + P15.y + P16.y) / 16;

    Cen.z = (P1.z + P2.z + P3.z + P4.z +
        P5.z + P6.z + P7.z + P8.z +
        P9.z + P10.z + P11.z + P12.z +
        P13.z + P14.z + P15.z + P16.z) / 16;

    P1 = rotDotX(u, ang, Cen, P1);
    P2 = rotDotX(u, ang, Cen, P2);
    P3 = rotDotX(u, ang, Cen, P3);
    P4 = rotDotX(u, ang, Cen, P4);
    P5 = rotDotX(u, ang, Cen, P5);
    P6 = rotDotX(u, ang, Cen, P6);
    P7 = rotDotX(u, ang, Cen, P7);
    P8 = rotDotX(u, ang, Cen, P8);
    P9 = rotDotX(u, ang, Cen, P9);
    P10 = rotDotX(u, ang, Cen, P10);
    P11 = rotDotX(u, ang, Cen, P11);
    P12 = rotDotX(u, ang, Cen, P12);
    P13 = rotDotX(u, ang, Cen, P13);
    P14 = rotDotX(u, ang, Cen, P14);
    P15 = rotDotX(u, ang, Cen, P15);
    P16 = rotDotX(u, ang, Cen, P16);
}

// масштабирование одной точки
Point Piramid::dotScale(float e, Point Cen, Point L) {
    // L.x
    float xe = (Cen.x + L.x) / 2;
    float lx = Cen.x - L.x;
    lx = lx * e;
    L.x = xe - lx / 2;
    // L.y
    float ye = (Cen.y + L.y) / 2;
    float ly = Cen.y - L.y;
    ly = ly * e;
    L.y = ye - ly / 2;
    // L.z
    float ze = (Cen.z + L.z) / 2;
    float lz = Cen.z - L.z;
    lz = lz * e;
    L.z = ze - lz / 2;

    return L;
}
// масштабирование всей фигуры
void Piramid::scale(float e) {
    Point Cen; // точка центра 
    Cen.x = (P1.x + P2.x + P3.x + P4.x +
        P5.x + P6.x + P7.x + P8.x +
        P9.x + P10.x + P11.x + P12.x +
        P13.x + P14.x + P15.x + P16.x) / 16;

    Cen.y = (P1.y + P2.y + P3.y + P4.y +
        P5.y + P6.y + P7.y + P8.y +
        P9.y + P10.y + P11.y + P12.y +
        P13.y + P14.y + P15.y + P16.y) / 16;

    Cen.z = (P1.z + P2.z + P3.z + P4.z +
        P5.z + P6.z + P7.z + P8.z +
        P9.z + P10.z + P11.z + P12.z +
        P13.z + P14.z + P15.z + P16.z) / 16;

    if (((abs(P1.x - Cen.x) >= 0.1 && abs(P1.y - Cen.y) >= 0.1 && abs(P1.z - Cen.z) >= 0.1) &&
        (abs(P2.x - Cen.x) >= 0.1 && abs(P2.y - Cen.y) >= 0.1 && abs(P2.z - Cen.z) >= 0.1) &&
        (abs(P3.x - Cen.x) >= 0.1 && abs(P3.y - Cen.y) >= 0.1 && abs(P3.z - Cen.z) >= 0.1) &&
        (abs(P4.x - Cen.x) >= 0.1 && abs(P4.y - Cen.y) >= 0.1 && abs(P4.z - Cen.z) >= 0.1) &&
        (abs(P5.x - Cen.x) >= 0.1 && abs(P5.y - Cen.y) >= 0.1 && abs(P5.z - Cen.z) >= 0.1) &&
        (abs(P6.x - Cen.x) >= 0.1 && abs(P6.y - Cen.y) >= 0.1 && abs(P6.z - Cen.z) >= 0.1) &&
        (abs(P7.x - Cen.x) >= 0.1 && abs(P7.y - Cen.y) >= 0.1 && abs(P7.z - Cen.z) >= 0.1) &&
        (abs(P8.x - Cen.x) >= 0.1 && abs(P8.y - Cen.y) >= 0.1 && abs(P8.z - Cen.z) >= 0.1) &&
        (abs(P9.x - Cen.x) >= 0.1 && abs(P9.y - Cen.y) >= 0.1 && abs(P9.z - Cen.z) >= 0.1) &&
        (abs(P10.x - Cen.x) >= 0.1 && abs(P10.y - Cen.y) >= 0.1 && abs(P10.z - Cen.z) >= 0.1) &&
        (abs(P11.x - Cen.x) >= 0.1 && abs(P11.y - Cen.y) >= 0.1 && abs(P11.z - Cen.z) >= 0.1) &&
        (abs(P12.x - Cen.x) >= 0.1 && abs(P12.y - Cen.y) >= 0.1 && abs(P12.z - Cen.z) >= 0.1) &&
        (abs(P13.x - Cen.x) >= 0.1 && abs(P13.y - Cen.y) >= 0.1 && abs(P13.z - Cen.z) >= 0.1) &&
        (abs(P14.x - Cen.x) >= 0.1 && abs(P14.y - Cen.y) >= 0.1 && abs(P14.z - Cen.z) >= 0.1) &&
        (abs(P15.x - Cen.x) >= 0.1 && abs(P15.y - Cen.y) >= 0.1 && abs(P15.z - Cen.z) >= 0.1) &&
        (abs(P16.x - Cen.x) >= 0.1 && abs(P16.y - Cen.y) >= 0.1 && abs(P16.z - Cen.z) >= 0.1)) 
        && e < 1 || e > 1) { // предотвращение сжатия в точку

        P1 = dotScale(e, Cen, P1);
        P2 = dotScale(e, Cen, P2);
        P3 = dotScale(e, Cen, P3);
        P4 = dotScale(e, Cen, P4);
        P5 = dotScale(e, Cen, P5);
        P6 = dotScale(e, Cen, P6);
        P7 = dotScale(e, Cen, P7);
        P8 = dotScale(e, Cen, P8);
        P9 = dotScale(e, Cen, P9);
        P10 = dotScale(e, Cen, P10);
        P11 = dotScale(e, Cen, P11);
        P12 = dotScale(e, Cen, P12);
        P13 = dotScale(e, Cen, P13);
        P14 = dotScale(e, Cen, P14);
        P15 = dotScale(e, Cen, P15);
        P16 = dotScale(e, Cen, P16);

    }

}


// закраска прямогольниками после проверки на видимость z-буффером
void Piramid::rectangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer) {
    // учёт координаты z при отрисовке в двумерном пространстве
    // точка пересечения смотрится не прямо вдоль оси z, а под углом 45, как видит пользователь
    t0.x -= 0.5 * t0.z; t0.y += 0.5 * t0.z;
    t1.x -= 0.5 * t1.z; t1.y += 0.5 * t1.z;
    t2.x -= 0.5 * t2.z; t2.y += 0.5 * t2.z;

    // сортировка точек по координате у
    if (t0.y == t1.y && t0.y == t2.y) return; // если все точки совпали по у, возврат
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y; // высота закрашиваемого треугольника

    for (int i = 0; i < total_height; i++) { // по всей высоте треугольника
        bool second_half = i > t1.y - t0.y || t1.y == t0.y; // true или false в зависимости от того 
        // больше ли i , чем расстояние между 1 и 0 точками или
        // они совпали
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y; // если i больше, чем расстояние между 1 и 0 точками, то
        // оно равно расстоянию между 2 и 1 точками, иначе
        // между 1 и 0 точками
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;

        Point A = t0 + Point(t2 - t0) * alpha;
        Point B = second_half ? t1 + Point(t2 - t1) * beta : t0 + Point(t1 - t0) * beta;

        if (A.x > B.x) std::swap(A, B); // сортировка точек по координате х

        for (int j = A.x; j <= B.x; j++) { // проход по строке с коорд х от а до б
            float phi = B.x == A.x ? 1.0 : (float)(j - A.x) / (float)(B.x - A.x);
            Point P = Point(A) + Point(B - A) * phi;
            int x = P.x;
            int y = P.y;
            if (x >= 0 && y >= 0) {
                if (zbuffer[x][y] < P.z) {
                    zbuffer[x][y] = P.z; // глубина ближайшего к экрану пикселя записывается в буфер
                    putpixel(P.x, P.y, colour); // colour+j даст крутой градиент к чёрному
                }
            }
        }
    }
}

// использование алгоритма z-буффера для отсечения невидимых поверхностей и закраски видимых
void Piramid::zBuff(Point P_1, Point P_2, Point P_3, Point P_4,
    Point P_5, Point P_6, Point P_7, Point P_8,
    Point P_9, Point P_10, Point P_11, Point P_12,
    Point P_13, Point P_14, Point P_15, Point P_16) {
    // создание z-буффера
    int** zbuffer;
    zbuffer = new int* [width];
    for (int i = 0; i < width; i++) {
        zbuffer[i] = new int[height]; // инициализация указателей
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            zbuffer[i][j] = minInt; // по всему экрану задаём ему минимальнейшее значение -- фон
    }

    rectangle(P1, P2, P3, BLUE, zbuffer);
    rectangle(P1, P4, P3, BLUE, zbuffer);

    rectangle(P1, P2, P6, GREEN, zbuffer);
    rectangle(P1, P5, P6, GREEN, zbuffer);

    rectangle(P2, P6, P7, CYAN, zbuffer);
    rectangle(P2, P3, P7, CYAN, zbuffer);
    
    rectangle(P3, P7, P8, GREEN, zbuffer);
    rectangle(P3, P4, P8, GREEN, zbuffer);

    rectangle(P1, P5, P8, RED, zbuffer);
    rectangle(P1, P4, P8, RED, zbuffer);

    rectangle(P5, P6, P7, MAGENTA, zbuffer);
    rectangle(P5, P8, P7, MAGENTA, zbuffer);

    
    rectangle(P9, P10, P11, LIGHTRED, zbuffer);
    rectangle(P9, P12, P11, LIGHTRED, zbuffer);

    rectangle(P9, P10, P14, LIGHTMAGENTA, zbuffer);
    rectangle(P9, P13, P14, LIGHTMAGENTA, zbuffer);

    rectangle(P10, P14, P15, YELLOW, zbuffer);
    rectangle(P10, P11, P15, YELLOW, zbuffer);

    rectangle(P11, P15, P16, LIGHTCYAN, zbuffer);
    rectangle(P11, P12, P16, LIGHTCYAN, zbuffer);

    rectangle(P9, P13, P16, LIGHTBLUE, zbuffer);
    rectangle(P9, P12, P16, LIGHTBLUE, zbuffer);

    rectangle(P13, P14, P15, GRAY, zbuffer);
    rectangle(P13, P16, P15, GRAY, zbuffer);

    // уничтожение
    for (int i = 0; i < width; i++) {
        delete[] zbuffer[i];
    }
    delete[] zbuffer;
}


// построение проекции точки на условный пол для тени
Point Piramid::shadowPoint(Point P) {
    Point L(600, 70, 100); // точка источника света

    int floor = 550; // условный пол
    Point S(0, 0, 0); // точка полученной проекции

    int k = (floor - P.y) / (L.y - P.y);
    S.x = (L.x - P.x) * k + P.x;
    S.y = floor;
    S.z = (L.z - P.z) * k + P.z;

    // учёт координаты z при отрисовке в двумерном пространстве
    // точка пересечения смотрится не прямо вдоль оси z, а под углом 45, как видит пользователь
    S.x -= 0.5 * S.z; S.y += 0.5 * S.z;

    return S;
}

// построение тени для треугольника
void Piramid::shadowTri(Point P1, Point P2, Point P3) {
    Point p1, p2, p3;
    int floor = 550; // условный пол
    // условие для отображения тени только ниже фигуры
    if (P1.y <= floor && P2.y <= floor && P3.y <= floor) {
        p1 = shadowPoint(P1);
        p2 = shadowPoint(P2);
        p3 = shadowPoint(P3);
        shadowTriColour(p1, p2, p3, GRAY);
    }
}

// построение теней для всех фигур
void Piramid::shadowAll(Point P_1, Point P_2, Point P_3, Point P_4,
    Point P_5, Point P_6, Point P_7, Point P_8,
    Point P_9, Point P_10, Point P_11, Point P_12,
    Point P_13, Point P_14, Point P_15, Point P_16) {
    Point L(600, 70, 100); // точка источника света
    int lightWidth = 4;
    for (int i = L.x- lightWidth; i <= L.x+ lightWidth; i++) {
        for (int j = L.y - lightWidth; j <= L.y + lightWidth; j++) {
            putpixel(i, j, WHITE);
        }
    }

    //Для первой фигуры
   /*
   * 1-2-3-4
   * 1-2-6-3
   * 2-6-7-3
   * 3-7-8-4
   * 1-5-8-4
   * 5-6-7-8
   */
   //Для второй фигуры
   /*
   * 9-10-11-12
   * 9-10-14-11
   * 10-14-15-11
   * 11-15-16-12
   * 9-13-16-12
   * 13-14-15-16
   */
    
    shadowTri(P1, P2, P3);
    shadowTri(P1, P4, P3);
    
    shadowTri(P1, P2, P6);
    shadowTri(P1, P5, P6);
    
    shadowTri(P2, P6, P7);
    shadowTri(P2, P3, P7);
    
    shadowTri(P3, P7, P8);
    shadowTri(P3, P4, P8);
    
    shadowTri(P1, P5, P8);
    shadowTri(P1, P4, P8);
    
    shadowTri(P5, P6, P7);
    shadowTri(P5, P8, P7);
    
    
    shadowTri(P9, P10, P11);
    shadowTri(P9, P12, P11);
    
    shadowTri(P9, P10, P14);
    shadowTri(P9, P13, P14);
    
    shadowTri(P10, P14, P15);
    shadowTri(P10, P11, P15);
    
    shadowTri(P11, P15, P16);
    shadowTri(P11, P12, P16);
    
    shadowTri(P9, P13, P16);
    shadowTri(P9, P12, P16);
    
    shadowTri(P13, P14, P15);
    shadowTri(P13, P16, P15);
}

// закраска тени треугольниками
void Piramid::shadowTriColour(Point t0, Point t1, Point t2, COLORREF colour) {
    // сортировка точек по координате у
    if (t0.y == t1.y && t0.y == t2.y) return; // если все точки совпали по у, возврат
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y; // высота закрашиваемого треугольника

    for (int i = 0; i < total_height; i++) { // по всей высоте треугольника
        bool second_half = i > t1.y - t0.y || t1.y == t0.y; // true или false в зависимости от того 
        // больше ли i , чем расстояние между 1 и 0 точками или
        // они совпали
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y; // если i больше, чем расстояние между 1 и 0 точками, то
        // оно равно расстоянию между 2 и 1 точками, иначе
        // между 1 и 0 точками
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;

        Point A = t0 + Point(t2 - t0) * alpha;
        Point B = second_half ? t1 + Point(t2 - t1) * beta : t0 + Point(t1 - t0) * beta;

        if (A.x > B.x) std::swap(A, B); // сортировка точек по координате х

        for (int j = A.x; j <= B.x; j++) { // проход по строке с коорд х от а до б
            float phi = B.x == A.x ? 1.0 : (float)(j - A.x) / (float)(B.x - A.x);
            Point P = Point(A) + Point(B - A) * phi;
            int x = P.x;
            int y = P.y;
            if (x >= 0 && y >= 0) {
                putpixel(P.x, P.y, colour);
            }
        }
    }
}
