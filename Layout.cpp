#include "Layout.h"
#include "Game.h"
#include "graphics.h"
#include <algorithm> 

Layout::Layout()
{

	_pimgB = newimage(50,50);
	getimage(_pimgB,".\\pic\\Black.jpg");
	_pimgW = newimage(50,50);
	getimage(_pimgW,".\\pic\\White.jpg");
	_pimgM = newimage(50,50);
	getimage(_pimgM,".\\pic\\Mark.jpg");
	
	
	
	_layout.resize(Game::_gridCount);
	for(int i=0;i<Game::_gridCount;++i)
	{
		_layout[i].resize(Game::_gridCount);
    } 
    
	for(int i=0;i<Game::_gridCount;++i)
	{
		for(int j=0;j<Game::_gridCount;++j)
		{
			_layout[i][j] = CP_NOTHING;
		}
	} 
	
	_layout[3][3] = _layout[4][4] = CP_WHITE;
	_layout[3][4] = _layout[4][3] = CP_BLACK;
	
	_player = CP_BLACK;
	
	GetAllMaybePos(); 
	
}

Layout::~Layout()
{
	delimage(_pimgB);
	delimage(_pimgW);
	delimage(_pimgM);
}

void Layout::SetPieces(POS pos)
{
	
	_layout[pos.row][pos.col] = _player;
	TurnPieces(pos); 
	_player = (CHESS_PIECE)(3-_player); 
	GetAllMaybePos();
}

void Layout::Draw()
{
	int x,y;

	for(int i=0; i<Game::_gridCount; ++i)
	{
		for(int j=0; j<Game::_gridCount; ++j)
		{
			x = Game::_xBegin + j * Game::_gridSize + 2;
			y = Game::_yBegin + i * Game::_gridSize + 2;	
			if(_layout[i][j] == CP_BLACK)
			{
				putimage(x,y,_pimgB);
			}
			else if (_layout[i][j] == CP_WHITE)
			{
				putimage(x,y,_pimgW);
			}
			else
			{
				continue;
			}
			//setfillcolor(EGERGB(255,255,255));
			//x = Game::_xBegin + j * Game::_gridSize + Game::_gridSize/2;
			//y = Game::_yBegin + i * Game::_gridSize + Game::_gridSize/2;
			//fillellipse(x,y,Game::_pieceSize,Game::_pieceSize);
		}
	}
	
	setfillcolor(EGERGB(255,255,0));
	for(int i=0;i<_allMaybePos.size();++i)
	{
		y = Game::_yBegin + _allMaybePos[i].row * Game::_gridSize + 2 ;
		x = Game::_xBegin + _allMaybePos[i].col * Game::_gridSize + 2 ;
		putimage(x,y,_pimgM);
	}
}

void Layout::GetAllMaybePos()
{
	_allMaybePos.clear();
	POS pos;
	
	for(pos.row=0; pos.row < Game::_gridCount;++pos.row)
	{
		for(pos.col=0; pos.col < Game::_gridCount;++pos.col)
		{
			if(!IsHasPieces(pos)&&IsMaybePos(pos))
			{
				_allMaybePos.push_back(pos); 
			}
		}
	}
	
}

bool Layout::IsHasPieces(POS pos)
{
	return _layout[pos.row][pos.col] == CP_NOTHING ? false : true;
}

/*
功能描述：判断所给的pos位置是否是一个可落子位置
函数名  ：IsMaybePos
输入	：pos，所判断的位置 
输出	：bret，为真pos位置可落子，为假pos位置不可落子
外部数据：_layout，_player
外部函数：
作者    ：
时间    ：2017-12-26
版本    ：ver 0.1
-----------
修改    ：
版本    ： 
*/
bool Layout::IsMaybePos(POS pos)
{
	bool bret = false;
	POS nextPos;
	
	for(int row=-1; row <=1; ++row)
	{
		for(int col=-1; col <=1; ++col)	
		{
			if(row == 0 && col == 0)
			{
				continue;
			}
			nextPos.row = pos.row + row;
			nextPos.col = pos.col + col;
			
			if(IsLegalPos(nextPos) &&
			_layout[nextPos.row][nextPos.col] == (CHESS_PIECE)(3-_player))	
			{
				for(nextPos.row += row,nextPos.col += col;
				IsLegalPos(nextPos);
				nextPos.row += row, nextPos.col += col)
				{
					if(_layout[nextPos.row][nextPos.col] ==
					(CHESS_PIECE)(3-_player))
					{
						continue;
					}
					else if(_layout[nextPos.row][nextPos.col] == _player)
					{
						return true;
					} 
					else
					{
						break;
					}
				}
			}
			  
		}	
	}
	return false;
}

bool Layout::IsLegalPos(POS pos)
{
	if(pos.row >= 0 && pos.row < Game::_gridCount &&
	pos.col >= 0 && pos.col < Game::_gridCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Layout::IsInMaybePos(POS pos)
{
	vector<POS>::iterator itr;
	itr = find(_allMaybePos.begin(),_allMaybePos.end(),pos);
	
	if(itr != _allMaybePos.end())
	{
		return true;
	} 
	else
	{
		return false;
	} 
}

void  Layout::TurnPieces(POS pos)
{
	POS nextPos;
	
	for(int row=-1; row<=1; ++row)
	{
		for(int col=-1;col <=1; ++col)
		{
			if(row == 0 && col == 0)
			{
				continue; 
			} 
			nextPos.row = pos.row + row;
			nextPos.col = pos.col + col;
			
			if(IsLegalPos(nextPos)&&
			_layout[nextPos.row][nextPos.col] == (CHESS_PIECE)(3-_player))
			{
				for(nextPos.row += row,nextPos.col += col;
				IsLegalPos(nextPos);
				nextPos.row += row,nextPos.col += col)
				{
					if(_layout[nextPos.row][nextPos.col] ==
					(CHESS_PIECE)(3-_player))
					{
						continue;
					}
					else if(_layout[nextPos.row][nextPos.col] == _player)
					{
						while(!(nextPos == pos))
						{
							_layout[nextPos.row][nextPos.col] = _player;
							nextPos.row -= row;
							nextPos.col -= col;
						}
						break;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}

bool Layout::IsMaybePosEmpty()
{
	return _allMaybePos.empty();
}

void Layout::ChangePlayer()
{
	_player = (CHESS_PIECE)(3-_player);
	GetAllMaybePos();
}

void Layout::GetResult(int& blackCount, int& whiteCount)
{
	for(int i=0; i<Game::_gridCount; ++i)
	{
		for(int j=0; j<Game::_gridCount; ++j)
		{
			if( _layout[i][j] == CP_BLACK)
			{
				blackCount += 1;
			}
			else if(_layout[i][j] == CP_WHITE)
			{
				whiteCount += 1;
			}
		}
	}
}
