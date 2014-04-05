//
//  TetrisSprite.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisSprite__
#define __Tetris__TetrisSprite__

#include <iostream>
#include "TetrisDrawable.h"
#include "../include/SDL2/SDL.h"

class TetrisSprite : public TetrisDrawable {
	
public:
	TetrisSprite(SDL_Texture* spritesheet, SDL_Renderer* renderer, SDL_Rect sheet_clipping);
	TetrisSprite( const TetrisSprite& other );
	void move(int x, int y);
	virtual inline void draw()	{ SDL_RenderCopy( m_Renderer, m_Spritesheet, & m_SpritesheetClipping, & m_DestinationField); }
	virtual inline int x()		{ return m_DestinationField.x; }
	virtual inline int y()		{ return m_DestinationField.y; }
	virtual inline int width()	{ return m_DestinationField.w; }
	virtual inline int height()	{ return m_DestinationField.h; }
	
private:
	SDL_Rect m_SpritesheetClipping;
	SDL_Rect m_DestinationField;
	
};


#endif /* defined(__Tetris__TetrisSprite__) */
