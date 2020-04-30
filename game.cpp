#include <iostream>
using namespace std;

class Player {

public:
    char name;
    Player* next;

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

    void is_valid(char move, Player player) {
      int position = move - '1';
      if (board[position] == move) {
        updateBoard(position, player);
      }
    }

};

class TicTacToe: public Board {
// update access specifiers
  Player playerX;
  Player playerO;

public:
  TicTacToe(){
    startGame();
    dispBoard();
    promptPlayer(&playerX);
  }

  void startGame() {
    playerX.name = 'X';
    playerO.name = 'O';
    playerX.next = &playerO;
    playerO.next = &playerX;
    cout << "Enter the number in the position you wish to play\n";
  }

  void promptPlayer( Player* player) {
    char move;
    cout << "Player" << player->name << "s Move:\n";
    cin >> move;
  }

};

int main() {
  TicTacToe();
}
