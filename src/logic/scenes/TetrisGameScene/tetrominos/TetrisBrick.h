//
//  TetrisBrick.h
//  Tetris
//
//  Created by Karol Stola on 31.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisBrick__
#define __Tetris__TetrisBrick__

#include <iostream>
#include <string>
#include "../../../../display/TetrisSpritesheet.h"
#include "../../../../display/TetrisSprite.h"
#include "../../../../exceptions/TetrisException.h"

class TetrisBrick : public TetrisSprite {
	
public:
	
	TetrisBrick(TetrisBrick& other);
	
	enum colors {
		green_dark,
		green_light,
		magenta,
		orange,
		red,
		stencil,
		violet,
		yellow,
		_end_
	};
	
	static void registerSpritesheet(TetrisSpritesheet* spritesheet);
	static TetrisBrick* create(colors color);
	static int brickWidth()				{ return width; }
	static int brickHeight()			{ return height; };
	
	
private:
	static const std::string m_BrickIdPrefix;
	static TetrisSpritesheet* m_Spritesheet;
	static std::map< colors, std::string > m_BrickDict;
	static int width;
	static int height;
	
};

#endif /* defined(__Tetris__TetrisBrick__) */
