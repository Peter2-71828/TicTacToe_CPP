#include <iostream>
using namespace std;

class Board {

  private:
    char board;

  public:
    void dispBoard() {
      char board[9] = {};
      cout << "  " << 1 << ' ' << 2 << ' '<< 3 << '\n';
      for (int i=3; i<10; i+=3) {
        cout << i/3 << ' ';
        cout << board[i-3] << ' ';
        cout << board[i-2] << ' ';
        cout << board[i-1] << '\n';
      }
    }
    Board() {
      dispBoard();
    }

};

int main() {
  Board newGame;
}
