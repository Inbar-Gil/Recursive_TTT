//
// Created by t8747382 on 30/08/2021.
//
#include <iostream>

#ifndef RECURSIVETTT_BOARD_HPP
#define RECURSIVETTT_BOARD_HPP
#define BOARD_SIZE 9
#define WIN_SCORE 100
#define TIE_SCORE 50


enum Move
{
	X = 1, O = 2
};

enum State
{
	W = 1, T = 3, L = 2, E = 0
};


class Board
{
private:
	int *_board;

	int _count_X();

	void _updateState();

public:
	int state;

	int score;

	Board();

	~Board();

	int playMove(Move nextMove, int loc);

	int updateScore();

};


Board::Board()
{
	_board = new int[BOARD_SIZE * sizeof(int)];
	state = 0;
	score = 0;
}

Board::~Board()
{
	delete _board;
}

int Board::_count_X()
{
	int counter = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (_board[i] == Move(X))
		{
			counter++;
		}
	}
	return counter;
}

int Board::playMove(Move nextMove, int loc)
{
	if (_board[loc])
	{
		return -1;
	}
	_board[loc] = nextMove;
	_updateState();
	return state;
}

int Board::updateScore()
{
	score = 0;
	if (state == W)
	{
		score = WIN_SCORE;
	}
	else if (state == L)
	{
		score = -WIN_SCORE;
	}
	else if (state == T)
	{
		if (_count_X() >= 5)
		{
			score = TIE_SCORE;
		}
		else
		{
			score = -TIE_SCORE;
		}
	}
	else
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			int taken = (int) (bool) (_board[i]);
			if (!(i % 2))
			{
				if (i == 4)
				{
					score = score + taken * 4;
				}
				else
				{
					score = score + taken * 3;
				}
			}
			else
			{
				score = score + taken * 2;
			}
		}
	}
	return score;
}

void Board::_updateState()
{
	int i = 0;
	while (true)
	{
		if (i == 9)
		{
			state = T;  // if all squares are full then it's considered a Tie (even if it's not)
			return;
		}
		if (!_board[i])  //breaks if any square is empty
		{
			break;
		}
		i++;
	}
	if (_board[0] == _board[1] && _board[1] == _board[2])
	{
		state = _board[0];
	}
	else if (_board[3] == _board[4] && _board[4] == _board[5])
	{
		state = _board[3];
	}
	else if (_board[6] == _board[7] && _board[7] == _board[8])
	{
		state = _board[6];
	}
	else if (_board[0] == _board[3] && _board[3] == _board[6])
	{
		state = _board[0];
	}
	else if (_board[1] == _board[4] && _board[4] == _board[7])
	{
		state = _board[1];
	}
	else if (_board[2] == _board[5] && _board[5] == _board[8])
	{
		state = _board[2];
	}
	else if (_board[0] == _board[4] && _board[4] == _board[8])
	{
		state = _board[0];
	}
	else if (_board[2] == _board[4] && _board[4] == _board[6])
	{
		state = _board[2];
	}
}


#endif //RECURSIVETTT_BOARD_HPP
