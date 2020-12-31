#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<list>

using namespace std;

typedef string Elem;
struct Node {
    Elem elem;
    Node* par;
    Node* left;
    Node* right;
    Node() : elem(), par(nullptr), left(nullptr), right(nullptr) { }
};


class Position {
private:
    Node* v;
public:
    Position(Node* v = nullptr) : v(v) { }
    Position(string st) {
        v = new Node;
        v->elem = st;
    }
    Position left() const { return v->left; }
    Position right() const { return v->right; }
    Position parent() const { return v->par; }
    list<Position> children() {
        list<Position> pl;
        pl.push_back(v->left); pl.push_back(v->right);
        return pl;
    }
    bool isRoot() const { return v->par == nullptr; }
    bool isExternal() const { return v->left == nullptr && v->right == nullptr; }

    friend class Tree;
    friend ostream& operator<< (ostream& os, const Position& ps);
};
ostream& operator<< (ostream& os, const Position& ps) {
    os << ps.v->elem;
    return os;
}

typedef list<Position> PositionList;

class Tree {
private:
    Node* _root;
    int n;
public:
    Tree() : _root(nullptr), n(0) { }
    Tree(string st) : _root(), n(1) { }
    int size() const { return n; }
    bool empty() const { return size() == 0; }
    Node* root() const { return _root; }
    PositionList positions() const {
        PositionList pl;
        inorder(_root, pl);
        return pl;
    }
    PositionList EnclosedPositions() const {
        PositionList pl;
        EnclosedInorder(_root, pl);
        return pl;
    }
    string ops = "+-*/";
    void Inorder(const string& oper) {
        Node* Current = new Node;
        for (string::const_iterator iter = oper.cbegin(); iter != oper.cend(); ++iter) {
            if (n == 0) {
                _root = new Node;
                Current = _root;
                _root->elem = *iter;
                ++n;
            }
            else {
                if (ops.find(*iter) != string::npos) {
                    if (Position(Current).isExternal()) {
                        expandLeft(Current, *iter);
                        Current = Current->left;
                    }
                    else {
                        expandRight(Current, *iter);
                        Current = Current->right;
                    }
                }
                else {
                    if (Position(Current).isExternal()) expandLeft(Current, *iter);
                    else {
                        expandRight(Current, *iter);
                        while (Current->right != nullptr) {
                            if (Position(Current).isRoot()) break;
                            Current = Current->par;
                        }
                    }
                }
            }
        }
    }
    void Postorder(const string& oper) {
        Node* Current = new Node;
        for (string::const_iterator iter = oper.begin(); iter != oper.end(); ++iter) {
            if (n == 0) {
                _root = new Node;
                Current = _root;
                _root->elem = *iter;
                ++n;
            }
            else {
                if (ops.find(*iter) != string::npos) {
                    if (Position(Current).isExternal()) {
                        expandRight(Current, *iter);
                        Current = Current->right;
                    }
                    else {
                        expandLeft(Current, *iter);
                        Current = Current->left;
                    }
                }
                else {
                    if (Position(Current).isExternal()) expandRight(Current, *iter);
                    else {
                        expandLeft(Current, *iter);
                        while (Current->left != nullptr) {
                            if (Position(Current).isRoot()) break;
                            Current = Current->par;
                        }
                    }
                }
            }
        }
    }
    void expandLeft(Node* v, const char& c) {
        v->left = new Node;
        v->left->elem = c;
        v->left->par = v;
        n++;
    }
    void expandRight(Node* v, const char& c) {
        v->right = new Node;
        v->right->elem = c;
        v->right->par = v;
        n++;
    }
    void inorder(Node* v, PositionList& pl) const {
        if (!Position(v).isExternal()) inorder(v->left, pl);
        pl.push_back(v);
        if (!Position(v).isExternal()) inorder(v->right, pl);
    }
    void EnclosedInorder(Node* v, PositionList& pl) const {
        if (!Position(v).isExternal()) {
            pl.push_back(Position("("));
            EnclosedInorder(v->left, pl);
        }
        pl.push_back(v);
        if (!Position(v).isExternal()) {
            EnclosedInorder(v->right, pl);
            pl.push_back(Position(")"));
        }
    }
    double evalExpr(Node* v, map<string, string> m) {
        if (Position(v).isExternal()) {
            if (atof(v->elem.c_str()) == 0 && v->elem != "0") return atof(m[v->elem].c_str());
            else return atof(v->elem.c_str());
        }
        else {
            double x = evalExpr(v->left, m);
            double y = evalExpr(v->right, m);
            char oper = v->elem[0];

            switch (oper)
            {
            case '+':
                return x + y;
                break;
            case '-':
                return x - y;
                break;
            case '*':
                return x * y;
                break;
            case '/':
                return x / y;
                break;
            default:
                break;
            }
        }
    }
};

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("fix.in");
    outFile.open("fix.out");

    int n = 0;
    string st = "";
    string intst = "";
    string oper = "";
    map<string, string> m;

    inFile >> st;
    n = stoi(st);

    for (int i = 0; i < n; i++) {
        Tree tree;
        inFile >> st;
        if (st == "I") {
            oper = "";
            while (true) {
                inFile >> st;
                if (st == "E") break;
                oper += st;
            }
            tree.Inorder(oper);
            PositionList pl = tree.EnclosedPositions();
            for (PositionList::iterator iter = pl.begin(); iter != pl.end(); ++iter) {
                outFile << *iter;
            }
            outFile << endl;
            m.clear();
            while (true) {
                inFile >> st;
                if (st == "E") break;
                inFile >> intst;
                m.insert(make_pair(st, intst));
            }
            outFile << round(tree.evalExpr(tree.root(), m)) << endl;
        }
        else {
            oper = "";
            while (true) {
                inFile >> st;
                if (st == "E") break;
                oper += st;
            }
            reverse(oper.begin(), oper.end());
            tree.Postorder(oper);
            PositionList pl = tree.EnclosedPositions();
            for (PositionList::iterator iter = pl.begin(); iter != pl.end(); ++iter) {
                outFile << *iter;
            }
            outFile << endl;
            m.clear();
            while (true) {
                inFile >> st;
                if (st == "E") break;
                inFile >> intst;
                m.insert(make_pair(st, intst));
            }
            outFile << round(tree.evalExpr(tree.root(), m)) << endl;
        }
    }
    inFile.close();
    outFile.close();

    return 0;
}
