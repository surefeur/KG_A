// Вар 1

#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Paralel.h"
#include "Colours.h"

using namespace std;

// размеры окна
const int width = 1400;
const int height = 700;

int main() {
    initwindow(width, height); // создаём консольное окно 1400 на 700

    char name_P1[3] = "1";
    char name_P2[3] = "2";
    char name_P3[3] = "3";
    char name_P4[3] = "4";
    char name_P5[3] = "5";
    char name_P6[3] = "6";
    char name_P7[3] = "7";
    char name_P8[3] = "8";
    
    Point P1(600, 300, 0, name_P1); 
    Point P2(600, 300, 50, name_P2);
    Point P3(700, 300, 50, name_P3);
    Point P4(700, 300, 0, name_P4);
    Point P5(800, 450, 0, name_P5);
    Point P6(800, 450, 50, name_P6);
    Point P7(900, 450, 50, name_P7);
    Point P8(900, 450, 0, name_P8);
    
    char name_P9[3] = "9";
    char name_P10[3] = "10";
    char name_P11[3] = "11";
    char name_P12[3] = "12";
    char name_P13[3] = "13";
    char name_P14[3] = "14";
    char name_P15[3] = "15";
    char name_P16[3] = "16";                             

    Point P9(550, 450, 0, name_P9);
    Point P10(550, 450, 100, name_P10);
    Point P11(650, 450, 100, name_P11);
    Point P12(650, 450, 0, name_P12);
    Point P13(750, 350, 0, name_P13);
    Point P14(750, 350, 100, name_P14);
    Point P15(850, 350, 100, name_P15);
    Point P16(850, 350, 0, name_P16);

    Piramid TriFour(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16); // создание пирамид

    // управление
    int i = 1; // условие выхода
    while (i) {
        switch (getch()) {
        case 'w':
        case 'W':
        case 'ц':
        case 'Ц':
            cout << 'w' << endl;
            TriFour.moveY(-10); // вверх
            break;
        case 'a':
        case 'A':
        case 'ф':
        case 'Ф':
            cout << 'a' << endl;
            TriFour.moveX(-10); // влево
            break;
        case 's':
        case 'S':
        case 'ы':
        case 'Ы':
            cout << 's' << endl;
            TriFour.moveY(10); // вниз
            break;
        case 'd':
        case 'D':
        case 'в':
        case 'В':
            cout << 'd' << endl;
            TriFour.moveX(10); // вправо
            break;
        case 'x':
        case 'X':
        case 'ч':
        case 'Ч':
            cout << 'x' << endl;
            TriFour.moveZ(-10); // назад
            TriFour.scale(0.9);
            break;
        case 'z':
        case 'Z':
        case 'я':
        case 'Я':
            cout << 'z' << endl;
            TriFour.moveZ(10); // вперёд
            TriFour.scale(1.1);
            break;
            // вокруг z
        case 'q':
        case 'Q':
        case 'й':
        case 'Й':
            cout << 'q' << endl;
            TriFour.rotateZ(1); // против часовой
            break;
        case 'e':
        case 'E':
        case 'у':
        case 'У':
            cout << 'e' << endl;
            TriFour.rotateZ(-1); // по часовой
            break;
            // вокруг y
        case 'r':
        case 'R':
        case 'к':
        case 'К':
            cout << 'r' << endl;
            TriFour.rotateY(1); // против часовой
            break;
        case 't':
        case 'T':
        case 'е':
        case 'Е':
            cout << 't' << endl;
            TriFour.rotateY(-1); // по часовой
            break;
            // вокруг x
        case 'f':
        case 'F':
        case 'а':
        case 'А':
            cout << 'f' << endl;
            TriFour.rotateX(1); // против часовой
            break;
        case 'g':
        case 'G':
        case 'п':
        case 'П':
            cout << 'g' << endl;
            TriFour.rotateX(-1); // по часовой
            break;

        case '=':
        case '+':
            cout << '+' << endl;
            TriFour.scale(1.5); // увеличение
            break;
        case '-':
        case '_':
            cout << '-' << endl;
            TriFour.scale(0.5); // уменьшение
            break;
        default:
            cout << "default -> exit" << endl;
            i = 0;
            break;
        }
        cleardevice(); // отичстка экрана
        TriFour.drawParaGram(); // перерисовка фигур
    }

    getch(); // чтение одного символа с клавиатуры
    closegraph(); // освобождает всю память, выделенную под графическую систему, затем восстанавливает экран в режим, который был до вызова initwindow

    return 0;
}
