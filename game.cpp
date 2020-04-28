#include <iostream>
using namespace std;

class Player {

public:
    char name;
    Player* next;

    Player(char name) {
      name = name;
    }
};

class Board {

  private:
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  public:

    Board() {
      Player playerX('X');
      Player playerO('Y');
      playerX.next = &playerO;
      playerO.next = &playerX;
      dispBoard();
      cout << "Enter the number in the position you wish to play\n";
      playerPrompt(&playerX);
    }

    void dispBoard() {
      for (int i=3; i<10; i+=3) {
        cout << this->board[i-3] << ' ';
        cout << this->board[i-2] << ' ';
        cout << this->board[i-1] << '\n';
      }
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
  Board newGame;
}
