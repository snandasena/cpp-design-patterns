#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graphic {
public:
    virtual void draw() const = 0;

    virtual void remove(Graphic *g) {}

    virtual void add(Graphic *g) {}

    virtual void getChild(int) {}

    virtual ~Graphic() {}
};

class Line : public Graphic {
public:
    void draw() const {
        cout << "Line draw()\n";
    }
};

class Rectangle : public Graphic {
public:
    void draw() const {
        cout << "Rectangle draw()\n";
    }
};

class Text : public Graphic {
public:
    void draw() const {
        cout << "Text draw()\n";
    }
};

// composite

class Picture : public Graphic {

public:
    void draw() const {
        for_each(gList.begin(), gList.end(), mem_fun(&Graphic::draw));
    }

    void add(Graphic *aGraphic) {
        gList.emplace_back(aGraphic);
    }

private:
    vector<Graphic *> gList;
};

int main() {
    Line line;
    line.draw();

    Rectangle rectangle;
    rectangle.draw();

    Text text;
    text.draw();

    Picture picture;
    picture.add(&line);
    picture.add(&rectangle);
    picture.add(&text);
    picture.add(&rectangle);

    picture.draw();

    return 0;
}