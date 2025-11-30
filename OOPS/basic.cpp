#include<iostream>
using namespace std;

class Animal {
    // state or properties
    private:
    int weight;
    public:
    int age;
    string name;

    // constructor
    Animal(){
        this->weight=0;
        this->age=0;
        this->name="";
        cout<<"Construction called"<<endl;
    }

    // parameterised constructor
    Animal(int age){
        this->age=age;
        cout<<"Parameterised constructor"<<endl;
    }

    // copy constructor
    Animal(Animal &obj){
        this->age=obj.age;
        this->weight=obj.weight;
        this->name=obj.name;

        cout<<"I m inside copy constructor"<<endl;
    }

    ~Animal(){
        cout<<"I m inside destructor"<<endl;
    }

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

    void setWeight(int weight){
       this-> weight = weight;
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
    // Animal* mukesh = new Animal;
    // (*mukesh).age = 14;
    // (*mukesh).name = "Mukesh Kumar";

    // // alternate
    // mukesh->age = 15;
    // mukesh->name = "Mukesh Yadav";

    // mukesh->eat();
    // mukesh->sleep();

    // Animal a(10);  // for parameterised constructor

    // // object copy
    // Animal c = a;   // for copy constructor
    // Animal d(b);


    Animal a;
    a.age = 5;


    Animal* b = new Animal();
    b->age =12;

    // manually call 
    delete b;




    return 0;
}