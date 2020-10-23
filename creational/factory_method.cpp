#include <iostream>
#include <cstring>

using namespace std;

class Button {
public:
    virtual void paint() =0;
};

class OSXButton : public Button {
public:
    void paint() override {
        cout << "OSX Button \n";
    }
};

class WinButton : public Button {
public:
    void paint() override {
        cout << "Win Button \n";
    }
};

class GUIFactory {
public:
    virtual Button *createButton(char *) =0;
};

class Factory : public GUIFactory {
public:
    Button *createButton(char *type) override {
        if (strcmp(type, "Windows") == 0) {
            return new WinButton;
        } else if (strcmp(type, "OSX") == 0) {
            return new OSXButton;
        }
    }
};

int main() {

    GUIFactory *guiFactory;
    Button *btn;

    guiFactory = new Factory;
    btn = guiFactory->createButton("OSX");
    btn -> paint();

    btn = guiFactory-> createButton("Windows");
    btn->paint();

    return 0;
}