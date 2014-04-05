//
//  TetrisTimeManager.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisTimeManager.h"

TetrisTimeManager::TetrisTimeManager()
	:m_countedFrames{0}
{
	m_Timer.start();
}

void TetrisTimeManager::manageFPS(){
	
	float avgFPS = m_countedFrames / ( m_Timer.getTicks() / m_Second );
	
	if( avgFPS > 2000000 ){
		avgFPS = 0;
	}
	
	m_countedFrames++;
	std::cout << avgFPS << std::endl;
}
