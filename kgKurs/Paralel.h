#pragma once
#include "Point.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


// класс фигуры
class Piramid {
public:
    Point P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16;

    int col = MAINCOL;

    // конструктор от 16 точек для двух фигур сразу
    Piramid(Point P_1, Point P_2, Point P_3, Point P_4,
            Point P_5, Point P_6, Point P_7, Point P_8,
            Point P_9, Point P_10, Point P_11, Point P_12,
            Point P_13, Point P_14, Point P_15, Point P_16);

    // отрисовка
    void drawParaGram();

    // пермещение
    void moveX(float amt);
    void moveY(float amt);
    void moveZ(float amt);

    // поворот одной точки вокруг z
    Point rotDotZ(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг z
    void rotateZ(int u);

    // поворот одной точки вокруг y
    Point rotDotY(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг y
    void rotateY(int u);

    // поворот одной точки вокруг x
    Point rotDotX(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг x
    void rotateX(int u);

    // масштабирование одной точки
    Point dotScale(float e, Point Cen, Point L);
    // масштабирование всей фигуры
    void scale(float e);
     
    // размеры окна и минимальное значения дальности пикселя
    const int width = 1400;
    const int height = 700;
    int minInt = -32767;

    // закраска прямогольника
    void rectangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer);

    // z-buffer
    void zBuff(Point P_1, Point P_2, Point P_3, Point P_4,
        Point P_5, Point P_6, Point P_7, Point P_8,
        Point P_9, Point P_10, Point P_11, Point P_12,
        Point P_13, Point P_14, Point P_15, Point P_16);

    // построение проекции точки на условный пол для тени
    Point shadowPoint(Point P);

    // построение тени для трайангла
    void shadowTri(Point P1, Point P2, Point P3);

    // построение теней для всех фигур
    void shadowAll(Point P_1, Point P_2, Point P_3, Point P_4,
        Point P_5, Point P_6, Point P_7, Point P_8,
        Point P_9, Point P_10, Point P_11, Point P_12,
        Point P_13, Point P_14, Point P_15, Point P_16);

    // закраска тени трайангла
    void shadowTriColour(Point t0, Point t1, Point t2, COLORREF colour);
};

