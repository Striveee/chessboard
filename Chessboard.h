#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "graphics.h" 

class Chessboard
{
	public:
		Chessboard();
		~Chessboard();
		void Draw();
	protected:
		PIMAGE  _pimg;
};

#endif
