//
//  TetrisEvent.h
//  Tetris
//
//  Created by Karol Stola on 29.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisEvent__
#define __Tetris__TetrisEvent__

#include <iostream>
#include "../../include/SDL2/SDL.h"

class TetrisEvent{
	
public:
	bool getEvent() { return (bool) SDL_PollEvent( & m_Event ); }
	SDL_EventType type() { return (SDL_EventType)m_Event.type; }
	SDL_Keycode keyCode() { return m_Event.key.keysym.sym; }
	
private:
	SDL_Event m_Event;
	
};

#endif /* defined(__Tetris__TetrisEvent__) */
