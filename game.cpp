#include <iostream>
using namespace std;

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

    void updateBoard(int position, char player){
      this->board[position] = player;
      dispBoard();
    }

    void is_valid(char move, char player) {
      int position = move - '1';
      if (board[position] == move) {
        updateBoard(position, player);
      }
    }

};

class TicTacToe: public Board {
// update access specifiers
  char playerX = 'X';
  char playerO = 'O';

public:
  TicTacToe(){
    cout << "Enter the number in the position you wish to play\n";
    dispBoard();
    while(true) {
      promptPlayer(playerX);
      promptPlayer(playerO);
    }
  }

  void promptPlayer( char player) {
    char move;
    cout << "Player" << player << "s Move:\n";
    cin >> move;
    is_valid(move, player);
  }

};

int main() {
  TicTacToe();
}
