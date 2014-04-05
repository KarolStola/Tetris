//
//  TetrisGraphicsInitializer.cpp
//  Tetris
//
//  Created by Karol Stola on 29.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisGraphicsInitializer.h"

TetrisGraphicsInitializer TetrisGraphicsInitializer::instance;

TetrisGraphicsInitializer::TetrisGraphicsInitializer(){
	try {
		
		if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
			throw TetrisException("Could not initialize SDL.");
		
		int img_flags = IMG_INIT_PNG;
		if( !(IMG_Init( img_flags ) & img_flags) )
			throw TetrisException("Could not initialize SDL_image.");
		
		 if( TTF_Init() == -1 )
			 throw TetrisException("Could not initialize SDL_ttf.");
		
	} catch (TetrisException& e) {
		
		std::cerr << e.what();
		throw e;
		
	}
}

TetrisGraphicsInitializer::~TetrisGraphicsInitializer(){
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}