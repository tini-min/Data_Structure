#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Heap {
private :
    vector<int> v;
    int n;
public :
    Heap(int n = 0) : n(n)  { v.push_back(0); }
    void insert(int e) {
        v.push_back(e); n++;
        int ind = n;
        while (ind != 1) {
            if (v.at(ind / 2) > v.at(ind)) {
                int temp = v.at(ind / 2);
                v.at(ind / 2) = v.at(ind);
                v.at(ind) = temp;
                ind /= 2;
            }
            else break;
        }
    }
    int removeMin() {
        int Min = min()
        v.at(1) = v.at(n); n--; v.pop_back();
        int ind = 1;
        bool flag;
        while (ind < n) {
            flag = false;
            if (ind * 2 + 1 <= n) {
                if ((v.at(ind) > v.at(ind * 2 + 1)) & (v.at(ind * 2) > v.at(ind * 2 + 1))) {
                    int temp = v.at(ind * 2 + 1);
                    v.at(ind * 2 + 1) = v.at(ind);
                    v.at(ind) = temp;
                    ind = ind * 2 + 1;
                    continue;
                }
                else flag = true;
            }
            if (ind * 2 <= n) {
                if (v.at(ind) > v.at(ind * 2)) {
                    int temp = v.at(ind * 2);
                    v.at(ind * 2) = v.at(ind);
                    v.at(ind) = temp;
                    ind *= 2;
                    continue;
                }
                else flag = true;
            }
            if (flag) break;
            ind *= 2;
        }
        return Min;
    }
    int min() {
        if (empty()) return v.at(1);
    }
    int size() { return n; }
    bool empty() { return n == 0; }
};

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("lists.in");
    outFile.open("list.out");
    Heap h;
    string st;
    string e = "";

    while (!inFile.eof()) {
        getline(inFile, st);
        if (st != "") {
            for (auto i : st) {
                if (i == ' ') {
                    h.insert(atoi(e.c_str()));
                    e = "";
                }
                else e += i;
            }
            h.insert(atoi(e.c_str()));
            e = "";
        }
    }
    while (!h.empty()) {
        outFile << h.removeMin() << " ";
    }

    inFile.close();
    outFile.close();

    return 0;
}
