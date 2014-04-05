//
//  TetrisScene.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisScene__
#define __Tetris__TetrisScene__

#include <iostream>
#include <string>
#include <functional>
#include <cxxabi.h>
#include "../../include/SDL2/SDL.h"
#include "../events/TetrisEventHandler.h"
#include "../../display/TetrisWindow.h"
#include "../../display/TetrisDrawer.h"

class TetrisScene
	: public TetrisEventHandler
	, public TetrisDrawer
{
public:
	typedef std::function< void(const std::string) > ChangeSceneCallback;
	TetrisScene( TetrisWindow* window, ChangeSceneCallback callback );
	virtual const std::string name();
	virtual void updateLogic() = 0;
	virtual void handleEvent( TetrisEvent& event )	{}
	virtual ~TetrisScene()							{};
	
protected:
	ChangeSceneCallback changeScene;
	static const std::string decodeName(const std::string& name);

};

#endif /* defined(__Tetris__TetrisScene__) */
