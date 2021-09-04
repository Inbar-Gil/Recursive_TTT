#include <iostream>
#include "Board.hpp"
#include "RecursiveBoard.hpp"
#include "RecursiveTTT.hpp"

using namespace std;

int main()
{
	int recDepth = 11;
	while (true)
	{
		cout << "Enter Recursive Depth (number between 1 and 10)" << endl;
		cin >> recDepth;
		if (recDepth <= 10 && recDepth > 0)
		{
			break;
		}
	}
	RecursiveTTT game = RecursiveTTT();
	game.startGame(recDepth);

	return 0;
}
