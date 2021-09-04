#include <iostream>
#include "Board.hpp"
#include "RecursiveBoard.hpp"




int main()
{
	RecursiveBoard rB = RecursiveBoard(2);
	rB.printBoards();
	int * moves = new int[2]();
	rB.isMoveLegal(moves);
//	rB.playMove(X, moves);
//	moves[1] = 4;
//	rB.playMove(X, moves);
//	moves[1] = 8;
//	rB.playMove(X, moves);
//	moves[0] = 2;
//	rB.playMove(X, moves);
//	moves[1] = 4;
//	rB.playMove(X, moves);
//	moves[1] = 0;
//	rB.playMove(X, moves);
//	moves[0] = 1;
//	rB.playMove(X, moves);
//	moves[1] = 4;
//	rB.playMove(X, moves);
//	moves[1] = 8;
//	rB.playMove(X, moves);
	rB.printBoards();
	delete[] moves;
	return 0;
}
