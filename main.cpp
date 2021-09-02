#include <iostream>
#include "Board.hpp"



int main()
{
	Board b = Board();
	b.printBoard();
	b.playMove(O, 0);
	b.playMove(O, 1);
	b.playMove(X, 2);
	b.playMove(X, 3);
	b.playMove(X, 4);
	b.playMove(O, 5);
	b.playMove(O, 6);
	b.playMove(X, 7);
	b.playMove(X, 8);
	return 0;


}
