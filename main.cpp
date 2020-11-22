#include <iostream>
using namespace std;

class Wall {
 public:
  //допустим тут вся стена будет одним цветом
  virtual void setColor(string color) {
    cout << "I am ordinary " << color << " wall" << endl;
  }
};

class SpecialWall : public Wall {
 public:
  //а тут стена с градиентной заливкой
  void setColor(string color) override {
    cout << "I am gradient " << color << " wall" << endl;
  }
};

class Room {
 public:
  virtual void addSide(Wall *wall) {
    cout << "I am ordinary room" << endl;
  }
};

class SpecialRoom : public Room {
 public:
  void addSide(Wall *wall) override {
    cout << "I am special room" << endl;
  }
};

class Maze {
 public:
  void addRoom(Room *r) {}
};

class MazeGame {
 public:

  //фабричный метод
  virtual Room *createRoom() {
    return new Room();
  }
  //фабричный метод
  virtual Wall *createWall() {
    return new Wall();
  }

  virtual Maze *createMaze() {
    Room *r1 = createRoom();
    Wall *w1 = createWall();
    w1->setColor("black");
    r1->addSide(w1);
    Maze *m = new Maze();
    m->addRoom(r1);
    return m;
  }

};

class SpecialMazeGame : public MazeGame {
 public:
  //фабричный метод
  Room *createRoom() override {
    return new SpecialRoom();
  }
  //фабричный метод
  Wall *createWall() override {
    return new SpecialWall();
  }

  Maze *createMaze() override {
    Room *r1 = createRoom();
    Wall *w1 = createWall();
    w1->setColor("black");
    r1->addSide(w1);
    Maze *m = new Maze();
    m->addRoom(r1);
    return m;
  }

};

int main() {
  cout << "ordinary maze game" << endl;
  MazeGame m;
  m.createMaze();

  cout << "special maze game" << endl;
  SpecialMazeGame m1;
  m1.createMaze();

  return 0;
}
