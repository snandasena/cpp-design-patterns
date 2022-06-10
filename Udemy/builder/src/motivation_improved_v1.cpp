//
// Created by sajith on 6/10/22.
//

#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

struct HtmlElement
{
    string name;
    string text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() = default;

    HtmlElement(const string &n, const string &t) : name{n}, text{t} {}

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
};

struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(const string &root_name)
    {
        root.name = root_name;
    }

    void add_element(const string &child_name, const string &child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
    }

    string str() const { return root.str(); }
};

int main()
{
    HtmlBuilder builder{"ul"};
    builder.add_element("li", "Hello");
    builder.add_element("li", "World!");

    cout << builder.str() << endl;
    return 0;
}