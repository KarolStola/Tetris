//
//  TetrominoChooser.h
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrominoChooser__
#define __Tetris__TetrominoChooser__

#include <iostream>
#include <functional>
#include <map>
#include <random>
#include "Tetrominos.h"
#include "../../../../exceptions/TetrisException.h"

class TetrominoChooser{
	
public:
	TetrominoChooser();
	template <class T>
	void registerTetromino();
	Tetromino* choose(SDL_Point window_pos, int mesh_spacing);
	
private:
	typedef std::vector < std::function< Tetromino* (SDL_Point, int) > > TetrominoChooserDict;
	TetrominoChooserDict m_Dict;
	
};

template <class T>
void TetrominoChooser::registerTetromino(){
	m_Dict.push_back( [&](SDL_Point window_point, int mesh_spacing){
		return new T(window_point, mesh_spacing);
	});
}

#endif /* defined(__Tetris__TetrominoChooser__) */
