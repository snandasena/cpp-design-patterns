#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton &getInstance();

private:
    Singleton() {
        cout << "Constructor\n";
    }

    ~Singleton() {
        cout << "Destructor\n";
    }

    Singleton(const Singleton &);

    const Singleton &operator=(const Singleton &);
};

Singleton &Singleton::getInstance() {
    static Singleton instance;
    return instance;
}

int main() {
    Singleton &s1 = Singleton::getInstance();
    cout << &s1;
    Singleton &s2 = Singleton::getInstance();
    cout << "\n" << &s2<<"\n";
    return 0;
}