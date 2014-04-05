//
//  TetrisDrawable.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisDrawable__
#define __Tetris__TetrisDrawable__

#include <iostream>
#include "../include/SDL2/SDL.h"

class TetrisDrawable {
	
public:
	TetrisDrawable(SDL_Texture* spritesheet, SDL_Renderer* renderer);
	virtual inline void draw()	= 0;
	virtual ~TetrisDrawable()	{}
	
protected:
	SDL_Texture* m_Spritesheet;
	SDL_Renderer* m_Renderer;
	
};

#endif /* defined(__Tetris__TetrisDrawable__) */
