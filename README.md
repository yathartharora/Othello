# Othello
# This is a strategic game played between two users
Clone the project and run the C++ file (suitable for your OS) onto your machine.
Please remember the following points before playing the game -- User always goes first and Symbol of user is always 'O'
As you run the C++ file on your machine you will see a 8 by 8 matrix with the center 4 blocks of the matrix preoccupied by two 'X' and two 'O' i.e you will find the following matrix: 

. . . . . . . .
. . . . . . . .
. . . . . . . .
. . . O X . . .
. . . X O . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .

To win the game, you have to place your symbol in the matrix in a way that at the end of the game there are more 'O's than 'X'

RULES FOR FLIPPING X's to O's and vide versa

Place your symbol 'O' at a place in the matrix such that there are maximum X's captured between the 'O' your placing and a 'O' that already exists in the matrix.That is a string of the form " O.(any number of X's).O " should be formed.Remember there should not be any '.' between the two 'O's for flipping of X's.Moreover the flipping can take place in any direction , horizontally,verticaly,diagonally.For example-- Suppose you place 'O' at the poition * in the given matrix - 

. . . . . . . O
. . . . . . X .
. . . . . X . .
. . . . * X O .
. . . . X . . .
. . . . . . O .
. . . . O . . X
. . . . . . . .


The matrix will result into the following - 

. . . . . . . O
. . . . . . O .
. . . . . O . .
. . . . O O O .
. . . . X . . .
. . . . . . O .
. . . . O . . X
. . . . . . . .

Carefully observe the X's that have changed to O's and that have not changed to X's and maybe by now you may no the reason why!!?
Consider another example -
. . . . . . . .                   . . . . . . . .
. . . . . . . .                   . . . . . . . .
. . . . X O . .                   . . . . X O . .
. . . . * . . .                   . . . . O . . .
. . O X X . . .         ---->>>   . . O O O . . .
. . O . X . . .                   . . O . O . . .
. . . . O . . .                   . . . . O . . .
. . . . . . . .                   . . . . . . . .


Similarly the Computer will try to capture as many X's as possible.
The game ends when there is no one who can make a valid move to win the game.

I Hope the explanation is clear enough!!!
