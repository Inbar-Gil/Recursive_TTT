//
// Created by t8747382 on 30/08/2021.
//
#include <iostream>
#include <map>
#include <string>

#ifndef RECURSIVETTT_BOARD_HPP
#define RECURSIVETTT_BOARD_HPP

#define BOARD_SIZE 9
#define WIN_SCORE 100
#define TIE_SCORE 50

enum Move
{
	X = 1, O = -1, N = 0
};

enum State
{
	W = 1, T = 3, L = 2, E = 0
};

std::ostream &operator<<(std::ostream &out, const Move value)
{
	static std::map<Move, std::string> strings;
	if (strings.empty())
	{
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(X);
		INSERT_ELEMENT(O);
		strings[N] = " ";
#undef INSERT_ELEMENT
	}
	return out << strings[value];
}


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

	void printBoard();

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
	printBoard();
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
			int scoreFactor = (int) (bool) (_board[i]) * _board[i];
			if (!(i % 2))
			{
				if (i == 4)
				{
					score = score + scoreFactor * 4;
				}
				else
				{
					score = score + scoreFactor * 3;
				}
			}
			else
			{
				score = score + scoreFactor * 2;
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
		state = _board[4];
	}
	else if (_board[6] == _board[7] && _board[7] == _board[8])
	{
		state = _board[7];
	}
	else if (_board[0] == _board[3] && _board[3] == _board[6])
	{
		state = _board[3];
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
		state = _board[8];
	}
	else if (_board[2] == _board[4] && _board[4] == _board[6])
	{
		state = _board[6];
	}
}

void Board::printBoard()
{
	std::cout << "********************" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		if (i != 2)
		{
			std::cout << "\u0332";
		}
		std::cout << (Move) _board[3 * i];
		for (int j = 1; j < 3; ++j)
		{
			std::cout << "|";
			if (i != 2)
			{
				std::cout << "\u0332";
			}
			std::cout << (Move) _board[3 * i + j];
		}
		std::cout << std::endl;
	}
	switch (state)
	{
		case W:
		{
			std::cout << "X Wins!" << std::endl;
			break;
		}
		case T:
		{
			std::cout << "It's a Tie!" << std::endl;
			break;
		}
		case L:
		{
			std::cout << "O Wins!" << std::endl;
			break;
		}
		case E:
		{
			std::cout << "Keep Playing" << std::endl;
			break;
		}

	}
	std::cout << "********************" << std::endl;

}

#endif //RECURSIVETTT_BOARD_HPP
