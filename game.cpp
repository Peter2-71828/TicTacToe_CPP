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

  protected:
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  public:

    void dispBoard() {
      for (int i=3; i<10; i+=3) {
        cout << this->board[i-3] << ' ';
        cout << this->board[i-2] << ' ';
        cout << this->board[i-1] << '\n';
      }
    }

};

class TicTacToe: public Board {

  public: 

  TicTacToe(){
    Player playerX('X');
    Player playerO('O');
    playerX.next = &playerO;
    playerO.next = &playerX;
    dispBoard();
    cout << "Enter the number in the position you wish to play\n";
    playerPrompt(&playerX);
  }

  void playerPrompt( Player* player) {
    char move;
    cout << "Player" << player->name << "s Move:\n";
    cin >> move;
    this->makeMove(move, *player);
  }

  void makeMove(char move, Player player){
    int position = move - '1';
    this->board[position] = player.name;
    dispBoard();
    playerPrompt(player.next);
  }

};

int main() {
  TicTacToe newGame;
}
