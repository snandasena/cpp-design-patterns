//
// Created by sajith on 6/10/22.
//


#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;


struct Tag
{
    string name;
    string text;
    vector<Tag> children;
    vector<pair<string, string >> attributes;

    friend ostream &operator<<(ostream &out, const Tag &tag)
    {
        out << "<" << tag.name;

        for (const auto &[first, second]: tag.attributes)
        {
            out << " " << first << "=\"" << second << "\"";
        }

        if (tag.children.empty() && tag.text.empty())
        {
            out << "/>" << endl;
        }
        else
        {
            out << ">" << endl;
            if (!tag.text.empty())
            {
                out << tag.text << endl;
            }

            for (const auto &child: tag.children)
            {
                out << child;
            }
            out << "</" << tag.name << ">" << endl;
        }
        return out;
    }

protected:

public:

    Tag(const string &n, const string &t) : name{n}, text{text} {}

    Tag(const string &n, const vector<Tag> &c) : name{n}, children(c) {}
};

struct P : Tag
{
    P(const string &text) : Tag{"p", text} {}

    P(initializer_list<Tag> children) : Tag{"p", children} {}
};

struct IMG : Tag
{
    explicit IMG(const string &url) : Tag{"img", ""}
    {
        attributes.emplace_back(make_pair("src", url));
    }
};

int main()
{
    cout <<
         P{
                 IMG{"http.example.com/image.png"}
         }
         << endl;

    return 0;
}

