//
//  TetrisTimer.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisTimer.h"

TetrisTimer::TetrisTimer()
	:m_StartTicks{0}
	,m_PausedTicks{0}
	,m_Paused{false}
	,m_Started{false}
{
	
}

void TetrisTimer::start(){
	m_Started = true;
	
	m_Paused = false;
	
	m_StartTicks = SDL_GetTicks();
	m_PausedTicks = 0;
}

void TetrisTimer::stop(){
	m_Started = false;
	
	m_Paused = false;
	
	m_StartTicks = 0;
	m_PausedTicks = 0;
}

void TetrisTimer::pause(){
	
	if( m_Started && !m_Paused ){
		m_Paused = true;
		
		m_PausedTicks = SDL_GetTicks() - m_StartTicks;
		m_StartTicks = 0;
	}
	
}

void TetrisTimer::unpause(){
	if( m_Started && m_Paused ){
		m_Paused = false;
		
		m_StartTicks = SDL_GetTicks() - m_PausedTicks;
		m_PausedTicks = 0;
	}
}

Uint32 TetrisTimer::getTicks()
{
	Uint32 time = 0;
	
	if( m_Started ){
		if( m_Paused ){
			time = m_PausedTicks;
		}
		else {
			time = SDL_GetTicks() - m_StartTicks;
		}
	}
	
	return time;
}

