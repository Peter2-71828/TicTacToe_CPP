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

class Board {

public:
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    void dispBoard() {
      for (int i=3; i<10; i+=3) {
        cout << this->board[i-3] << ' ';
        cout << this->board[i-2] << ' ';
        cout << this->board[i-1] << '\n';
      }
    }

    void updateBoard(int position, Player player){
      this->board[position] = player.name;
      dispBoard();
    }

};
