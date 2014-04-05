//
//  TetrisGameField.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisGameField__
#define __Tetris__TetrisGameField__

#include <iostream>
#include <string>
#include <vector>
#include "TetrisGameFieldMesh.h"
#include "../tetrominos/Tetromino.h"
#include "../tetrominos/TetrominoChooser.h"
#include "../../../events/TetrisEventHandler.h"
#include "../../../../display/TetrisSpritesheet.h"
#include "../../../../display/TetrisSprite.h"
#include "../../../../display/TetrisDrawable.h"

class TetrisGameField
	: public TetrisDrawable
{
	
public:
	TetrisGameField(TetrisSpritesheet& spritesheet);
	void initMatrix();
	bool canRotateTetromino( Tetromino::rotation rot );
	bool canMoveTetromino( Tetromino::direction dir );
	void moveTetromino( Tetromino::direction dir );
	void rotateTetromino(Tetromino::rotation rot)	{ m_FallingTetromino->rotate(rot); }
	virtual void draw();
	virtual ~TetrisGameField();
	void changeFallingTetromino();
	void placeTetromino();
	bool rowIsFull(int row);
	bool rowHasBrick(int row);
	bool gameIsLost();
	int clearRows();
	void clearRow(int i);
	enum modes {classic, crazy};
	void setMode( modes mode )						{ m_Mode = mode; }
	void reset();
	
	
	
private:
	
	SDL_Point matrixPointToScreenPoint(SDL_Point point);
	SDL_Point nextTetrominoScreenPoint();
	bool canBePlaced(TetrisOccupationMatrix occ_matrix, SDL_Point place);
	SDL_Point positionNextTo(SDL_Point origin_pos, Tetromino::direction dir );
	void dropRowsFromAbove( int i );
	
	modes m_Mode;
	
	TetrisSprite m_Border;
	TetrisSprite m_NextTetrominoPanel;
	TetrisSprite m_NextTetrominoIcon;
	
	const SDL_Point m_TetrominoStartingPoint = {4, 0};
	const SDL_Rect m_MatrixSize = {0,0,10,22};
	const int m_MeshSpacing = 2;
	const int m_InvisibleRows = 2;
	typedef std::vector< std::vector < TetrisGameFieldMesh > > TetrisMatrix;
	TetrisMatrix m_Matrix;
	
	TetrominoChooser m_TetrominoChooser;
	TetrominoChooser m_CrazyTetrominoChooser;
	Tetromino* m_FallingTetromino;
	SDL_Point m_FallingTetrominoPosition;
	Tetromino* m_NextTetromino;
	//TetrisGameFieldMesh** m_Matrix;
	
};

#endif /* defined(__Tetris__TetrisGameField__) */
