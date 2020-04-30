#include <iostream>
using namespace std;

class Board {

protected:
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

class TicTacToe: private Board {
public:
  TicTacToe(){
    cout << "Enter the number in the position you wish to play\n";
    dispBoard();
    while(is_gameOver()) {
      promptPlayer(playerX);
      if (is_gameOver()!=true) {
        break;
      }
      promptPlayer(playerO);
    }
    if (winner.length() > 1) {
      cout << "It was a Draw!";
    }else {
      cout << winner << " won!";
    }
  }
private:
  char playerX = 'X';
  char playerO = 'O';
  int turnCount = 0;
  string winner = "DRAW";

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
    turnCount ++;
    for (int i=0; i<9; i+=4) {
      for (int n=1; n<5; n++) {
        if (i!=4 && (n==2 || n==4)) {
          continue;
        }else if (i==0) {
          if (board[i]==board[i+n] && board[i]==board[i+(2*n)]) {
            winner = board[i];
            return false;
          }
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
    }if (turnCount > 9) {
      return false;
    }else {
      return true;
    }
  }
};

int main() {
  TicTacToe();
}
