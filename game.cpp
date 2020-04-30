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

};

// class Rules {
//
// protected:
//   bool is_valid()
//
// };

class GamePlay: protected Board {

protected:
  void playerPrompt( Player* player) {
    char move;
    cout << "Player" << player->name << "s Move:\n";
    cin >> move;
    this->updateBoard(move, *player);
  }

  void updateBoard(char move, Player player){
    int position = move - '1';
    this->board[position] = player.name;
    dispBoard();
    playerPrompt(player.next);
  }

};

class TicTacToe: private GamePlay {

public:
  TicTacToe(){
    Player playerX('X');
    Player playerO('O');
    playerX.next = &playerO;
    playerO.next = &playerX;
    play(playerX);
  }

  void play(Player playerX) {
    dispBoard();
    cout << "Enter the number in the position you wish to play\n";
    playerPrompt(&playerX);
  }

};

int main() {
  TicTacToe();
}
