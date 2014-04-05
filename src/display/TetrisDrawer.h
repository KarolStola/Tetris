//
//  TetrisDrawer.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisDrawer__
#define __Tetris__TetrisDrawer__

#include <iostream>
#include "TetrisAssetConsumer.h"
#include "TetrisWindow.h"

class TetrisDrawer : public TetrisAssetConsumer{
	
public:
	TetrisDrawer(TetrisWindow* window);
	virtual void draw() = 0;
	
protected:
	TetrisWindow* m_Window;
	const std::string m_SpritesheetLocation;
	
};

#endif /* defined(__Tetris__TetrisDrawable__) */
