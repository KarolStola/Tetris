//
//  TetrisSceneBase.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisSceneBase__
#define __Tetris__TetrisSceneBase__

#include <iostream>
#include "TetrisScene.h"

template <class T>
class TetrisSceneBase : public TetrisScene{
	
public:
	TetrisSceneBase( TetrisWindow* window, ChangeSceneCallback callback );
	static const std::string className();
	const std::string name()		{ return TetrisSceneBase<T>::className(); }
	virtual ~TetrisSceneBase()				{};
	
private:
	
	
};

template <class T>
const std::string TetrisSceneBase<T>::className(){
	return decodeName(
		typeid(TetrisSceneBase<T>).name()
	);
}

template<class T>
TetrisSceneBase<T>::TetrisSceneBase( TetrisWindow* window, ChangeSceneCallback callback )
	:TetrisScene(window, callback)
{}

#endif /* defined(__Tetris__TetrisSceneBase__) */
