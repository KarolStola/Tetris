//
//  Tetris.cpp
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "Tetris.h"

Tetris::Tetris()
	: m_Quit{ false }
	, m_SceneManager { & m_Window }
{
	
}

void Tetris::play(){
	while (! m_Quit) {
		while ( m_Event.getEvent() ) {
			handleEvent( m_Event );
		}
		updateLogic();
		display();
		//m_TimeManager.manageFPS();
	}
}

void Tetris::updateLogic(){
	m_SceneManager.callLogicUpdater();
}

void Tetris::handleEvent( TetrisEvent& event ){
	
	switch ( event.type() ) {
		
		case SDL_QUIT:
			m_Quit = true;
			break;
			
		case SDL_KEYDOWN:
			handleKeyDownEvent( event.keyCode() );
			break;
		
		case SDL_KEYUP:
			handleKeyUpEvent( event.keyCode() );
			break;
			
		default:
			break;
	}
	
}

void Tetris::handleKeyDownEvent( SDL_Keycode keycode ){
	m_SceneManager.handleKeyDownEvent(keycode);
}

void Tetris::handleKeyUpEvent( SDL_Keycode keycode ){
	m_SceneManager.handleKeyUpEvent(keycode);
}

void Tetris::display(){
	m_Window.clear();
	m_SceneManager.callDrawer();
	m_Window.update();
}

Tetris::~Tetris(){
	
}