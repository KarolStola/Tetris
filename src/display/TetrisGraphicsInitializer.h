//
//  TetrisGraphicsInitializer.h
//  Tetris
//
//  Created by Karol Stola on 29.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisGraphicsInitializer__
#define __Tetris__TetrisGraphicsInitializer__

#include <iostream>
#include "../exceptions/TetrisException.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_ttf.h"

class TetrisGraphicsInitializer{

public:
	~TetrisGraphicsInitializer();

private:
	TetrisGraphicsInitializer();
	static TetrisGraphicsInitializer instance;

};

#endif /* defined(__Tetris__TetrisGraphicsInitializer__) */
