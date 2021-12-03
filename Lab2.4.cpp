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

class Section { 
protected:
    Point* p1;
    Point* p2;
public:
    Section() { //конструктор по умолчанию
        printf("Section()\n");
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) { //конструктор с параметрами (координаты двух точек)
        printf("Section(int x1, int y1, int x2, int y2)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Section(const Section& s) { //копирующий конструктор
        printf("Section(const Section &s)\n");
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Section() { //деструктор
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};

int main(array<System::String^>^ args)
{
    Section* s1 = new Section;
    Section* s2 = new Section(*s1);

    delete s1;
    delete s2;
    return 0;
}

