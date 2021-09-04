//
// Created by t8747382 on 04/09/2021.
//

#include <sstream>
#include <cstring>
#include "RecursiveTTT.hpp"

RecursiveTTT::RecursiveTTT()
{
	_gameBoard = nullptr;
	_recursionDepth = 0;
	_gameState = E;
	_turn = X;
}

RecursiveTTT::~RecursiveTTT()
{
	delete _gameBoard;
}

void RecursiveTTT::startGame(int recDepth)
{
	_gameBoard = new RecursiveBoard(recDepth);
	_recursionDepth = recDepth;
	bool gameEnd = false;
	while (!gameEnd)
	{
		int *locs = getInput();
		if (locs == nullptr)
		{
			continue;
		}
		if (locs[0] == -1)
		{
			delete locs;
			break;
		}
		if (_gameBoard->isMoveLegal(locs))
		{
			std::cout << "Illegal Move, Try Again" << std::endl;
			delete[] locs;
			continue;
		}
		else
		{
			_gameBoard->playMove(_turn, locs);
			delete[] locs;
			_gameBoard->updateLastMove();
			_gameBoard->printBoards();
			_gameState = _gameBoard->state;
			switch (_turn)
			{
				case X:
					_turn = O;
					break;
				case O:
					_turn = X;
					break;
				case N:
					std::cout << "Something Went Wrong, Game Ending" << std::endl;
					gameEnd = true;
					break;
			}
			switch (_gameState)
			{
				case W:
				{
					std::cout << std::endl << std::endl << std::endl << "-----X has Won -----";
					gameEnd = true;
					break;
				}
				case L:
				{
					std::cout << std::endl << std::endl << std::endl << "-----O has Won -----";
					gameEnd = true;
					break;
				}
				case E:
				{
					break;
				}
			}
		}
	}
}

int *RecursiveTTT::getInput()
{
	std::string input;
	getline(std::cin, input);
	if (!input.empty())
	{
		if (input.at(0) == 'X')
		{
			int *error = new int;
			*error = -1;
			return error;
		}
	}

	std::vector<int> vect;
	std::stringstream ss(input);
	for (int i; ss >> i;)
	{
		vect.push_back(i);
		if (ss.peek() == ',')
		{
			ss.ignore();
		}
	}
	if (vect.size() != _recursionDepth)
	{
		if (input.empty())
		{
			std::cout << "Let's Begin The Game" << std::endl;
		}
		else
		{
			std::cout << "Wrong Move Format, Should be all coords seperated by commas" << std::endl;
		}
		return nullptr;
	}
	int *moves = new int[_recursionDepth];
	for (int i = 0; i < _recursionDepth; ++i)
	{
		moves[i] = vect[i];
	}
	return moves;
}
