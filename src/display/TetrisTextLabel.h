//
//  TetrisTextLabel.h
//  Tetris
//
//  Created by Karol Stola on 03.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisTextLabel__
#define __Tetris__TetrisTextLabel__

#include <iostream>
#include <string>
#include "../include/SDL2/SDL_ttf.h"
#include "TetrisGraphicsInitializer.h"
#include "../exceptions/TetrisException.h"

class TetrisTextLabel {
	
public:
	TetrisTextLabel(SDL_Renderer* renderer, const std::string& text = " ");
	void setText(const std::string& text);
	void clearLabel();
	void setPosition(SDL_Point position);
	void setFontSize(int font_size);
	void setUnderlineOn();
	void setUnderlineOff();
	int width()							{ return m_Size.w; }
	int height()						{ return m_Size.h; }
	void draw();
	~TetrisTextLabel();
	
private:
	void loadFont(const std::string& font_name);
	std::string m_DefaultFontName;
	std::string m_Text;
	void clearFont();
	SDL_Texture* m_Label;
	SDL_Texture* m_LabelStroke;
	TTF_Font* m_Font;
	TTF_Font* m_StrokeFont;
	SDL_Renderer* m_Renderer;
	SDL_Color m_TextColor;
	SDL_Color m_StrokeColor;
	SDL_Rect m_Size;
	int m_FontSize;
	int m_StrokeSize;
};

#endif /* defined(__Tetris__TetrisTextLabel__) */
