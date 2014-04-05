//
//  TetrisBrick.cpp
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisBrick.h"

const std::string TetrisBrick::m_BrickIdPrefix = "game_object_tile_";

TetrisSpritesheet* TetrisBrick::m_Spritesheet = NULL;

std::map < TetrisBrick::colors , std::string > TetrisBrick::m_BrickDict =
{
	{green_dark, "green_dark"},
	{green_light, "green_light"},
	{magenta, "magenta"},
	{orange, "orange"},
	{red, "red"},
	{stencil, "stencil"},
	{violet, "violet"},
	{yellow, "yellow"}
};

int TetrisBrick::width;
int TetrisBrick::height;


void TetrisBrick::registerSpritesheet(TetrisSpritesheet* spritesheet){
	m_Spritesheet = spritesheet;
	int sizes[colors::_end_][2];
	
	for (int i = 0; i < colors::_end_; i++) {
		sizes[i][0] = spritesheet->getSprite( m_BrickIdPrefix + m_BrickDict[(colors)i] ).width();
		sizes[i][1] = spritesheet->getSprite( m_BrickIdPrefix + m_BrickDict[(colors)i] ).height();
		
		if (i != 0)
			if (sizes[i][0] != sizes[i-1][0]
				&& sizes[i][1] != sizes[i-1][1])
				throw TetrisException("Tetris bricks are not the same size.");
	}
	
	width = sizes[0][0];
	height = sizes[0][1];
}

TetrisBrick* TetrisBrick::create(colors color){
	
	std::string ex_message = "TetrisBrick creation failed: ";
	
	auto it = m_BrickDict.find(color);
	if (it == m_BrickDict.end())
		throw TetrisException( ex_message + "no such brick color." );
	
	if (m_Spritesheet == NULL)
		throw TetrisException( ex_message + "spritesheet not registered");
	
	std::string sprite_name = m_BrickIdPrefix + it->second;
	
	TetrisBrick* created = new TetrisBrick( static_cast< TetrisBrick& > (m_Spritesheet->getSprite(sprite_name)) );
	
	return created;
}

TetrisBrick::TetrisBrick(TetrisBrick& other)
	:TetrisSprite( static_cast<TetrisSprite&>(other) )
{
	
}