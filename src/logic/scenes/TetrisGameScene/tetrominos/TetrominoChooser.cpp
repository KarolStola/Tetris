//
//  TetrominoChooser.cpp
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrominoChooser.h"

TetrominoChooser::TetrominoChooser(){
	srand((int)time(NULL));
}

Tetromino* TetrominoChooser::choose(SDL_Point window_pos, int mesh_spacing){
	
	/*
	std::default_random_engine engine {};
	std::uniform_int_distribution<> distribution { 0, (int)(m_Dict.size()-1) };
	//std::uniform_int_distribution<> distribution { 0, 2 };
	
	auto randomize = bind(distribution, engine);

	int choosen_number = randomize();
	*/
	int choosen_number = rand() % m_Dict.size();
	auto create_tetromino = m_Dict[choosen_number];
	
	return create_tetromino(window_pos, mesh_spacing);
}