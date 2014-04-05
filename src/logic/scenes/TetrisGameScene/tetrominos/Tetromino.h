//
//  Tetromino.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__Tetromino__
#define __Tetris__Tetromino__

#include <iostream>
#include <vector>
#include "../../../../include/SDL2/SDL.h"
#include "TetrisBrick.h"
#include "../game_field/TetrisOccupationMatrix.h"



class Tetromino {
	
public:
	Tetromino(int field_size, SDL_Point window_pos, int mesh_spacing, TetrisBrick::colors color, int num_of_bricks = 4);
	enum rotation							{ clockwise, c_clockwise };
	enum direction							{ left, right, up, down };
	enum tetrominos							{ I, L, J, Z, T, S, O, _end_ };
	void setWindowPosition(SDL_Point pos)	{ m_WindowPosition = pos; updateBrickWindowPositions(); }
	void move(direction dir);
	void rotate(rotation rot);
	void draw(int hide_rows);
	TetrisOccupationMatrix getOccupationAfterRotation(rotation rot);
	TetrisOccupationMatrix getOccupation();
	std::vector< TetrisBrick * > slurpBricks();
	virtual ~Tetromino();
	
protected:
	SDL_Point calculateRotation(SDL_Point point, rotation rot);
	SDL_Point rotatePoint(SDL_Point origin, rotation rot);
	SDL_Point rotPointToFieldPoint(SDL_Point rot_point);
	SDL_Point fieldPointToRotPoint(SDL_Point field_point);
	void updateBrickWindowPositions();
	
	std::vector< TetrisBrick * > m_Bricks;
	
	typedef std::vector< std::vector <TetrisBrick * > > TetrominoField;
	TetrominoField m_Field;
	SDL_Point m_WindowPosition;
	int m_MeshSpacing;
	
};

#endif /* defined(__Tetris__Tetromino__) */
