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
    void move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
    }
    void reset();
};
void Point::reset() { //реализация после объявления в классе
    x = 0;
    y = 0;
}

int main(array<System::String^>^ args)
{
    Point* p = new Point(1, 2);
    p->move(10, 10);
    delete p;

    Point* p1 = new Point(1, 2);
    p1->reset();
    delete p1;

    return 0;
}