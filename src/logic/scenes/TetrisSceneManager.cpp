//
//  TetrisSceneManager.cpp
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisSceneManager.h"

TetrisSceneManager::TetrisSceneManager(TetrisWindow* window)
	//: m_Window{window}
	: m_CurrentScene{NULL}
{
	addScene( new TetrisGameScene( window, getChangeSceneCallback() ) );
	addScene( new TetrisMainMenu( window, getChangeSceneCallback() ) );
	
	changeScene(TetrisMainMenu::className());
}

void TetrisSceneManager::addScene(TetrisScene* new_scene){
	m_SceneContainer[new_scene->name()] = new_scene;
}

void TetrisSceneManager::changeScene( const std::string scene_name ){
	
	auto it = m_SceneContainer.find(scene_name);
	if (it == m_SceneContainer.end())
		throw TetrisException("Requested for scene not known to SceneManager.");
	
	auto next_scene = it->second;
	
	if ( m_CurrentScene != NULL ) {
		if ( m_CurrentScene->name() == TetrisMainMenu::className() ){
			if ( next_scene->name() == TetrisGameScene::className() ) {
				auto mode = static_cast< TetrisMainMenu * >(m_CurrentScene)->getSelectedOption();
				static_cast< TetrisGameScene * >(next_scene)->setMode(mode);
			}
		}
	}
	
	m_CurrentScene = next_scene;
	
	
	
}

TetrisScene::ChangeSceneCallback TetrisSceneManager::getChangeSceneCallback() {
	return std::bind(
		& TetrisSceneManager::changeScene,
		this,
		std::placeholders::_1
	);
}

TetrisSceneManager::~TetrisSceneManager(){
	auto delete_scenes_function = [&]( SceneContainerEntry entry){
		delete entry.second;
	};
	for_each(m_SceneContainer.begin(), m_SceneContainer.end(), delete_scenes_function);
}