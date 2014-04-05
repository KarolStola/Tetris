//
//  TetrisWindow.h
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisWindow__
#define __Tetris__TetrisWindow__

#include <string>
#include "../include/SDL2/SDL.h"
#include "../exceptions/TetrisException.h"

class TetrisWindow {
	
public:
	TetrisWindow();
	inline SDL_Renderer* getRenderer()	{ return m_WindowRenderer; }
	inline void clear()					{ SDL_RenderClear( m_WindowRenderer); }
	inline void update()				{ SDL_RenderPresent( m_WindowRenderer ); }
	inline void resize(int w, int h)	{ SDL_SetWindowSize( m_Window, w, h); }
	inline int width()					{ return m_width; }
	inline int height()					{ return m_height; }
	virtual ~TetrisWindow();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_WindowRenderer;
	const int m_width;
	const int m_height;
};

#endif /* defined(__Tetris__TetrisWindow__) */