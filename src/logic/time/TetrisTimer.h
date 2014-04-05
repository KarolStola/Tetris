//
//  TetrisTimer.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisTimer__
#define __Tetris__TetrisTimer__

#include <iostream>
#include "../../include/SDL2/SDL.h"

class TetrisTimer {
public:
	TetrisTimer();
	
	void start();
	void stop();
	void pause();
	void unpause();
	void reset()		{ stop(); start(); }
	bool isStarted()	{ return m_Started; }
	bool isPaused()		{ return m_Paused && m_Started; }
	Uint32 getTicks();
	
private:
	Uint32 m_StartTicks;
	Uint32 m_PausedTicks;
	bool m_Paused;
	bool m_Started;
	const int m_Second = 1000;
};

#endif /* defined(__Tetris__TetrisTimer__) */
