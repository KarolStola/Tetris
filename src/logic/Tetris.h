//
//  Tetris.h
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__Tetris__
#define __Tetris__Tetris__

#include "../include/SDL2/SDL.h"
#include "scenes/TetrisSceneManager.h"
#include "events/TetrisEvent.h"
#include "events/TetrisEventHandler.h"
#include "../display/TetrisWindow.h"
#include "time/TetrisTimeManager.h"

class Tetris:  public TetrisEventHandler {

public:
	Tetris();
	void play();
	void handleEvent( TetrisEvent& event );
	void handleKeyUpEvent( SDL_Keycode keycode );
	void handleKeyDownEvent( SDL_Keycode keycode );
	void display();
	void updateLogic();
	virtual ~Tetris();

private:
	TetrisWindow m_Window;
	TetrisEvent m_Event;
	TetrisSceneManager m_SceneManager;
	bool m_Quit;
	//TetrisTimeManager m_TimeManager;
	
};

#endif /* defined(__Tetris__Tetris__) */
