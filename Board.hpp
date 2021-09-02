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
#define UNDERSCORE "\u0332"

enum Move
{
	X = 1, O = -1, N = 0
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

	void printBoard();

};


#endif //RECURSIVETTT_BOARD_HPP
