#include "Game.h"
#include "graphics.h" // 就是需要引用这个图形库  
#include "Chessboard.h"

int main()
{
	initgraph(Game::_winWidth, Game::_winHeight, INIT_RENDERMANUAL);
	setbkcolor(EGERGB(40,150,170));
	
	HWND hwnd = getHWnd();
	SetWindowText(hwnd,"黑白棋");
	 
	Game game;
	
	game.Run();
	
	getch();  
	closegraph();   
	return 0;
}

