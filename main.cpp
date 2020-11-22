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

class Creator {
 public:
  virtual Product *createObj() = 0;
};

class ConcreteCreator1 : public Creator {
 public:
  Product *createObj() override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  Product *createObj() override {
    return new ConcreteProduct2();
  }
};

int main() {
  ConcreteCreator1 c1;
  ConcreteCreator2 c2;
  Product *p1 = c1.createObj();
  Product *p2 = c2.createObj();

  p1->print();
  p2->print();
  return 0;
}
