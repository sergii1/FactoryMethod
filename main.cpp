#include <iostream>
using namespace std;

//композиция - сам объект
//агрегация - указатель
//где странная стрелочка, там и содержиться указатель или объект

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

//class Creator{
// public:
//   Product* createObj(int id){
//     switch (id) {
//       case 1:{
//         return new ConcreteProduct1();
//       }
//       case 2:{
//         return new ConcreteProduct2();
//       }
//       default: {
//         return nullptr;
//       }
//     }
//   };
//};

class Room{
 public:
  virtual void setSize(){}
};

class SpecialRoom: public Room{
 public:
  void setSize() override{}
};

class Wall {
 public:
  virtual void setDoor(){}
};

class Maze{

 public:
   void draw(){}
   void addRoom(Room* r){}
   void addWall(Wall* r){}
};


class  MazeCreator{
 public:
  Room* createRoom(){
    return new Room();
  }
  Wall* createWall(){
    return new Wall();
  }

  virtual Maze* createMaze(){
    auto r1 = createRoom();
    r1->setSize();
    auto w1 = createWall();
    Maze* m  = new Maze();
    m->addRoom(r1);
    m->addWall(w1);
    return m;
  }

};

class  SpecialMazeCreator: Maze{
 public:
  Room* createRoom(){
    return new SpecialRoom();
  }
  Wall* createWall(){
    return new Wall();
  }

  virtual Maze* createMaze(){
    auto r1 = createRoom();
    r1->setSize();
    auto w1 = createWall();
    Maze* m  = new Maze();
    m->addRoom(r1);
    m->addWall(w1);
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
//  Creator creator;
//  Product* p1 = creator.createObj(1);
//  Product* p2 = creator.createObj(2);


  ConcreteCreator1 c1;
  ConcreteCreator2 c2;
  Product *p1 = c1.createObj();
  Product *p2 = c2.createObj();

  p1->print();
  p2->print();
  return 0;
}
