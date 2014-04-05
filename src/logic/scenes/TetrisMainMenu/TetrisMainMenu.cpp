//
//  TetrisMainMenu.cpp
//  Tetris
//
//  Created by Karol Stola on 03.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisMainMenu.h"

TetrisMainMenu::TetrisMainMenu( TetrisWindow* window, ChangeSceneCallback callback )
	: TetrisSceneBase(window, callback)
	, m_Spritesheet{ m_SpritesheetLocation + "tetris_main_001.png", m_Window->getRenderer() }
	, m_Background{ m_Spritesheet.getSprite("bg_main") }
	, m_MainTextLabel{ m_Window->getRenderer(), "choose game mode:" }
	, m_Watermark(m_Window->getRenderer(), "created by Karol Stola")
	, m_SelectedOption{0}
{
	m_MainTextLabel.setFontSize(40);
	
	SDL_Point position;
	position.x = m_Window->width() / 2;
	position.x -= m_MainTextLabel.width() / 2;
	position.x += 50;
	position.y = 100;
	m_MainTextLabel. setPosition( position );
	
	m_Watermark.setFontSize(35);
	m_Watermark.setPosition( {(m_Window->width()/2)-150, m_Window->height() + 75} );
	
	m_MenuOptions.push_back( new TetrisTextLabel( m_Window->getRenderer(), "classic" ) );
	position.x = m_Window->width() / 2;
	position.x -= m_MenuOptions[0]->width() / 2;
	position.x += 20;
	position.y = 200;
	m_MenuOptions[0]->setFontSize(40);
	m_MenuOptions[0]->setPosition(position);
	m_MenuOptions[0]->setUnderlineOn();
	
	m_MenuOptionsDict[ 0 ] = TetrisGameField::classic;
	
	m_MenuOptions.push_back( new TetrisTextLabel( m_Window->getRenderer(), "crazy" ) );
	position.x = m_Window->width() / 2;
	position.x -= m_MenuOptions[1]->width() / 2;
	position.x += 25;
	position.y = 250;
	m_MenuOptions[1]->setFontSize(40);
	m_MenuOptions[1]->setPosition(position);
	
	m_MenuOptionsDict[ 1 ] = TetrisGameField::crazy;
}

void TetrisMainMenu::handleKeyUpEvent( SDL_Keycode keycode ){
	
}

void TetrisMainMenu::handleKeyDownEvent (SDL_Keycode keycode){
	
	switch (keycode) {
		case SDLK_UP :
			if (m_SelectedOption > 0) {
				m_MenuOptions[ m_SelectedOption ]->setUnderlineOff();
				m_SelectedOption--;
				m_MenuOptions[ m_SelectedOption ]->setUnderlineOn();
			}
			break;
			
		case SDLK_DOWN :
			if ( m_SelectedOption < m_MenuOptions.size() - 1 ) {
				m_MenuOptions[ m_SelectedOption ]->setUnderlineOff();
				m_SelectedOption++;
				m_MenuOptions[ m_SelectedOption ]->setUnderlineOn();
			}
			break;
			
		case SDLK_RETURN :
			changeScene(TetrisGameScene::className());
			break;
			
		default:
			break;
	}
}

void TetrisMainMenu::updateLogic(){
	
}

void TetrisMainMenu::draw(){
	
	m_Background.draw();
	m_MainTextLabel.draw();
	m_Watermark.draw();
	for (auto& option : m_MenuOptions)
		option->draw();

}

TetrisMainMenu::~TetrisMainMenu(){
	for (auto& option : m_MenuOptions)
		delete option;
}