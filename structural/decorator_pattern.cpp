#include <iostream>
#include <string>

using namespace std;

class Window {
public:
    virtual void draw() = 0;

    virtual string getDescription() =0;

    virtual ~Window() {}
};

class SimpleWindow : public Window {
public:
    void draw() {
        // draw window
    }

    string getDescription() {
        return "simple window\n";
    }

};

class WindowDecorator : public Window {
protected:
    Window *m_decorateWindow;

public:
    WindowDecorator(Window *decorateWindow) : m_decorateWindow(decorateWindow) {}
};

class VerticalScrollBarDecorator : public WindowDecorator {
public:
    VerticalScrollBarDecorator(Window *decorateWindow) : WindowDecorator(decorateWindow) {}

    void draw() {
        drawVerticalScrollBar();
        m_decorateWindow->draw();
    }

    string getDescription() {
        return m_decorateWindow->getDescription() + "with vertical scrollbar\n";
    }

private:
    void drawVerticalScrollBar() {
        // draw the vertical scrollbar
    }
};


class HorizontalScrollBarDecorator : public WindowDecorator {
public:
    HorizontalScrollBarDecorator(Window *decorateWindow) : WindowDecorator(decorateWindow) {}

    void draw() {
        drawHorizontalScrollBar();
        m_decorateWindow->draw();
    }

    string getDescription() {
        return m_decorateWindow->getDescription() + "with horizontal scrollbar\n";
    }

private:
    void drawHorizontalScrollBar() {
        // draw the horizontal scrollbar
    }
};


int main() {
    Window *simple = new SimpleWindow();
    cout << simple->getDescription() << "\n";


    Window *horiz = new HorizontalScrollBarDecorator(new SimpleWindow());
    cout << horiz->getDescription() << "\n";

    Window *vert = new VerticalScrollBarDecorator(new SimpleWindow());
    cout << vert->getDescription() << "\n";

    Window *decorareWindow = new HorizontalScrollBarDecorator(
            new VerticalScrollBarDecorator(new SimpleWindow()));

    cout << decorareWindow->getDescription();

    return 0;
}