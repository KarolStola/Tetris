//
//  TetrisTimeManager.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisTimeManager__
#define __Tetris__TetrisTimeManager__

#include <iostream>
#include "TetrisTimer.h"

class TetrisTimeManager{
	
public:
	TetrisTimeManager();
	void manageFPS();
	
private:
	TetrisTimer m_Timer;
	const float m_Second = 1000.f;
	int m_countedFrames;
	
};

#endif /* defined(__Tetris__TetrisTimeManager__) */
