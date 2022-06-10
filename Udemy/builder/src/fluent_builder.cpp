//
// Created by sajith on 6/10/22.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>


using namespace std;


struct HtmlBuilder;

class HtmlElement
{
    friend struct HtmlBuilder;
    string name;
    string text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() = default;

    HtmlElement(const string &n, const string &t) : name{n}, text{t} {}

public:

    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (!text.empty())
        {
            oss << string(indent_size * (indent + 1), ' ') << text << endl;
        }

        for (const auto &item: elements)
        {
            oss << item.str(indent + 1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

//    static HtmlBuilder build(string root_name)
//    {
//        return {root_name};
//    }

    static unique_ptr<HtmlBuilder> create(string root_name)
    {
        return make_unique<HtmlBuilder>(root_name);
    }
};

class HtmlBuilder
{
    HtmlElement root;

public:

    explicit HtmlBuilder(const string &root_name)
    {
        root.name = root_name;
    }

    HtmlBuilder &add_element(const string &child_name, const string &child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    string str() const { return root.str(); }

    HtmlElement build()
    {
        return root;
    }

    operator HtmlElement() const
    {
        return root;
    }
};

int main()
{
    HtmlBuilder builder{"ul"};
    builder.add_element("li", "Hello");
    builder.add_element("li", "World!");
    cout << builder.str() << endl;

    HtmlBuilder builder1{"ul"};
    builder1
            .add_element("li", "Hello")
            .add_element("li", "World");

    cout << builder1.str() << endl;

//    auto builder2 = HtmlElement::build("ul").add_element("li", "Hello").add_element("li", "World");
//    cout << builder2.str() << endl;
//
//    HtmlElement elem = HtmlElement::build("ul").add_element("li", "Hello");

    auto bilder = HtmlElement::create("ul")->
            add_element("li", "Hello")
            .add_element("li", "World")
            .build();
    cout << bilder.str() << endl;

//    HtmlElement

    return 0;
}