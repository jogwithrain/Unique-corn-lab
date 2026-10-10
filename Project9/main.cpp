#include <iostream>
#include <vector>


using namespace std;


class unicorn {
private:
public:
    bool z = false;
    static vector<string> x;
    string* ptr = nullptr;
    unicorn(string a) { // constructor
        for (int i = 0;i < x.size();i++) {
            if (x.at(i) == a) {
                z = true;
            }
        }
        if (z) {
            cout << "ERROR!! The magic denies that name for a unicorn. They must be named something different." << endl;
            return;
        }
        else {
            ptr = new string(a);
            x.push_back(*ptr);
            //  cout << "allocated!" << endl;

        }
    }
    ~unicorn() { // Destructor 
        if (ptr != nullptr) {
            for (int i = 0;i < x.size();i++) {
                if (x.at(i) == *ptr) {
                    x.erase(x.begin() + i);
                }
            }
        }

        delete ptr;
        //  cout << "deallocated!" << endl;
    }
    string& operator*() {
        return *ptr;
    }
};


vector<string> unicorn::x;


int main() {
    unicorn s = unicorn("bella");
    cout << *s << endl;
    {
        unicorn b = unicorn("Ella");
        cout << *b << " " << *s << endl;
    } // Out of scope so it deallocates, name is able to be used again.
    unicorn y = unicorn("Ella");
    cout << *y << endl;
    unicorn c = unicorn("bella"); //fails to create
    unicorn r = unicorn("Rain");
    cout << *r << endl;




}



