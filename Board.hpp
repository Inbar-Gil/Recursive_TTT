//
// Created by t8747382 on 30/08/2021.
//
#include <iostream>

#ifndef RECURSIVETTT_BOARD_HPP
#define RECURSIVETTT_BOARD_HPP


enum Move
{
	X = 1, O = -1
};


class Board
{
private:
	int *_board;

	int _count_X();

	int _count_O();

public:
	int state;

	int score;

	void playMove(Move nextMove, int loc);

	int updateScore();

	Board();

	~Board();

};


int Board::_count_X()
{
	int counter = 0;
	for (int i = 0; i < 9; i++)
	{
		if (_board[i] == Move(X))
		{
			int x = 5;
		}
	}
	return 0;
}

int Board::_count_O()
{
	return 0;
}

void Board::playMove(Move nextMove, int loc)
{
	std::cout << nextMove;
	_board[loc] = nextMove;
}

Board::Board()
{
	_board = new int[9 * sizeof(int)];
	state = 0;
	score = 0;
}

Board::~Board()
{
	delete _board;
}

int Board::updateScore()
{
	if (state == 1)
	{
		return 100;
	}
	if (state == -1)
	{
		
	}
	return 0;
}


#endif //RECURSIVETTT_BOARD_HPP
