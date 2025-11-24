#include<iostream>
using namespace std;

class Animal {
    // state or properties
    private:
    int weight;
    public:
    int age;
    string name;

    // behaviour
    void eat(){
        cout<<"eating "<<endl;
    }
    void sleep(){
        cout<<"sleeping "<<endl;
    }

    // getter setter for private access
    int getWeght(){
        return weight;
    }

    void setWeight(int w){
        weight = w;
    }
};


int main() {
    // cout<<"size of empty class is "<<sizeof(Animal)<<endl;

    // object creation

    // static
    // Animal ramesh;
    // ramesh.age = 12;
    // ramesh.name = "Ramesh Singh";
    // cout<< "Age is "<< ramesh.age<<endl;
    // cout<< "name is "<< ramesh.name<<endl;

    // // to private member 
    // ramesh.setWeight(34);
    // cout<<" weight is "<< ramesh.getWeght()<<endl;


    // dynamic memory 
    Animal* mukesh = new Animal;
    (*mukesh).age = 14;
    (*mukesh).name = "Mukesh Kumar";

    // alternate
    mukesh->age = 15;
    mukesh->name = "Mukesh Yadav";

    mukesh->eat();



    return 0;
}