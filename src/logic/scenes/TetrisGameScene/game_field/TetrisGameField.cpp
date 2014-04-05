//
//  TetrisGameField.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisGameField.h"

TetrisGameField::TetrisGameField(TetrisSpritesheet& spritesheet)
	: TetrisDrawable( spritesheet.getSDL_Texture(), spritesheet.getSDL_Renderer() )
	, m_Border( spritesheet.getSprite( "ui_panel_main" ) )
	, m_NextTetrominoPanel ( spritesheet.getSprite( "ui_panel_short" ) )
	, m_NextTetrominoIcon ( spritesheet.getSprite( "ui_icon_tile_next" ) )
	, m_FallingTetromino{NULL}
	, m_NextTetromino{NULL}
	, m_FallingTetrominoPosition(m_TetrominoStartingPoint)
	, m_Mode{classic}
{
	m_Border.move(240, 20);
	m_NextTetrominoPanel.move(35, 100);
	m_NextTetrominoIcon.move(
		m_NextTetrominoPanel.x() + 10,
		m_NextTetrominoPanel.y() + 13
	);
	m_TetrominoChooser.registerTetromino<Tetromino_I>();
	m_TetrominoChooser.registerTetromino<Tetromino_L>();
	m_TetrominoChooser.registerTetromino<Tetromino_J>();
	m_TetrominoChooser.registerTetromino<Tetromino_Z>();
	m_TetrominoChooser.registerTetromino<Tetromino_T>();
	m_TetrominoChooser.registerTetromino<Tetromino_S>();
	m_TetrominoChooser.registerTetromino<Tetromino_O>();
	
	m_CrazyTetrominoChooser.registerTetromino<Tetromino_Crazy>();
}

void TetrisGameField::initMatrix(){
	
	m_Matrix.resize( m_MatrixSize.h );
	for (auto& row : m_Matrix )
		row.resize( m_MatrixSize.w );
	
	for (int i = 0; i < m_Matrix.size(); i++) {
		for (int j = 0; j < m_Matrix[i].size(); j++) {
			SDL_Point screen_point = matrixPointToScreenPoint( {j, i} );
			m_Matrix[i][j].setPosition(screen_point.x, screen_point.y);
		}
	}
	
	changeFallingTetromino();
}

void TetrisGameField::changeFallingTetromino(){
	
	TetrominoChooser* next_tetromino_chooser;
	
	switch (m_Mode) {
		case classic :
			next_tetromino_chooser = & m_TetrominoChooser;
			break;
			
		case crazy :
			next_tetromino_chooser = & m_CrazyTetrominoChooser;
			break;
			
		default:
			break;
	}
	
	m_FallingTetrominoPosition = m_TetrominoStartingPoint;
	
	if ( m_FallingTetromino != NULL ) {
		delete m_FallingTetromino;
		m_FallingTetromino = m_NextTetromino;
		m_FallingTetromino->setWindowPosition(
			matrixPointToScreenPoint(m_FallingTetrominoPosition)
		);
	}
	else{
		m_FallingTetromino = next_tetromino_chooser->choose(
			matrixPointToScreenPoint(m_FallingTetrominoPosition),
			m_MeshSpacing
		);
	}
	
	m_NextTetromino = next_tetromino_chooser->choose(nextTetrominoScreenPoint(), m_MeshSpacing);
}

void TetrisGameField::reset(){
	
	for (auto& row : m_Matrix) {
		for (auto& mesh : row) {
			mesh.deleteBrick();
		}
	}
	
	if( m_FallingTetromino != NULL ){
		delete m_FallingTetromino;
		m_FallingTetromino = NULL;
	}
		
		
	if( m_NextTetromino != NULL ){
		delete m_NextTetromino;
		m_FallingTetromino = NULL;
	}
	
	changeFallingTetromino();
	
}

bool TetrisGameField::canBePlaced(TetrisOccupationMatrix occ_matrix, SDL_Point place){
	
	for (int i = 0; i < occ_matrix.size(); i++) {
		for (int j = 0; j < occ_matrix[i].size(); j++) {
			if ( occ_matrix[i][j] == true ) {
				
				int x = place.x + j;
				int y = place.y + i;
				
				if (
					x < 0 ||
					x >= m_Matrix[0].size() ||
					y < 0 ||
					y >= m_Matrix.size() ||
					m_Matrix[y][x].hasBrick()
				)
					return false;
				
			}
		}
	}
	
	return true;
}

bool TetrisGameField::canRotateTetromino( Tetromino::rotation rot ){
	
	TetrisOccupationMatrix occ_matrix = m_FallingTetromino->getOccupationAfterRotation(rot);
	
	return canBePlaced(occ_matrix, m_FallingTetrominoPosition);
}

bool TetrisGameField::canMoveTetromino( Tetromino::direction dir ){
	
	SDL_Point position = positionNextTo( m_FallingTetrominoPosition, dir);
	
	TetrisOccupationMatrix occ_matrix = m_FallingTetromino->getOccupation();
	
	return canBePlaced(occ_matrix, position);
}

void TetrisGameField::moveTetromino( Tetromino::direction dir ){
	m_FallingTetrominoPosition = positionNextTo(m_FallingTetrominoPosition, dir);
	m_FallingTetromino->setWindowPosition(
		matrixPointToScreenPoint(m_FallingTetrominoPosition)
	);
}

void TetrisGameField::placeTetromino(){
	
	TetrisOccupationMatrix occ_matrix = m_FallingTetromino->getOccupation();
	auto bricks = m_FallingTetromino->slurpBricks();
	
	for (int i = 0; i < occ_matrix.size(); i++) {
		for (int j = 0; j < occ_matrix[i].size(); j++) {
			if ( occ_matrix[i][j] == true && bricks.size() != 0) {
				
				int x = m_FallingTetrominoPosition.x + j;
				int y = m_FallingTetrominoPosition.y + i;
				
				if (! m_Matrix[y][x].hasBrick() ){
					m_Matrix[y][x].addBrick( bricks[bricks.size()-1] );
					bricks.pop_back();
				}
			}
		}
	}
	changeFallingTetromino();
}

bool TetrisGameField::rowIsFull(int row){
	if ( row < 0 || row >= m_Matrix.size() )
		throw TetrisException("Checkig row outside of game field.");
	
	for (int i = 0; i < m_Matrix[row].size(); i++)
		if (! m_Matrix[row][i].hasBrick() )
			return false;
	
	return true;
}

bool TetrisGameField::rowHasBrick(int row){
	if ( row < 0 || row >= m_Matrix.size() )
		throw TetrisException("Checkig row outside of game field.");
	
	for (int i = 0; i < m_Matrix[row].size(); i++)
		if ( m_Matrix[row][i].hasBrick() )
			return true;
	
	return false;
}

bool TetrisGameField::gameIsLost(){
	for (int i = 0; i < m_InvisibleRows; i++) {
		if ( rowHasBrick(i) ) {
			return true;
		}
	}
	return false;
}

int TetrisGameField::clearRows(){
	int rows_cleared = 0;
	for ( int i = (int)m_Matrix.size() - 1; i >= 0; i--){
		if ( rowIsFull(i) ){
			clearRow(i);
			dropRowsFromAbove(i);
			rows_cleared++;
			i++;
		}
	}
	return rows_cleared;
}

void TetrisGameField::clearRow(int i){
	for ( auto& mesh : m_Matrix[i] ) {
		mesh.deleteBrick();
	}
}

void TetrisGameField::dropRowsFromAbove( int i ){
	for (int y = i; y > 0; y--) {
		for (int x = 0; x < m_Matrix[y].size(); x++) {
			auto brick = m_Matrix[y-1][x].popBrick();
			m_Matrix[y][x].addBrick( brick );
		}
	}
}

SDL_Point TetrisGameField::positionNextTo(SDL_Point origin_pos, Tetromino::direction dir ){
	switch ( dir ) {
			
		case Tetromino::up :
			origin_pos.y--;
			break;
			
		case Tetromino::down :
			origin_pos.y++;
			break;
			
		case Tetromino::left :
			origin_pos.x--;
			break;
			
		case Tetromino::right :
			origin_pos.x++;
			break;
			
		default:
			break;
			
	}
	return origin_pos;
}

void TetrisGameField::draw() {
	
	m_Border.draw();
	m_NextTetrominoPanel.draw();
	m_NextTetrominoIcon.draw();
	
	for (int i = m_InvisibleRows; i < m_Matrix.size(); i++)
		for (auto& mesh : m_Matrix[i])
			mesh.draw();
	
	
	m_NextTetromino->draw(0);
	
	int hide_rows = m_InvisibleRows - m_FallingTetrominoPosition.y;
	m_FallingTetromino->draw(hide_rows);
	
}

SDL_Point TetrisGameField::matrixPointToScreenPoint(SDL_Point point){
	
	SDL_Point screen_point;
	
	SDL_Point origin_pos { m_Border.x(), m_Border.y()};
	origin_pos.x += 15;
	origin_pos.y += 10;
	
	screen_point.x = origin_pos.x + ( point.x * m_MeshSpacing ) + ( point.x * TetrisBrick::brickWidth() );
	screen_point.y = origin_pos.y + ( point.y * m_MeshSpacing ) + ( point.y*TetrisBrick::brickHeight() )
	- ( m_InvisibleRows * m_MeshSpacing ) - ( m_InvisibleRows * TetrisBrick::brickHeight() ); // two upper rows will be invisible
	
	return screen_point;
}

SDL_Point TetrisGameField::nextTetrominoScreenPoint(){
	SDL_Point screen_point = { m_NextTetrominoPanel.x(), m_NextTetrominoPanel.y() };
	screen_point.x += 65;
	screen_point.y += 10;
	return screen_point;
}

TetrisGameField::~TetrisGameField(){
	
}
