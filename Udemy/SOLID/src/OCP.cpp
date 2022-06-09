//
// Created by sajith on 6/9/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>


using namespace std;
using namespace boost;

enum class Color
{
    red, green, blue
};
enum class Size
{
    small, medium, large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

template<typename T>
struct AndSpecification;

template<typename T>
struct Specification
{
    virtual bool is_satisfied(T *item) = 0;

    AndSpecification<T> operator&&(Specification<T> &&other)
    {
        return AndSpecification<T>(*this, other);
    }

   virtual ~Specification() = default;
};

template<typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> &items, Specification<T> &spec) = 0;

   virtual ~Filter() = default;
};


struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> &items, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (const auto &item: items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    explicit ColorSpecification(Color col) : color{col} {}

    bool is_satisfied(Product *item) override
    {
        return item->color == color;
    }
    
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size sz) : size{sz} {}

    bool is_satisfied(Product *item) override
    {
        return item->size == size;
    }
};

template<typename T>
struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &f, Specification<T> &s) : first{f}, second{s} {}

    bool is_satisfied(T *item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

void caller()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};
    BetterFilter bf;
    ColorSpecification green{Color::green};

    for (auto &item: bf.filter(items, green))
    {
        cout << item->name << " is green\n";
    }

    SizeSpecification large{Size::large};
    AndSpecification<Product> green_and_large{green, large};

    for (auto &item: bf.filter(items, green_and_large))
    {
        cout << item->name << " is green and large\n";
    }

    auto spec = ColorSpecification(Color::green) && SizeSpecification(Size::large);

    for (auto &item: bf.filter(items, spec))
    {
        cout << item->name << " is green and large\n";
    }
}

int main()
{
    caller();
    return 0;
}