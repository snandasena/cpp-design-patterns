#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton *getInstance();

private:
    Singleton() {}

    static Singleton *instance;
};

Singleton *Singleton::instance = 0;

Singleton *Singleton::getInstance() {
    if (!instance) {
        instance = new Singleton();
        cout << "getInstance(): First \n";
        return instance;
    } else {
        cout << "getInstance(): Previous\n";
    }
}

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    return 0;
}