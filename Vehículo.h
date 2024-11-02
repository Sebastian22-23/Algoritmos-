#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
using namespace System::Drawing;

// Clase base
class CVehiculo {
protected:
    float x, y, dx, dy;
    float width, height;
public:
    CVehiculo(float x, float y, float dx, float dy);
    virtual ~CVehiculo() {}
    virtual void mover(Graphics^ g);
    virtual void mover2(Graphics^ g);
    virtual void dibujar(Graphics^ g) = 0;
    //virtual void mostrar(Graphics^g);
    int getDx() const { return dx; }
    int getDy() const { return dy; }
    void setDx(int newDx) { dx = newDx; }
    void setDy(int newDy) { dy = newDy; }
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    void invertirDireccion();
};


CVehiculo::CVehiculo(float x, float y, float dx, float dy)
    : x(x), y(y), dx(dx), dy(dy), width(80), height(30) {}

void CVehiculo::mover(Graphics^ g) {
    //if (x + dx + this->width >= g->VisibleClipBounds.Width) dx = 0;

    if (x < 800) {
        x += dx;
    }
    else {
        dx = 0;
    }


    //if (y + dy + height >= g->VisibleClipBounds.Height || y + dy < 0) dy = -dy;
    //y += dy;
}

void CVehiculo::mover2(Graphics^ g) {

    if (x + dx + width + 15 >= g->VisibleClipBounds.Width || x + dx < 0) dx = -dx;
    x += dx;

    if (y + dy + height + 50 >= g->VisibleClipBounds.Height || y + dy - 30 < 0) dy = -dy;
    y += dy;
}

void CVehiculo::invertirDireccion() {
    dx = -dx;
    dy = -dy;
}

// Clase Carro1
class Carro1 : public CVehiculo {
public:
    Carro1(float x, float y, float dx, float dy) : CVehiculo(x, y, dx, dy) {}
    void dibujar(Graphics^ g) override {

        Brush^ brush = gcnew SolidBrush(Color::Black);
        g->FillRectangle(brush, x, y, width, height);
        Brush^ brush1 = gcnew SolidBrush(Color::Black);
        Brush^ brush2 = gcnew SolidBrush(Color::White);
        Pen^ pen2 = gcnew
            Pen(Color::White, 2.0);
        if (dx >= 0)
        {
            g->DrawRectangle(pen2, x, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x + 6, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 16, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 28, y, width - 73, height - 10);
            g->FillRectangle(brush2, x + 38, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 35, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 53, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 62, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 71, y, width - 71, height - 20);

            g->DrawRectangle(pen2, x, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x + 35, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y + 10, width - 44, height - 20);

            g->DrawRectangle(pen2, x, y + 20, width - 64, height - 20);
            g->DrawRectangle(pen2, x + 28, y + 20, width - 28, height - 20);

            g->FillRectangle(brush, x + 28, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 28, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 10, y - 30, width - 62, height - 20);
            g->DrawRectangle(pen2, x + 10, y - 30, width - 62, height - 20);
            g->FillRectangle(brush, x + 1, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 1, y - 30, width - 71, height - 20);


            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);


            // Dibujar polígonos
            //uso de IA  en cli
            Brush^ brush3 = gcnew SolidBrush(Color::Black);
            cli::array<Point>^ puntos1 = { Point(x + 5, y - 2), Point(x + 7, y - 30), Point(x + 2, y - 30), Point(x, y - 2), Point(x + 5, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 57, y - 25), Point(x + 55, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 64, y - 25), Point(x + 62, y - 30), Point(x + 56, y - 30), Point(x + 59, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 69, y - 12), Point(x + 65, y - 24), Point(x + 61, y - 22), Point(x + 65, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x + 74, y - 2), Point(x + 70, y - 11), Point(x + 66, y - 8), Point(x + 69, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }
        if (dx < 0)
        {
            g->DrawRectangle(pen2, x, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 9, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 18, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 27, y, width - 71, height - 20);
            //Aca va la manija
            g->FillRectangle(brush2, x + 39, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 36, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 45, y, width - 73, height - 10);
            g->DrawRectangle(pen2, x + 52, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 64, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 74, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x, y + 10, width - 44, height - 20);
            g->DrawRectangle(pen2, x + 36, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 52, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x, y + 20, width - 28, height - 20);
            g->DrawRectangle(pen2, x + 64, y + 20, width - 64, height - 20);

            g->FillRectangle(brush, x + 45, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 45, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 52, y - 30, width - 65, height - 20);
            g->DrawRectangle(pen2, x + 52, y - 30, width - 65, height - 20);
            g->FillRectangle(brush, x + 67, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 67, y - 30, width - 71, height - 20);

            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);

            Brush^ brush3 = gcnew SolidBrush(Color::Black);
            cli::array<Point>^ puntos1 = { Point(x + 75 , y - 2), Point(x + 72, y - 30), Point(x + 77, y - 30), Point(x + 80, y - 2), Point(x + 75, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 16, y - 25), Point(x + 20, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 8, y - 25), Point(x + 12, y - 30), Point(x + 18, y - 30), Point(x + 13, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 2, y - 12), Point(x + 7, y - 24), Point(x + 12, y - 22), Point(x + 7, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x, y - 2), Point(x + 2, y - 11), Point(x + 7, y - 8), Point(x + 5, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }




    }
};

// Clase Carro2
class Carro2 : public CVehiculo {
public:
    Carro2(float x, float y, float dx, float dy) : CVehiculo(x, y, dx, dy) {}
    void dibujar(Graphics^ g) override {
        Brush^ brush = gcnew SolidBrush(Color::Blue);
        g->FillRectangle(brush, x, y, width, height);
        Brush^ brush1 = gcnew SolidBrush(Color::Blue);
        Brush^ brush2 = gcnew SolidBrush(Color::White);
        Pen^ pen2 = gcnew
            Pen(Color::White, 2.0);
        if (dx >= 0)
        {
            g->DrawRectangle(pen2, x, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x + 6, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 16, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 28, y, width - 73, height - 10);
            g->FillRectangle(brush2, x + 38, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 35, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 53, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 62, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 71, y, width - 71, height - 20);

            g->DrawRectangle(pen2, x, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x + 35, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y + 10, width - 44, height - 20);

            g->DrawRectangle(pen2, x, y + 20, width - 64, height - 20);
            g->DrawRectangle(pen2, x + 28, y + 20, width - 28, height - 20);

            g->FillRectangle(brush, x + 28, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 28, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 10, y - 30, width - 62, height - 20);
            g->DrawRectangle(pen2, x + 10, y - 30, width - 62, height - 20);
            g->FillRectangle(brush, x + 1, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 1, y - 30, width - 71, height - 20);


            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);


            // Dibujar polígonos
            Brush^ brush3 = gcnew SolidBrush(Color::Blue);
            cli::array<Point>^ puntos1 = { Point(x + 5, y - 2), Point(x + 7, y - 30), Point(x + 2, y - 30), Point(x, y - 2), Point(x + 5, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 57, y - 25), Point(x + 55, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 64, y - 25), Point(x + 62, y - 30), Point(x + 56, y - 30), Point(x + 59, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 69, y - 12), Point(x + 65, y - 24), Point(x + 61, y - 22), Point(x + 65, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x + 74, y - 2), Point(x + 70, y - 11), Point(x + 66, y - 8), Point(x + 69, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }
        if (dx < 0)
        {
            g->DrawRectangle(pen2, x, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 9, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 18, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 27, y, width - 71, height - 20);
            //Aca va la manija
            g->FillRectangle(brush2, x + 39, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 36, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 45, y, width - 73, height - 10);
            g->DrawRectangle(pen2, x + 52, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 64, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 74, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x, y + 10, width - 44, height - 20);
            g->DrawRectangle(pen2, x + 36, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 52, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x, y + 20, width - 28, height - 20);
            g->DrawRectangle(pen2, x + 64, y + 20, width - 64, height - 20);

            g->FillRectangle(brush, x + 45, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 45, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 52, y - 30, width - 65, height - 20);
            g->DrawRectangle(pen2, x + 52, y - 30, width - 65, height - 20);
            g->FillRectangle(brush, x + 67, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 67, y - 30, width - 71, height - 20);

            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);

            Brush^ brush3 = gcnew SolidBrush(Color::Blue);
            cli::array<Point>^ puntos1 = { Point(x + 75 , y - 2), Point(x + 72, y - 30), Point(x + 77, y - 30), Point(x + 80, y - 2), Point(x + 75, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 16, y - 25), Point(x + 20, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 8, y - 25), Point(x + 12, y - 30), Point(x + 18, y - 30), Point(x + 13, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 2, y - 12), Point(x + 7, y - 24), Point(x + 12, y - 22), Point(x + 7, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x, y - 2), Point(x + 2, y - 11), Point(x + 7, y - 8), Point(x + 5, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }
    }
};

// Clase Carro3
class Carro3 : public CVehiculo {
public:
    Carro3(float x, float y, float dx, float dy) : CVehiculo(x, y, dx, dy) {}
    void dibujar(Graphics^ g) override {
        Color randomColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256);
        Brush^ brush = gcnew SolidBrush(randomColor);
        g->FillRectangle(brush, x, y, width, height);
        Brush^ brush1 = gcnew SolidBrush(randomColor);
        Brush^ brush2 = gcnew SolidBrush(Color::White);
        Pen^ pen2 = gcnew
            Pen(Color::White, 2.0);

        //Rompecabezas
        if (dx >= 0)
        {
            g->DrawRectangle(pen2, x, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x + 6, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 16, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 28, y, width - 73, height - 10);
            g->FillRectangle(brush2, x + 38, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 35, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 53, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 62, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 71, y, width - 71, height - 20);

            g->DrawRectangle(pen2, x, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x + 35, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 44, y + 10, width - 44, height - 20);

            g->DrawRectangle(pen2, x, y + 20, width - 64, height - 20);
            g->DrawRectangle(pen2, x + 28, y + 20, width - 28, height - 20);

            g->FillRectangle(brush, x + 28, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 28, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 10, y - 30, width - 62, height - 20);
            g->DrawRectangle(pen2, x + 10, y - 30, width - 62, height - 20);
            g->FillRectangle(brush, x + 1, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 1, y - 30, width - 71, height - 20);


            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);


            // Dibujar polígonos
            Brush^ brush3 = gcnew SolidBrush(randomColor);
            cli::array<Point>^ puntos1 = { Point(x + 5, y - 2), Point(x + 7, y - 30), Point(x + 2, y - 30), Point(x, y - 2), Point(x + 5, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 57, y - 25), Point(x + 55, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 64, y - 25), Point(x + 62, y - 30), Point(x + 56, y - 30), Point(x + 59, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 69, y - 12), Point(x + 65, y - 24), Point(x + 61, y - 22), Point(x + 65, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x + 74, y - 2), Point(x + 70, y - 11), Point(x + 66, y - 8), Point(x + 69, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }
        if (dx < 0)
        {
            g->DrawRectangle(pen2, x, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 9, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 18, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 27, y, width - 71, height - 20);
            //Aca va la manija
            g->FillRectangle(brush2, x + 39, y + 3, width - 77, height - 27);
            g->DrawRectangle(pen2, x + 36, y, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 45, y, width - 73, height - 10);
            g->DrawRectangle(pen2, x + 52, y, width - 68, height - 20);
            g->DrawRectangle(pen2, x + 64, y, width - 70, height - 20);
            g->DrawRectangle(pen2, x + 74, y, width - 74, height - 20);
            g->DrawRectangle(pen2, x, y + 10, width - 44, height - 20);
            g->DrawRectangle(pen2, x + 36, y + 10, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 52, y + 10, width - 52, height - 10);
            g->DrawRectangle(pen2, x, y + 20, width - 28, height - 20);
            g->DrawRectangle(pen2, x + 64, y + 20, width - 64, height - 20);

            g->FillRectangle(brush, x + 45, y - 30, width - 73, height);
            g->DrawRectangle(pen2, x + 45, y - 30, width - 73, height);
            g->FillRectangle(brush, x + 52, y - 30, width - 65, height - 20);
            g->DrawRectangle(pen2, x + 52, y - 30, width - 65, height - 20);
            g->FillRectangle(brush, x + 67, y - 30, width - 71, height - 20);
            g->DrawRectangle(pen2, x + 67, y - 30, width - 71, height - 20);

            //g->FillEllipse(brush2, x + 22.5, y + 23, width - 85, height - 10);
            g->FillEllipse(brush1, x + 25, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 25, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush1, x + 70, y + 25, width - 100, height - 13.5);
            g->DrawEllipse(pen2, x + 70, y + 25, width - 100, height - 13.5);

            g->FillEllipse(brush2, x + 56, y + 29, width - 72, height - 23);
            g->FillEllipse(brush2, x + 11, y + 29, width - 72, height - 23);

            Brush^ brush3 = gcnew SolidBrush(randomColor);
            cli::array<Point>^ puntos1 = { Point(x + 75 , y - 2), Point(x + 72, y - 30), Point(x + 77, y - 30), Point(x + 80, y - 2), Point(x + 75, y - 2) };
            cli::array<Point>^ puntos2 = { Point(x + 16, y - 25), Point(x + 20, y - 30), Point(x + 35, y - 30), Point(x + 35, y - 25) };
            cli::array<Point>^ puntos3 = { Point(x + 8, y - 25), Point(x + 12, y - 30), Point(x + 18, y - 30), Point(x + 13, y - 23) };
            cli::array<Point>^ puntos4 = { Point(x + 2, y - 12), Point(x + 7, y - 24), Point(x + 12, y - 22), Point(x + 7, y - 10) };
            cli::array<Point>^ puntos5 = { Point(x, y - 2), Point(x + 2, y - 11), Point(x + 7, y - 8), Point(x + 5, y - 2) };

            g->FillPolygon(brush3, puntos1);
            g->FillPolygon(brush3, puntos2);
            g->FillPolygon(brush3, puntos3);
            g->FillPolygon(brush3, puntos4);
            g->FillPolygon(brush3, puntos5);
        }
    }
};