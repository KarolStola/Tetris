//
//  TetrisScene.cpp
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisScene.h"

TetrisScene::TetrisScene( TetrisWindow* window, ChangeSceneCallback callback )
	:TetrisDrawer(window)
	,changeScene{callback}
{
	
}

const std::string TetrisScene::decodeName(const std::string& name){
	int status;
	const char * coded_name = name.c_str();
	std::string decoded_name = abi::__cxa_demangle(coded_name, 0, 0, &status);
	return decoded_name;
}

const std::string TetrisScene::name(){
	return decodeName(
		typeid(*this).name()
	);
}