#include <iostream>
using namespace std;

class Board {

  private:
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  public:

    Board() {
      dispBoard();
    }

    void dispBoard() {
      for (int i=3; i<10; i+=3) {
        cout << this->board[i-3] << ' ';
        cout << this->board[i-2] << ' ';
        cout << this->board[i-1] << '\n';
      }
    }

    void playerPrompt() {
      char move;
      cout << "PlayerXs Move:\n";
      cin >> move;
      this->makeMove(move);
    }

    void makeMove(char move){
      int position = move - '1';
      this->board[position] = 'X';
      dispBoard();
      playerPrompt();
    }

};

int main() {
  Board newGame;
  cout << "Enter moves as an [x,y] coordinate array \n";
  newGame.playerPrompt();
}
