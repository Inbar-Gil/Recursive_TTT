//
// Created by t8747382 on 02/09/2021.
//
#include "Board.hpp"
#include <vector>


#ifndef RECURSIVETTT_RECURSIVEBOARD_HPP
#define RECURSIVETTT_RECURSIVEBOARD_HPP


class RecursiveBoard
{
private:

	int _recursionDepth;

	Board *_bigBoard;

	std::vector<RecursiveBoard *> _smallBoards;

	int *_lastMove;

	void _updateState();

	bool _isMovePossible(int *locs);

	static void _setupChart();


public:
	State state;

	RecursiveBoard();

	RecursiveBoard(int recDepth);

	~RecursiveBoard();

	State playMove(Move nextMove, int *locs);

	void printBoards();

	bool isMoveLegal(int *locs);

};


#endif //RECURSIVETTT_RECURSIVEBOARD_HPP
