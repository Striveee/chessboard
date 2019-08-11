#ifndef GAME_H
#define GAME_H

#include "Chessboard.h"
#include "Layout.h"

class Game
{
	public:
		Game();
		~Game();
	protected:
		Chessboard _cb;
		Layout     _layout;
	public:
		static int _gridSize;
		static int _gridCount;
		static int _winWidth;
		static int _winHeight;
		static int _xBegin;
		static int _yBegin;
		static int _pieceSize; 
	public:
		void Run();
	protected:
		bool GetMouseHit(POS& pos);
		void GameOver();
};

#endif
