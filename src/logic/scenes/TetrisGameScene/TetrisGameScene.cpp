//
//  TetrisGameScene.cpp
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisGameScene.h"

TetrisGameScene::TetrisGameScene( TetrisWindow* window, ChangeSceneCallback callback )
	: TetrisSceneBase(window, callback)
	, m_Spritesheet{ m_SpritesheetLocation + "tetris_main_001.png", m_Window->getRenderer() }
	, m_Background{ m_Spritesheet.getSprite("bg_main") }
	, m_GameField{m_Spritesheet}
	, m_BasicDropTime{1000}
	, m_DropTime{m_BasicDropTime}
	, m_SpeedUpMultiplier{15.f}
	, m_SpeedUp{false}
	, m_GameOver{false}
	, m_ScoreLabel{m_Window->getRenderer()}
	, m_GameOverLabel {m_Window->getRenderer(), "Game Over"}
	, m_GameOverHintLabel(m_Window->getRenderer(), "press esc to go back")
	, m_Score{0}
	, m_Level{0}
	, m_RowsClearedOnThisLevel{0}
	, m_RowsNeededToLevelUp{7}
	, m_NextLevelDropTimeMultiplier{0.75}
{
	TetrisBrick::registerSpritesheet(&m_Spritesheet);
	m_GameField.initMatrix();
	
	int window_width = m_Background.width();
	int window_height =  m_Background.height();
	m_Window->resize(window_width, window_height);
	
	m_ScoreLabel.setFontSize(60);
	m_ScoreLabel.setText( std::to_string(m_Score) );
	m_ScoreLabel.setPosition( {525, 50 } );
	
	m_GameOverLabel.setFontSize(100);
	m_GameOverLabel.setPosition( {100, 200} );
	m_GameOverHintLabel.setFontSize(30);
	m_GameOverHintLabel.setPosition( {220, 300} );
	
	m_ScoreForRowsCleared.push_back(0);
	m_ScoreForRowsCleared.push_back(40);
	m_ScoreForRowsCleared.push_back(100);
	m_ScoreForRowsCleared.push_back(300);
	m_ScoreForRowsCleared.push_back(1200);
	
	m_Timer.start();
}

void TetrisGameScene::updateLogic(){
	if ( m_GameOver )
		return;
	
	int current_drop_time = m_DropTime;
	if ( m_SpeedUp )
		current_drop_time /= m_SpeedUpMultiplier;
		
	if (m_Timer.getTicks() >= current_drop_time) {
		
		if ( m_GameField.canMoveTetromino( Tetromino::down ) )
			m_GameField.moveTetromino( Tetromino::down );
		else{
			
			m_GameField.placeTetromino();
			
			int rows_cleared = m_GameField.clearRows();
			m_Score += m_ScoreForRowsCleared[rows_cleared] * (m_Level + 1);
			m_RowsClearedOnThisLevel += rows_cleared;
			
			if (m_RowsClearedOnThisLevel >= m_RowsNeededToLevelUp) {
				m_Level++;
				m_RowsClearedOnThisLevel -= m_RowsNeededToLevelUp;
				m_DropTime *= m_NextLevelDropTimeMultiplier;
			}
			
			m_ScoreLabel.setText( std::to_string(m_Score) );
			
			m_GameOver = m_GameField.gameIsLost();
			
		}
		
		m_Timer.reset();
	}
}

void TetrisGameScene::handleKeyUpEvent(SDL_Keycode keycode) {
	
	if ( m_GameOver )
		return;
	
	switch (keycode) {
		
		case SDLK_SPACE:
			m_SpeedUp = false;
			break;
			
		default:
			break;
			
	}
}

void TetrisGameScene::handleKeyDownEvent(SDL_Keycode keycode) {
	
	switch (keycode) {
		case SDLK_ESCAPE:
			reset();
			changeScene( TetrisMainMenu::className() );
			break;
			
		default:
			break;
	}
	
	if( m_GameOver )
		return;
	
	switch (keycode) {
			
		case SDLK_UP :
			if ( m_GameField.canRotateTetromino(Tetromino::clockwise) )
				m_GameField.rotateTetromino(Tetromino::clockwise);
			break;
		
		case SDLK_DOWN :
			if ( m_GameField.canRotateTetromino(Tetromino::c_clockwise) )
				m_GameField.rotateTetromino(Tetromino::c_clockwise);
			break;
		
		case SDLK_RIGHT :
			if ( m_GameField.canMoveTetromino( Tetromino::right ) )
				m_GameField.moveTetromino( Tetromino::right );
			break;
			
		case SDLK_LEFT :
			if ( m_GameField.canMoveTetromino( Tetromino::left ) )
				m_GameField.moveTetromino( Tetromino::left );
			break;
			
		case SDLK_SPACE:
			m_SpeedUp = true;
			break;
			
		default:
			break;
			
	}
	
}

void TetrisGameScene::draw(){
	m_Background.draw();
	m_GameField.draw();
	m_ScoreLabel.draw();
	
	if (m_GameOver){
		m_GameOverLabel.draw();
		m_GameOverHintLabel.draw();
	}
}

void TetrisGameScene::setMode( TetrisGameField::modes mode ){
	m_GameField.setMode(mode);
	m_GameField.reset();
}

void TetrisGameScene::reset(){
	m_DropTime = m_BasicDropTime;
	m_SpeedUp = false;
	m_GameOver = false;
	m_Score = 0;
	m_ScoreLabel.setText( std::to_string( m_Score ) );
	m_Level = 0;
	m_RowsClearedOnThisLevel = 0;
	m_Timer.reset();
	m_GameField.reset();
}

TetrisGameScene::~TetrisGameScene(){
	
}