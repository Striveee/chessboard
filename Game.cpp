#include "Game.h"
#include "graphics.h"
#include <windows.h>
#include <stdio.h>

int Game::_winWidth	    =490;   //��� 
 int Game::_winHeight	=490;	//�߶� 
 int Game::_gridSize	=53;	//С�����С 
 int Game::_gridCount	=8;		//С��������

int Game::_pieceSize  = _gridSize/2-2;

int Game::_xBegin  = (Game::_winWidth - Game::_gridSize*Game::_gridCount)/2;
int Game::_yBegin  = (Game::_winHeight - Game::_gridSize*Game::_gridCount)/2;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
	_cb.Draw();
	_layout.Draw();
	
	POS pos;
	for(; is_run(); delay_fps(100))
	{
		while(!GetMouseHit(pos));
		
		if(!_layout.IsMaybePosEmpty() && _layout.IsMaybePos(pos))
		{
			_layout.SetPieces(pos);
			
			_cb.Draw();
			_layout.Draw();
			delay_fps(100);
			if(_layout.IsMaybePosEmpty()) 
			{
				//����
				
				_layout.ChangePlayer() ;
				_cb.Draw();
				_layout.Draw();
			
				
				if(_layout.IsMaybePosEmpty())
				{
					GameOver();
					break;
				}
					HWND hwnd = getHWnd();
				MessageBox(hwnd,"����","��ʾ",MB_OK);
				//xyprintf(0,0,"����") ;
				
			}
		}
		
	}
}

bool Game::GetMouseHit(POS& pos)
{
	mouse_msg msg;
	msg = getmouse();
	if(msg.is_left() && msg.is_down())
	{
		if(msg.x - _xBegin > 0 && msg.y - _yBegin > 0)
		{
			pos.row = (msg.y-_yBegin)/_gridSize;
			pos.col = (msg.x-_xBegin)/_gridSize;
			
			if(pos.row >= 0 && pos.row < _gridCount &&
			pos.col >=0 && pos.col <_gridCount)
			{
				return true; 
			}	
		}
	
	}
	return false;
 } 
 
void Game::GameOver()
{
	int blackCount=0, whiteCount=0;
	_layout.GetResult(blackCount,whiteCount);
	
	char str[10];
	char buf[128];
	if(blackCount > whiteCount)
	{
		strcpy(str,"����Ӯ��"); 
	}
	else if(blackCount < whiteCount)
	{
		strcpy(str,"����Ӯ��");
	} 
	else
	{
		strcpy(str,"���壡");
	}
	sprintf(buf,"����:%d  ���壺%d,%s",
	blackCount,whiteCount,str);
	HWND hwnd = getHWnd();
	MessageBox(hwnd,buf,"��ʾ",MB_OK);
	
	//��ʾ��� 
}
