#include <iostream>
using namespace std;

class Player {

public:
    char name;
    Player* next;

    Player(char XorO) {
      name = XorO;
    }

};
