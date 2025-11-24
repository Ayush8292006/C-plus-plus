#include<iostream>
using namespace std;

class abc{
public:
    static int x, y;

    void print() const {
        cout << x << " " << y << endl;
    }
};

// yahan memory allocate hoti hai static variables ki
int abc::x = 0;
int abc::y = 0;

int main(){

    abc obj1;
    obj1.x = 1;
    obj1.y = 1;
    obj1.print();

    abc obj2;
    obj2.x = 5;
    obj2.y = 10;
    obj2.print();

    obj1.print();
    obj2.print();

    return 0;
}
