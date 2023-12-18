#pragma once
#include "Point.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


// ����� ������
class Piramid {
public:
    Point P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16;

    int col = MAINCOL;

    // ����������� �� 16 ����� ��� ���� ����� �����
    Piramid(Point P_1, Point P_2, Point P_3, Point P_4,
            Point P_5, Point P_6, Point P_7, Point P_8,
            Point P_9, Point P_10, Point P_11, Point P_12,
            Point P_13, Point P_14, Point P_15, Point P_16);

    // ���������
    void drawParaGram();

    // ����������
    void moveX(float amt);
    void moveY(float amt);
    void moveZ(float amt);

    // ������� ����� ����� ������ z
    Point rotDotZ(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ z
    void rotateZ(int u);

    // ������� ����� ����� ������ y
    Point rotDotY(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ y
    void rotateY(int u);

    // ������� ����� ����� ������ x
    Point rotDotX(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ x
    void rotateX(int u);

    // ��������������� ����� �����
    Point dotScale(float e, Point Cen, Point L);
    // ��������������� ���� ������
    void scale(float e);
     
    // ������� ���� � ����������� �������� ��������� �������
    const int width = 1400;
    const int height = 700;
    int minInt = -32767;

    // �������� �������������
    void rectangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer);

    // z-buffer
    void zBuff(Point P_1, Point P_2, Point P_3, Point P_4,
        Point P_5, Point P_6, Point P_7, Point P_8,
        Point P_9, Point P_10, Point P_11, Point P_12,
        Point P_13, Point P_14, Point P_15, Point P_16);

    // ���������� �������� ����� �� �������� ��� ��� ����
    Point shadowPoint(Point P);

    // ���������� ���� ��� ���������
    void shadowTri(Point P1, Point P2, Point P3);

    // ���������� ����� ��� ���� �����
    void shadowAll(Point P_1, Point P_2, Point P_3, Point P_4,
        Point P_5, Point P_6, Point P_7, Point P_8,
        Point P_9, Point P_10, Point P_11, Point P_12,
        Point P_13, Point P_14, Point P_15, Point P_16);

    // �������� ���� ���������
    void shadowTriColour(Point t0, Point t1, Point t2, COLORREF colour);
};

