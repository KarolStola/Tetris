//
//  TetrisException.h
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisException__
#define __Tetris__TetrisException__

#include <exception>
#include <string>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_ttf.h"

class TetrisException: public std::exception{
public:
	TetrisException(const std::string exception_message);
	const std::string what() {return m_ExceptionMessage;}
private:
	std::string m_ExceptionMessage;
};

#endif /* defined(__Tetris__TetrisException__) */
