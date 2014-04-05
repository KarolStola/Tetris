//
//  TetrisTextLabel.cpp
//  Tetris
//
//  Created by Karol Stola on 03.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisTextLabel.h"

TetrisTextLabel::TetrisTextLabel(SDL_Renderer* renderer, const std::string& text)
	: m_Label { NULL }
	, m_LabelStroke{ NULL }
	, m_Font {NULL}
	, m_StrokeFont{ NULL }
	, m_Renderer {renderer}
	, m_Size {0,0,0,0}
	, m_FontSize {28}
	, m_TextColor {145,11,7}
	, m_StrokeColor {255,187,0}
	, m_Text{" "}
	, m_DefaultFontName {
		/*"fonts/GILGON__.ttf"*/
		"assets/fonts/Foo.ttf"
	}
	, m_StrokeSize{2}
{
	loadFont(m_DefaultFontName);
	setText( text );
}

void TetrisTextLabel::loadFont(const std::string& font_name){
	clearFont();
	m_Font = TTF_OpenFont(font_name.c_str() , m_FontSize );
	if ( m_Font == NULL )
		throw TetrisException("Could not load font: " + font_name);
	
	m_StrokeFont = TTF_OpenFont(font_name.c_str() , m_FontSize );
	TTF_SetFontOutline(m_Font, m_StrokeSize);
}

void TetrisTextLabel::setText(const std::string& text){
	
	m_Text = text;
	
	clearLabel();
	
	SDL_Surface* text_surface = TTF_RenderText_Blended( m_Font, m_Text.c_str(), m_TextColor );
    if( text_surface == NULL )
    	throw TetrisException("Unable to create text surface: " + text);
	
	SDL_Surface* stroke_surface = TTF_RenderText_Blended( m_StrokeFont, m_Text.c_str(), m_StrokeColor );
	if( text_surface == NULL )
    	throw TetrisException("Unable to create stroke surface: " + text);
	
	m_Label = SDL_CreateTextureFromSurface( m_Renderer, text_surface );
    m_LabelStroke = SDL_CreateTextureFromSurface( m_Renderer, stroke_surface );
	
	if( m_Label == NULL )
		throw TetrisException("Could not create text label from surface: " + text);
	if( m_LabelStroke == NULL )
		throw TetrisException("Could not create text stroke from surface: " + text);
			
	m_Size.w = text_surface->w;
	m_Size.h = text_surface->h;
	
	SDL_FreeSurface( text_surface );
	SDL_FreeSurface( stroke_surface );
    
}

void TetrisTextLabel::setFontSize(int font_size){
	if (font_size != m_FontSize) {
		m_FontSize = font_size;
		loadFont(m_DefaultFontName);
		setText(m_Text);
	}
}

void TetrisTextLabel::setUnderlineOn(){
	TTF_SetFontStyle(m_Font, TTF_STYLE_UNDERLINE);
	setText(m_Text);
}

void TetrisTextLabel::setUnderlineOff(){
	TTF_SetFontStyle(m_Font, TTF_STYLE_NORMAL);
	setText(m_Text);
}

void TetrisTextLabel::clearLabel(){
	if(m_Label != NULL){
		SDL_DestroyTexture(m_Label);
		m_Label = NULL;
	}
	if(m_LabelStroke != NULL){
		SDL_DestroyTexture(m_LabelStroke);
		m_LabelStroke = NULL;
	}
}

void TetrisTextLabel::draw() {
	SDL_Rect stroke_size = m_Size;
	stroke_size.y -= m_StrokeSize;
	
	SDL_RenderCopy( m_Renderer, m_LabelStroke, NULL, &m_Size );
	SDL_RenderCopy( m_Renderer, m_Label, NULL, &m_Size );
}

void TetrisTextLabel::setPosition(SDL_Point position){
	m_Size.x = position.x;
	m_Size.y = position.y;
}

void TetrisTextLabel::clearFont(){
	if(m_Font != NULL){
		TTF_CloseFont(m_Font);
		m_Font = NULL;
	}
	if ( m_StrokeFont != NULL ) {
		TTF_CloseFont(m_StrokeFont);
		m_StrokeFont = NULL;
	}
}

TetrisTextLabel::~TetrisTextLabel(){
	clearLabel();
	clearFont();
}
