#ifndef LAYOUT_H
#define LAYOUT_H

typedef enum{CP_NOTHING,CP_BLACK,CP_WHITE}CHESS_PIECE;
//#include <algorithm> 
#include "graphics.h" 
#include <vector>
using namespace std;

struct POS
{
	int row;
	int col;
	
	bool operator==(const POS& pos)
	{
		return row == pos.row && col == pos.col;
	}
 } ;
 
class Layout
{
	public:
		Layout();
		~Layout();
		void Draw();
		void SetPieces(POS pos);
		bool IsHasPieces(POS pos);
		
		bool IsMaybePosEmpty();
		void ChangePlayer();
		void GetResult(int& blackCount, int& whiteCount); 
		bool IsMaybePos(POS pos);
	protected:
		void TurnPieces(POS pos); 
		vector<vector<CHESS_PIECE> > _layout;
		CHESS_PIECE _player;
		
		vector<POS> _allMaybePos;
		void GetAllMaybePos();
		bool IsInMaybePos(POS pos);
		bool IsLegalPos(POS pos);
		//bool IsHasPieces(POS pos);
		
		PIMAGE _pimgB;
		PIMAGE _pimgW;
		PIMAGE _pimgM;	
};

#endif
