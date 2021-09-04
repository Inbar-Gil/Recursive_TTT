//
// Created by t8747382 on 04/09/2021.
//

#ifndef RECURSIVETTT_RECURSIVETTT_HPP
#define RECURSIVETTT_RECURSIVETTT_HPP

#include "RecursiveBoard.hpp"
#include <string>


class RecursiveTTT
{
private:
	RecursiveBoard *_gameBoard;
	int _recursionDepth;
	State _gameState;
	Move _turn;

public:
	RecursiveTTT();
	~RecursiveTTT();
	void startGame(int recDepth);
	int *getInput();

};


#endif //RECURSIVETTT_RECURSIVETTT_HPP
