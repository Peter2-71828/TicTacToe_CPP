# Tic-Tac-Toe tech test

## How To Run
* clone this repo and enter navigate to the base directory
* run ```./game```
* 2 Players, PlayerX and PlayerY will be prompted to make moves
* Each move enter the number correlating to the position you wish to occupy and hit Enter
* If you enter a number longer than 1 character the first character will be taken as your input
* If player has one or if there are no spaces left to play the results of the game will be output

## Requirements

* Your goal is to write a program that lets two humans play Tic-Tac-Toe against each other.
* Implement a command line interface that lets the humans play the game by typing commands into the terminal.
* Players should be able to input their moves.
* The board should be shown after each move.
* The game should announce the result of the game when it's over.

### Rules of Tic-Tac-Toe

```
O X X
X X O
O X O
```

* There are two players in the game (X and O).
* The board is 9 positions in a 3x3 grid.
* Players take turns until the game is over.
* A player can claim a position if it is not already taken.
* A turn ends when a player claims a position.
* A player wins if they make a line by claiming 3 boxes in a row, 3 positions in a column, or 3 positions in a diagonal.
* If all positions are taken and neither player has a line, the game is a draw.
