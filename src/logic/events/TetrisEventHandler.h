//
//  TetrisEventHandler.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisEventHandler__
#define __Tetris__TetrisEventHandler__

#include <iostream>
#include "TetrisEvent.h"

class TetrisEventHandler {
	
public:
	virtual void handleEvent( TetrisEvent& event ) = 0;
	virtual void handleKeyUpEvent( SDL_Keycode keycode ) = 0;
	virtual void handleKeyDownEvent( SDL_Keycode keycode ) = 0;
	
};

#endif /* defined(__Tetris__TetrisEventHandler__) */
