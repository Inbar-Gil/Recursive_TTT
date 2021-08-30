#include <iostream>
#include "Board.hpp"



int main()
{
	Board b = Board();
	b.playMove(X, 0);
	std::cout << b.updateScore() << std::endl;
	b.playMove(X, 1);
	std::cout << b.updateScore() << std::endl;
	b.playMove(X, 2);
	std::cout << b.updateScore() << std::endl;
	return 0;
}
