#include <iostream>

using namespace std;

// Implementor
class DrawingImplementor {

public:
    virtual void drawSquare(double) =0;

    virtual  ~DrawingImplementor() {};
};

// concrete implementor

class DrawingImlementorA : public DrawingImplementor {
public:
    DrawingImlementorA() {

    }

    virtual ~DrawingImlementorA() {

    }

    void drawSquare(double side) {
        cout << "\nImplementorA.square with side = " << side << "\n";

    }
};

// concrete implementor
class DrawingImlementorB : public DrawingImplementor {
public:
    DrawingImlementorB() {

    }

    virtual ~DrawingImlementorB() {}

    void drawSquare(double side) {
        cout << "\nImplementorB.square with side = " << side << "\n";
    }
};

// abstraction
class Shape {
public:
    virtual void draw() =0;

    virtual void resize(double pct) =0;

    virtual ~Shape() {

    }
};


class Square : public Shape {
public:
    Square(double s, DrawingImplementor &implementor) : side(s), drawingImplementor(implementor) {
    }

    virtual  ~Square() {

    }

    // low level i.e Implementation specific
    void draw() {
        drawingImplementor.drawSquare(side);
    }

    // high level i.e abstraction specifc
    void resize(double pct) {
        side *= pct;
    }


private:
    double side;
    DrawingImplementor &drawingImplementor;
};


int main() {

    DrawingImlementorA imlementorA;
    DrawingImlementorB imlementorB;

    Square squareA(1.0, imlementorA);
    Square squareB(2.0, imlementorB);

    Shape *shapes[2];
    shapes[0] = &squareA;
    shapes[1] = &squareB;

    shapes[0]->resize(10.0);
    shapes[0]->draw();

    shapes[1]->resize(10);
    shapes[1]->draw();

    return 0;
}