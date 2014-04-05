//
//  Tetromino.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "Tetromino.h"

Tetromino::Tetromino(int field_size, SDL_Point window_pos, int mesh_spacing, TetrisBrick::colors color, int num_of_bricks )
	: m_MeshSpacing{mesh_spacing}
	, m_WindowPosition(window_pos)
{
	m_Bricks.resize(num_of_bricks, NULL);
	for (auto& brick : m_Bricks)
		brick = TetrisBrick::create(color);
	
	m_Field.resize(field_size);
	for (auto& row : m_Field)
		row.resize(field_size, NULL);
	
}

TetrisOccupationMatrix Tetromino::getOccupationAfterRotation(rotation rot){
	
	TetrisOccupationMatrix matrix( m_Field.size() );
	
	for (int i = 0; i < m_Field.size(); i++) {
		for (int j = 0; j < m_Field[i].size(); j++) {
			if( m_Field[j][i] != NULL ){
				SDL_Point rotation = calculateRotation({j,i}, rot);
				matrix[rotation.x][rotation.y] = true;
			}
		}
	}
	
	return matrix;
}

TetrisOccupationMatrix Tetromino::getOccupation(){
	
	TetrisOccupationMatrix matrix(m_Field.size());
	
	for (int i = 0; i < m_Field.size(); i++)
		for (int j = 0; j < m_Field[i].size(); j++)
			if ( m_Field[i][j] != NULL )
				matrix[i][j] = true;
	
	return matrix;
}

void Tetromino::updateBrickWindowPositions(){
	for (int i = 0; i < m_Field.size(); i++) {
		for (int j = 0; j < m_Field[i].size(); j++) {
			if ( m_Field[i][j] != NULL ) {
				int x = m_WindowPosition.x + (j*TetrisBrick::brickWidth()) + (j*m_MeshSpacing);
				int y = m_WindowPosition.y + (i*TetrisBrick::brickHeight()) + (i*m_MeshSpacing);
				
				m_Field[i][j]->move(x,y);
			}
		}
	}
}

void Tetromino::draw(int hide_rows){
	for (int i = (int)m_Field.size() - 1; i >= 0 && i >= hide_rows; i-- )
		for (int j = 0; j < m_Field[i].size(); j++)
			if (m_Field[i][j] != NULL)
				m_Field[i][j]->draw();
}

void Tetromino::rotate(rotation rot){
	TetrominoField tmp_field = m_Field;
	for (int i = 0; i < m_Field.size(); i++) {
		for (int j = 0; j < m_Field[i].size(); j++) {
			SDL_Point rotation = calculateRotation({j,i}, rot);
			tmp_field[rotation.x][rotation.y] = m_Field[j][i];
		}
	}
	m_Field = tmp_field;
	updateBrickWindowPositions();
}

SDL_Point Tetromino::calculateRotation(SDL_Point point, rotation rot){
	SDL_Point calculated;
	calculated = fieldPointToRotPoint(point);
	calculated = rotatePoint(calculated, rot);
	calculated = rotPointToFieldPoint(calculated);
	return calculated;
}

SDL_Point Tetromino::rotatePoint(SDL_Point origin, rotation rot){
	SDL_Point rot_point = {0,0};
	switch (rot) {
		case c_clockwise:
			rot_point.x = origin.y;
			rot_point.y = -origin.x;
			break;
			
		case clockwise:
			rot_point.x = -origin.y;
			rot_point.y = origin.x;
			break;
			
		default:
			break;
	}
	return rot_point;
}

SDL_Point Tetromino::rotPointToFieldPoint(SDL_Point rot_point){
	
	SDL_Point iter_helper = {0,0};
	SDL_Point field_point = {0,0};
	
	int field_size = (int)m_Field.size();
	
	bool even_field_size = ((field_size % 2) == 0 );
	
	iter_helper.x = field_size / -2;
	iter_helper.y = field_size / 2;
	
	
	while (iter_helper.x != rot_point.x ) {
		field_point.x++;
		iter_helper.x++;
		
		if ( even_field_size && iter_helper.x == 0 )
			iter_helper.x++;
	}
	
	while (iter_helper.y != rot_point.y ) {
		field_point.y++;
		iter_helper.y--;
		
		if ( even_field_size && iter_helper.y == 0 )
			iter_helper.y--;
	}
	
	return field_point;
}

std::vector< TetrisBrick * > Tetromino::slurpBricks(){
	auto bricks = m_Bricks;
	
	for ( auto& brick : m_Bricks )
		brick = NULL;
	
	return bricks;
}

SDL_Point Tetromino::fieldPointToRotPoint(SDL_Point field_point){
	SDL_Point iter_helper = {0,0};
	SDL_Point rot_point = {0,0};
	
	int field_size = (int)m_Field.size();
	
	bool even_field_size = ((field_size % 2) == 0 );
	
	rot_point.x = field_size / -2;
	rot_point.y = field_size / 2;
	
	
	while (iter_helper.x != field_point.x ) {
		rot_point.x++;
		iter_helper.x++;
		
		if ( even_field_size && rot_point.x == 0 )
			rot_point.x++;
			
	}
	
	while (iter_helper.y != field_point.y ) {
		rot_point.y--;
		iter_helper.y++;
		
		if ( even_field_size && rot_point.y == 0 )
			rot_point.y--;
	}
	
	return rot_point;
}

Tetromino::~Tetromino(){
	for (auto& brick :m_Bricks)
		if (brick != NULL)
			delete brick;
}
