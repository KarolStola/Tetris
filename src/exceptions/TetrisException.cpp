//
//  TetrisException.cpp
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include <cstring>
#include "TetrisException.h"

TetrisException::TetrisException(const std::string exception_message)
	: m_ExceptionMessage(exception_message)
{
	const char * sdl_error = SDL_GetError();
	
	if( strlen(sdl_error) != 0 ){
		m_ExceptionMessage += "\nSDL_Exception: ";
		m_ExceptionMessage += sdl_error;
	}
	
	const char * img_error = IMG_GetError();
	
	if( strlen(img_error) != 0 ){
		m_ExceptionMessage += "\nIMG_Exception: ";
		m_ExceptionMessage += img_error;
	}
	
	const char * ttf_error = TTF_GetError();
	
	if( strlen(ttf_error) != 0 ){
		m_ExceptionMessage += "\nTTF_Exception: ";
		m_ExceptionMessage += ttf_error;
	}
	
	m_ExceptionMessage += "\n";
}