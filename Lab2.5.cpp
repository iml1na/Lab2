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
    void Print() {
        printf("x = %d, y = %d\n", x, y);
    }
};

class ColoredPoint : public Point //наследуется от Point
{
protected:
    int color;
public:
    void Print()
    {
        printf("color = %d\n", color);
    }
};
int main(array<System::String^>^ args)
{
    Point* p1 = new Point();
    p1->Print();
    ColoredPoint* p2 = new ColoredPoint(); //класс ColoredPoint наследуется от Point, значит конструктор тот же
    delete p1;
    delete p2;

    return 0;
}