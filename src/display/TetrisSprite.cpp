//
//  TetrisSprite.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisSprite.h"


TetrisSprite::TetrisSprite(SDL_Texture* spritesheet, SDL_Renderer* renderer, SDL_Rect sheet_clipping)
	: TetrisDrawable(
		spritesheet,
		renderer
	)
	, m_SpritesheetClipping(sheet_clipping)
	, m_DestinationField{ 0, 0, sheet_clipping.w, sheet_clipping.h}
{
	
}

TetrisSprite::TetrisSprite( const TetrisSprite& other )
	: TetrisDrawable(
		other.m_Spritesheet,
		other.m_Renderer
	)
	, m_SpritesheetClipping( other.m_SpritesheetClipping )
	, m_DestinationField (other.m_DestinationField )
{
	//std::cout << "bla" << std::endl;
}

void TetrisSprite::move(int x, int y){
	m_DestinationField.x = x;
	m_DestinationField.y = y;
}