#include <iostream>
using namespace std;

class Board {

  private:
    char board[9] = { };

  public:

    Board() {
      dispBoard();
    }

    void dispBoard() {
      cout << "  " << 1 << ' ' << 2 << ' '<< 3 << '\n';
      for (int i=3; i<10; i+=3) {
        cout << i/3 << ' ';
        cout << this->board[i-3] << ' ';
        cout << this->board[i-2] << ' ';
        cout << this->board[i-1] << '\n';
      }
    }

    void makemove(int move) {
      
    }

};

int main() {
  Board newGame;
  cout << "Enter moves as an [x,y] coordinate array \n";
  cout << "PlayerXs Move:\n";
  cin >> makemove(move);
}
