//
//  Tetrominos.cpp
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "Tetrominos.h"

Tetromino_I::Tetromino_I(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(4, window_pos, mesh_spacing, TetrisBrick::orange)
{
	m_Field[1][0] = m_Bricks[0];
	m_Field[1][1] = m_Bricks[1];
	m_Field[1][2] = m_Bricks[2];
	m_Field[1][3] = m_Bricks[3];
	
	updateBrickWindowPositions();
}

Tetromino_J::Tetromino_J(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(3, window_pos, mesh_spacing, TetrisBrick::green_light)
{
	m_Field[1][0] = m_Bricks[0];
	m_Field[1][1] = m_Bricks[1];
	m_Field[1][2] = m_Bricks[2];
	m_Field[0][0] = m_Bricks[3];
	
	updateBrickWindowPositions();
}

Tetromino_L::Tetromino_L(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(3, window_pos, mesh_spacing, TetrisBrick::red)
{
	m_Field[1][0] = m_Bricks[0];
	m_Field[1][1] = m_Bricks[1];
	m_Field[1][2] = m_Bricks[2];
	m_Field[0][2] = m_Bricks[3];
	
	updateBrickWindowPositions();
}


Tetromino_Z::Tetromino_Z(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(3, window_pos, mesh_spacing, TetrisBrick::yellow)
{
	m_Field[0][0] = m_Bricks[0];
	m_Field[0][1] = m_Bricks[1];
	m_Field[1][1] = m_Bricks[2];
	m_Field[1][2] = m_Bricks[3];
	
	updateBrickWindowPositions();
}


Tetromino_T::Tetromino_T(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(3, window_pos, mesh_spacing, TetrisBrick::magenta)
{
	m_Field[1][0] = m_Bricks[0];
	m_Field[1][1] = m_Bricks[1];
	m_Field[1][2] = m_Bricks[2];
	m_Field[0][1] = m_Bricks[3];
	
	updateBrickWindowPositions();
}

Tetromino_S::Tetromino_S(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(3, window_pos, mesh_spacing, TetrisBrick::violet)
{
	m_Field[0][2] = m_Bricks[0];
	m_Field[0][1] = m_Bricks[1];
	m_Field[1][1] = m_Bricks[2];
	m_Field[1][0] = m_Bricks[3];
	
	updateBrickWindowPositions();
}

Tetromino_O::Tetromino_O(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(2, window_pos, mesh_spacing, TetrisBrick::green_dark)
{
	m_Field[0][0] = m_Bricks[0];
	m_Field[0][1] = m_Bricks[1];
	m_Field[1][0] = m_Bricks[2];
	m_Field[1][1] = m_Bricks[3];
	
	updateBrickWindowPositions();
}


Tetromino_Crazy::Tetromino_Crazy(SDL_Point window_pos, int mesh_spacing)
	:Tetromino(
		3,
		window_pos, mesh_spacing,
		(TetrisBrick::colors)(rand()%((int)TetrisBrick::_end_)),
		4+(rand()%2)
	)
{
	int x, y;
	for (int i =0; i < m_Bricks.size(); i++) {
		
		do{
			
			y = rand() % m_Field.size();
			x = rand() % m_Field[y].size();
			
		}while( m_Field[y][x] != NULL );
		
		m_Field[y][x] = m_Bricks[i];
	}
	
	updateBrickWindowPositions();
}