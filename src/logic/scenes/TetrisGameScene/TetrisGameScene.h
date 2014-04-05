//
//  TetrisGameScene.h
//  Tetris
//
//  Created by Karol Stola on 30.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisGameScene__
#define __Tetris__TetrisGameScene__

#include <iostream>
#include <string>
#include <cstdlib>
#include "game_field/TetrisGameField.h"
#include "tetrominos/Tetrominos.h"
#include "tetrominos/TetrisBrick.h"
#include "../TetrisSceneBase.h"
#include "../TetrisMainMenu/TetrisMainMenu.h"
#include "../../time/TetrisTimer.h"
#include "../../../display/TetrisTextLabel.h"
#include "../../../display/TetrisSprite.h"
#include "../../../display/TetrisSpritesheet.h"

class TetrisGameScene: public TetrisSceneBase<TetrisGameScene> {
	
public:
	TetrisGameScene( TetrisWindow* window, ChangeSceneCallback callback );
	void handleKeyUpEvent(SDL_Keycode keycode);
	void handleKeyDownEvent(SDL_Keycode keycode);
	void draw();
	void updateLogic();
	void setMode( TetrisGameField::modes mode );
	void reset();
	virtual ~TetrisGameScene();
	
private:
	TetrisTimer m_Timer;
	const int m_BasicDropTime;
	int m_DropTime;
	float m_SpeedUpMultiplier;
	float m_NextLevelDropTimeMultiplier;
	bool m_SpeedUp;
	bool m_GameOver;
	TetrisSpritesheet m_Spritesheet;
	TetrisSprite m_Background;
	TetrisGameField m_GameField;
	TetrisTextLabel m_ScoreLabel;
	TetrisTextLabel m_GameOverLabel;
	TetrisTextLabel m_GameOverHintLabel;
	
	unsigned int m_Score;
	std::vector<int> m_ScoreForRowsCleared;
	int m_Level;
	int m_RowsClearedOnThisLevel;
	int m_RowsNeededToLevelUp;
};

#endif /* defined(__Tetris__TetrisGameScene__) */
