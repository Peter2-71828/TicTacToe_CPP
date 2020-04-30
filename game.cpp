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

};

class TicTacToe: public Board {
// update access specifiers
  char playerX = 'X';
  char playerO = 'O';

public:
  TicTacToe(){
    cout << "Enter the number in the position you wish to play\n";
    dispBoard();
    while(is_gameOver()) {
      promptPlayer(playerX);
      promptPlayer(playerO);
    }
  }

  void promptPlayer( char player) {
    string move;
    cout << "Player" << player << "s Move:\n";
    cin >> move;
    is_valid(move.front(), player);
  }

  void is_valid(char move, char player) {
    int position = move - '1';
    if (board[position] == move) {
      updateBoard(position, player);
    }
    else {
      cout << "Invalid move try again";
      promptPlayer(player);
    }
  }

  bool is_gameOver() {
    // redundant checking should be eliminated
    char winner;
    for (int i=0; i<9; i+=4) {
      for (int n=1; n<5; n++) {
        if (i==0) {
            if (board[i]==board[i+n] && board[i]==board[i+(2*n)]) {
              winner = board[i];
              return false;
            }
        }else if (i!=4 && (n==2 || n==4)) {
          continue;
        }else if (i==4) {
          if (board[i]==board[i+n] && board[i]==board[i-n]) {
            winner = board[i];
            return false;
          }
        }else {
          if (board[i]==board[i-n] && board[i]==board[i-(2*n)]) {
            winner = board[i];
            return false;
          }
        }
      }
    }return true;
  }
};

int main() {
  TicTacToe();
}
