//
// Created by sajith on 6/10/22.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";

    cout << output << endl;

    string words[] = {"hello", "world"};
    ostringstream oss;

    oss << "<ul>\n";
    for (const auto &word: words)
    {
        oss << " <li> " << word << " </li>  \n";
    }
    oss << "</ul>";

    cout << oss.str() << endl;
    return 0;
}