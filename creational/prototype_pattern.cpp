#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 4;

class Document {
public:
    virtual Document *clone() const =0;

    virtual void store() const =0;

    virtual ~Document() {}
};

class XMLDocument : public Document {
    Document *clone() const { return new XMLDocument; }

    void store() const {
        cout << "XML Doc\n";
    }
};

class PlainDocument : public Document {
    Document *clone() const { return new PlainDocument; }

    void store() const {
        cout << "Plain Doc\n";
    }
};

class SpreadSheetDocument : public Document {
public:
    Document *clone() const { return new SpreadSheetDocument; }

    void store() const {
        cout << "Spread sheet Doc\n";
    }
};

class DocumentManager {
public:
    static Document *makeDocument(int choice);

    ~DocumentManager() {}

private:
    static Document *mDocTypes[N];
};

Document *DocumentManager::mDocTypes[] = {
        0, new XMLDocument, new PlainDocument, new SpreadSheetDocument
};


Document *DocumentManager::makeDocument(int choice) {
    return mDocTypes[choice]->clone();

}

struct Destruct {
    void operator()(Document *a) const {
        delete a;
    }
};


int main() {
    vector<Document *> docs(N);
    int choice;
    cout << "quit(0), xml(1), plain(2), spreadsheet(3): \n";
    while (true) {
        cout << "Type in your choice (0-3)\n";
        cin >> choice;
        if (choice <= 0 || choice >= N)
            break;
        docs[choice] = DocumentManager::makeDocument(choice);
    }

    for (int i = 1; i < docs.size(); ++i) {
        if (docs[i]) {
            docs[i]->store();
        }
    }

    Destruct d;
    for_each(docs.begin(), docs.end(), d);

    return 0;
}