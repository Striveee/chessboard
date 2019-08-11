#include "graphics.h" // 就是需要引用这个图形库  
#include "Chessboard.h"
#include "Game.h"

Chessboard::Chessboard()
{
	_pimg = newimage(Game::_winWidth, Game::_winHeight);
	getimage(_pimg, ".\\pic\\Chessboard.jpg");
}

Chessboard::~Chessboard()
{
	delimage(_pimg);
}

void Chessboard::Draw()
{
	cleardevice(); 
	
	putimage(0,0,_pimg);
	/*int x1, y1, x2, y2;
	
	for(int i=0; i<Game::_gridCount+1; ++i)
	{
		x1 = (Game::_winWidth-Game::_gridSize*Game::_gridCount)/2;
		x2 = Game::_winWidth - x1;
		y1 = y2 = (Game::_winHeight-Game::_gridSize*Game::_gridCount)/2 +Game:: _gridSize * i;
		line(x1, y1, x2, y2);
	}	
	
	for(int i=0; i<Game::_gridCount+1; ++i)
	{
		y1 = (Game::_winHeight-Game::_gridSize*Game::_gridCount)/2;
		y2 = Game::_winHeight - y1;
		x1 = x2 = (Game::_winWidth-Game::_gridSize*Game::_gridCount)/2 + Game::_gridSize * i;
		line(x1, y1, x2, y2);
	}	*/	
}
