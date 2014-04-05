//
//  TetrisWindow.cpp
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisWindow.h"

#include <iostream>
TetrisWindow::TetrisWindow()
	: m_Window{NULL}
	, m_WindowRenderer{NULL}
	, m_width{640}
	, m_height{480}
{
	m_Window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		m_width,
		m_height,
		SDL_WINDOW_SHOWN
	);
	
	if( m_Window == NULL )
		throw TetrisException( "Window could not be created." );
	
	m_WindowRenderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_PRESENTVSYNC);
	if( m_WindowRenderer == NULL )
		throw TetrisException("Window renderer could not be created.");
		
	SDL_SetRenderDrawColor( m_WindowRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	
}

TetrisWindow::~TetrisWindow(){
	if (m_WindowRenderer != NULL) {
		SDL_DestroyRenderer( m_WindowRenderer );
	}
	if (m_Window != NULL) {
		SDL_DestroyWindow( m_Window );
		m_Window = NULL;
	}
}