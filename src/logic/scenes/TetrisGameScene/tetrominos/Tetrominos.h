//
//  Tetrominos.h
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__Tetrominos__
#define __Tetris__Tetrominos__

#include <iostream>
#include "../../../../include/SDL2/SDL.h"
#include "Tetromino.h"
#include "TetrisBrick.h"

class Tetromino_I: public Tetromino{
public:
	Tetromino_I(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_J: public Tetromino{
public:
	Tetromino_J(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_L: public Tetromino{
public:
	Tetromino_L(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_Z: public Tetromino{
public:
	Tetromino_Z(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_T: public Tetromino{
public:
	Tetromino_T(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_S: public Tetromino{
public:
	Tetromino_S(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_O: public Tetromino{
public:
	Tetromino_O(SDL_Point window_pos, int mesh_spacing);
};

class Tetromino_Crazy: public Tetromino{
public:
	Tetromino_Crazy(SDL_Point window_pos, int mesh_spacing);
};

#endif /* defined(__Tetris__Tetrominos__) */
