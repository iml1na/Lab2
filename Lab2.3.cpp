#include "pch.h"
#include <conio.h>
#include "stdio.h"
#include <iostream>

using namespace System;

class Point {
protected:
    int x, y;
public:
    Point() { //конструктор по умолчанию
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y) { //конструктор с параметрами
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) { //копирующий конструктор
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point() {
        printf("%d, %d\n", x, y); //деструктор
        printf("~Point()\n");
    }
};

class ColoredPoint : public Point { //наследуется от класса Point
protected:
    int color;
public:
    ColoredPoint() : Point() { //конструктор по умолчанию
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y) { //конструктор с параметрами
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) { //копирующий конструктор
        printf("ColoredPoint(const Point &p)\n");
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {
        printf("%d, %d color = %d\n", x, y, color); //деструктор
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color) {
        color = new_color;
    }
};

int main(array<System::String^>^ args)
{
    setlocale(LC_ALL, "Russian");
    printf("\nОбъект помещается в переменную своего собственного класса:\n");
    ColoredPoint* p1 = new ColoredPoint(1, 2, 42); 
    delete p1;
    printf("\nОбъект помещается в переменную класса предка: \n");
    Point* p2 = new ColoredPoint(1, 2, 42); //в переменную базового класса можно поместить переменную класса потомка
    delete p2;

    return 0;
}