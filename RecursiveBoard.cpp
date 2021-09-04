//
// Created by t8747382 on 02/09/2021.
//

#include "RecursiveBoard.hpp"


int *reduceArray(const int *locs, int locsLength)
{
	int *reducedLocs = new int[locsLength - 1];
	for (int i = 0; i < locsLength - 1; ++i)
	{
		reducedLocs[i] = locs[i + 1];
	}
	return reducedLocs;
}

RecursiveBoard::RecursiveBoard()
{
	_recursionDepth = 1;
	_bigBoard = new Board;
	_smallBoards = std::vector<RecursiveBoard *>();
	_lastMove = nullptr;
	state = E;
}

RecursiveBoard::RecursiveBoard(int recDepth)
{
	_recursionDepth = recDepth;
	_bigBoard = new Board;

	if (recDepth <= 1)
	{
		_smallBoards = std::vector<RecursiveBoard *>();
		_lastMove = nullptr;
	}
	else
	{
		_smallBoards = std::vector<RecursiveBoard *>(BOARD_SIZE);
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			_smallBoards[i] = new RecursiveBoard(_recursionDepth - 1);
		}
		_lastMove = new int[_recursionDepth];
		for (int i = 0; i < _recursionDepth; ++i)
		{
			_lastMove[i] = -1;
		}
	}
	state = E;
}

RecursiveBoard::~RecursiveBoard()
{
	for (auto &_smallBoard : _smallBoards)
	{
		delete _smallBoard;
	}
	_smallBoards.clear();
	delete[] _lastMove;
	delete _bigBoard;
}

void RecursiveBoard::_updateState()
{
	state = (*_bigBoard).state;
}

State RecursiveBoard::playMove(Move nextMove, int *locs)
{

	if (_recursionDepth == 1)
	{
		(*_bigBoard).playMove(nextMove, locs[0]);
	}
	else
	{
		int *reducedLocs = reduceArray(locs, _recursionDepth);
		_smallBoards[locs[0]]->playMove(nextMove, reducedLocs);
		Move bigMove = (Move) _smallBoards[locs[0]]->state;
		(*_bigBoard).playMove(bigMove, locs[0]);
		delete[] reducedLocs;
		for (int i = 0; i < _recursionDepth; ++i)
		{
			_lastMove[i] = locs[i];
		}
	}
	_updateState();
	return state;
}

void RecursiveBoard::printBoards()
{
	if (_recursionDepth != 1)
	{
		std::cout << "####################" << std::endl << std::endl << std::endl;
	}
	_bigBoard->printBoard();
	if (_recursionDepth != 1)
	{
		std::cout << std::endl << std::endl << std::endl << "####################" << std::endl;
	}
	for (auto &_smallBoard : _smallBoards)
	{
		_smallBoard->printBoards();
	}
}

bool RecursiveBoard::_isMovePossible(int *locs)
{
	if ((*_bigBoard).isTaken(locs[0]))
	{
		return true;
	}
	if (_recursionDepth == 1)
	{
		return false;
	}
	int *reducedLocs = reduceArray(locs, _recursionDepth);
	bool result = _smallBoards[locs[0]]->_isMovePossible(reducedLocs);
	delete[] reducedLocs;
	return result;

}

bool RecursiveBoard::isMoveLegal(int *locs)
{
	if (_isMovePossible(locs))
	{
		return true;
	}
	for (int i = 0; i < _recursionDepth - 1; ++i)
	{
		if (locs[i] != _lastMove[i + 1] && _lastMove[i + 1] != -1)
		{
			return true;
		}
	}
	return false;
}


void RecursiveBoard::updateLastMove()
{
	for (int i = _recursionDepth - 1; i > 0; --i)
	{
		std::vector<int> vect;
		for (int j = i; j > 0; --j)
		{
			vect.push_back(_lastMove[j]);
		}
		if (_isTaken(vect))
		{
			_lastMove[i] = -1;
		}
	}
}

bool RecursiveBoard::_isTaken(std::vector<int> locs)
{
	int loc = locs.back();
	if (locs.size() == 1)
	{
		locs.clear();
		return _bigBoard->isTaken(loc);
	}
	locs.pop_back();
	return _smallBoards[loc]->_isTaken(locs);
}


