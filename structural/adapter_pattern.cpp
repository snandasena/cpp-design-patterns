#include <iostream>

using namespace std;

class Rectangle {
public:
    virtual void draw() =0;
};


class LegacyRectangle {
public:
    LegacyRectangle(int x1, int y1, int x2, int y2) {
        x1_ = x1;
        x2_ = x2;
        y1_ = y1;
        y2_ = y2;
    }

    void oldDraw() {
        cout << "LegacyRectangle: oldDraw()\n";
    }

private:
    int x1_;
    int x2_;
    int y1_;
    int y2_;
};


class RectangleAdapter : public Rectangle, private LegacyRectangle {
public:
    RectangleAdapter(int x, int y, int w, int h) :
            LegacyRectangle(x, y, x + w, y + h) {
        cout << "RectangleAdapter(x, y, x + w, y + h)\n";
    }

    void draw() {
        cout << "RectangleAdapter: draw()\n";
        oldDraw();
    }
};


int main() {
    int x = 20, y = 50, w = 300, h = 200;
    Rectangle *r = new RectangleAdapter(x, y, w, h);
    r->draw();
    return 0;
}