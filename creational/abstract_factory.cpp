#include <iostream>

using namespace std;

class Button {
public:
    virtual void paint() =0;
};

class WinButton : public Button {
public:
    void paint() {
        cout << " Window Button \n";
    }
};

class MacButton : public Button {
public:
    void paint() {
        cout << " Mac Button \n";
    }
};

class ScrollBar {
public:
    virtual void paint() =0;
};

class WinScrollBar : public ScrollBar {
public:
    void paint() override {
        cout << " Window ScrollBar \n";
    }
};

class MacScrollBar : public ScrollBar {
public:
    void paint() override {
        cout << " Mac ScrollBar \n";
    }
};


class GUIFactory {
public:
    virtual Button *createButton() =0;

    virtual ScrollBar *createScrollBar() =0;
};


class WinFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new WinButton;
    }

    ScrollBar *createScrollBar() override {
        return new WinScrollBar;
    }
};


class MacFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new MacButton;
    }

    ScrollBar *createScrollBar() override {
        return new MacScrollBar;
    }
};


int main() {
    GUIFactory *guiFactory;
    Button *btn;
    ScrollBar *sb;

    guiFactory = new MacFactory;
    btn = guiFactory->createButton();
    btn->paint();

    sb = guiFactory->createScrollBar();
    sb->paint();

    guiFactory = new WinFactory;
    btn = guiFactory->createButton();
    btn->paint();

    sb = guiFactory->createScrollBar();
    sb->paint();

    return 0;
}