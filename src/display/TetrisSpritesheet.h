//
//  TetrisSpritesheet.h
//  Tetris
//
//  Created by Karol Stola on 29.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisSpritesheet__
#define __Tetris__TetrisSpritesheet__

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include "TetrisDrawable.h"
#include "TetrisSprite.h"
#include "../exceptions/TetrisException.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/rapidxml-1.13/rapidxml.hpp"

class TetrisSpritesheet : TetrisDrawable {

public:
	TetrisSpritesheet(std::string file_name, SDL_Renderer* window_renderer);
	void loadImage(std::string file_name);
	void freeSpritesheet();
	inline void draw()						{ SDL_RenderCopy( m_Renderer, m_Spritesheet, NULL, NULL ); }
	inline SDL_Texture* getSDL_Texture()	{ return m_Spritesheet; }
	inline SDL_Renderer* getSDL_Renderer()	{ return m_Renderer; }
	TetrisSprite& getSprite(std::string name);
	virtual ~TetrisSpritesheet();

private:
	void prepareSprites(std::string image_file_name);
	
	typedef std::map< std::string, TetrisSprite* > SpriteContainer;
	typedef std::pair< std::string, TetrisSprite* > SpriteContainerEntry;
	SpriteContainer m_Sprites;
	
};



#endif /* defined(__Tetris__TetrisSprite__) */
