//
//  TetrisMainMenu.h
//  Tetris
//
//  Created by Karol Stola on 03.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisMainMenu__
#define __Tetris__TetrisMainMenu__

#include <iostream>
#include <vector>
#include <map>
#include "../TetrisSceneBase.h"
#include "../TetrisGameScene/TetrisGameScene.h"
#include "../TetrisGameScene/game_field/TetrisGameField.h"
#include "../../../display/TetrisSprite.h"
#include "../../../display/TetrisSpritesheet.h"
#include "../../../display/TetrisTextLabel.h"

class TetrisMainMenu : public TetrisSceneBase<TetrisMainMenu> {

public:
	TetrisMainMenu( TetrisWindow* window, ChangeSceneCallback callback );
	virtual void handleKeyUpEvent( SDL_Keycode keycode );
	virtual void handleKeyDownEvent( SDL_Keycode keycode );
	TetrisGameField::modes getSelectedOption()					{ return m_MenuOptionsDict[ m_SelectedOption ]; }
	virtual void updateLogic();
	virtual void draw();
	virtual ~TetrisMainMenu();
	
private:
	TetrisSpritesheet m_Spritesheet;
	TetrisSprite m_Background;
	TetrisTextLabel m_MainTextLabel;
	TetrisTextLabel m_Watermark;
	std::vector< TetrisTextLabel * > m_MenuOptions;
	std::map< int, TetrisGameField::modes >  m_MenuOptionsDict;
	int m_SelectedOption;

};

#endif /* defined(__Tetris__TetrisMainMenu__) */
