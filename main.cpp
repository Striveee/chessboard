#include "Game.h"
#include "graphics.h" // ������Ҫ�������ͼ�ο�  
#include "Chessboard.h"

int main()
{
	initgraph(Game::_winWidth, Game::_winHeight, INIT_RENDERMANUAL);
	setbkcolor(EGERGB(40,150,170));
	
	HWND hwnd = getHWnd();
	SetWindowText(hwnd,"�ڰ���");
	 
	Game game;
	
	game.Run();
	
	getch();  
	closegraph();   
	return 0;
}

