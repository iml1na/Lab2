#include "pch.h"
#include <conio.h>
#include "stdio.h"
#include <iostream>

using namespace System;

class Point {
public:
    int x, y;
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
    ~Point() { //деструктор
        printf("%d, %d\n", x, y); 
        printf("~Point()\n");
    }
};

int main(array<System::String^>^ args)
{
    //статическое создание объектов
    {
        Point p; //создание с помощью конструктора по умолчанию
        Point p2(10, 20); //создание с помощью конструктора с параметрами
        Point p3(p2); //создание с помощью копирующего конструктора
    } //конец зоны видимости, объекты удалятся
    printf("\n");
    //динамическое создание объектов
    Point* p = new Point;
    Point* p2 = new Point(10, 20);
    Point* p3 = new Point(*p2);

    delete p;
    delete p2;
    delete p3;

    return 0;
}

