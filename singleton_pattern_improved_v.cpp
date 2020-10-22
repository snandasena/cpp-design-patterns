#include <iostream>
#include <boost/thread/mutex.hpp>

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

// thread safe singleton
Singleton &Singleton::getInstance() {
    boost::mutex mtx;
    boost::mutex::scoped_lock lock(mtx);
    static Singleton instance;
    return instance;
}

int main() {
    Singleton &s1 = Singleton::getInstance();
    cout << &s1;
    Singleton &s2 = Singleton::getInstance();
    cout << "\n" << &s2 << "\n";
    return 0;
}