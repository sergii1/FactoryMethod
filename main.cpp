#include <iostream>
using namespace std;

class Product {
 public:
  virtual void print() = 0;
};

class ConcreteProduct1 : public Product {
 public:
  void print() override {
    cout << "ConcreteProduct1" << endl;
  }
};

class ConcreteProduct2 : public Product {
 public:
  void print() override {
    cout << "ConcreteProduct2" << endl;
  }
};

class Creator{
 public:
   Product* createObj(int id){
     switch (id) {
       case 1:{
         return new ConcreteProduct1();
       }
       case 2:{
         return new ConcreteProduct2();
       }
       default: {
         return nullptr;
       }
     }
   };
};



int main() {
  Creator creator;
  Product* p1 = creator.createObj(1);
  Product* p2 = creator.createObj(2);
  p1->print();
  p2->print();
  return 0;
}
