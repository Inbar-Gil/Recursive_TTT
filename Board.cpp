//
// Created by t8747382 on 02/09/2021.
//

#include "Board.hpp"

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

Board::Board()
{
	_board = new int[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		_board[i] = 0;
	}
	state = E;
	score = 0;
}

Board::~Board()
{
	delete[] _board;
	_board = nullptr;
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

State Board::playMove(Move nextMove, int loc)
{
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
	else if (state == TW || state == TL)
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
	if (state)
	{
		return;
	}
	if (_board[0] == _board[1] && _board[1] == _board[2])
	{
		state = (State) _board[0];
	}
	else if (_board[3] == _board[4] && _board[4] == _board[5])
	{
		state = (State) _board[4];
	}
	else if (_board[6] == _board[7] && _board[7] == _board[8])
	{
		state = (State) _board[7];
	}
	else if (_board[0] == _board[3] && _board[3] == _board[6])
	{
		state = (State) _board[3];
	}
	else if (_board[1] == _board[4] && _board[4] == _board[7])
	{
		state = (State) _board[1];
	}
	else if (_board[2] == _board[5] && _board[5] == _board[8])
	{
		state = (State) _board[2];
	}
	else if (_board[0] == _board[4] && _board[4] == _board[8])
	{
		state = (State) _board[8];
	}
	else if (_board[2] == _board[4] && _board[4] == _board[6])
	{
		state = (State) _board[6];
	}
	if (!state)
	{
		while (true)
		{
			if (i == 9)
			{
				if (_count_X() >= 5)
				{
					state = TW;
				}
				else
				{
					state = TL;
				}
				return;
			}
			if (!_board[i])  //breaks if any square is empty
			{
				break;
			}
			i++;
		}
	}
}

void Board::printBoard()
{
	std::cout << "********************" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		if (i != 2)
		{
			std::cout << UNDERSCORE;
		}
		std::cout << (Move) _board[3 * i];
		for (int j = 1; j < 3; ++j)
		{
			std::cout << "|";
			if (i != 2)
			{
				std::cout << UNDERSCORE;
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

bool Board::isTaken(int loc)
{
	return (bool) _board[loc];
}

