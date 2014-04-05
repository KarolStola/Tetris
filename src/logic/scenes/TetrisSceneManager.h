//
//  TetrisSceneManager.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisSceneManager__
#define __Tetris__TetrisSceneManager__

#include <iostream>
#include <map>
#include "../../include/SDL2/SDL.h"
#include "TetrisScene.h"
#include "TetrisMainMenu/TetrisMainMenu.h"
#include "TetrisGameScene/TetrisGameScene.h"
#include "../events/TetrisEventHandler.h"
#include "../../display/TetrisWindow.h"

class TetrisSceneManager: public TetrisEventHandler {
	
public:
	TetrisSceneManager(TetrisWindow* window);
	
	void changeScene( const std::string scene_name );
	TetrisScene::ChangeSceneCallback getChangeSceneCallback();
	void addScene(TetrisScene* new_scene);
	virtual void handleEvent( TetrisEvent& event )					{};
	inline virtual void handleKeyUpEvent( SDL_Keycode keycode )		{ m_CurrentScene->handleKeyUpEvent(keycode); }
	inline virtual void handleKeyDownEvent( SDL_Keycode keycode )	{ m_CurrentScene->handleKeyDownEvent(keycode); }
	inline void callDrawer()										{ m_CurrentScene->draw(); }
	inline void callLogicUpdater()									{ m_CurrentScene->updateLogic(); }
	
	virtual ~TetrisSceneManager();
	
private:
	//TetrisWindow* m_Window;
	TetrisScene* m_CurrentScene;
	typedef std::map< std::string, TetrisScene* > SceneContainer;
	typedef std::pair< std::string, TetrisScene* > SceneContainerEntry;
	SceneContainer m_SceneContainer;
	
};


#endif /* defined(__Tetris__TetrisSceneManager__) */
