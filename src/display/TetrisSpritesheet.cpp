//
//  TetrisSprite.cpp
//  Tetris
//
//  Created by Karol Stola on 29.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisSpritesheet.h"

TetrisSpritesheet::TetrisSpritesheet(std::string file_name, SDL_Renderer* window_renderer)
	: TetrisDrawable(NULL, window_renderer)
{
	loadImage(file_name);
}

void TetrisSpritesheet::loadImage(std::string file_name){
	
	freeSpritesheet();
	
	SDL_Surface* temp_surface = NULL;
	temp_surface = IMG_Load(file_name.c_str());
	
	if (temp_surface == NULL)
		throw TetrisException( "Couldn't load image: " + file_name );
	
	m_Spritesheet = SDL_CreateTextureFromSurface( m_Renderer, temp_surface );
	if ( m_Spritesheet == NULL )
		throw TetrisException( "Could not convert surface to texture: " + file_name );
	
	SDL_FreeSurface( temp_surface );
	
	prepareSprites(file_name);
	
}

/**
 *	@TODO very ugly method - beautify it
 */
void TetrisSpritesheet::prepareSprites(std::string image_file_name){
	auto pos = image_file_name.find_last_of(".");
	image_file_name.replace(image_file_name.begin()+pos, image_file_name.end(), ".xml");
	std::ifstream file(image_file_name);
	if (!file)
		throw TetrisException("No xml file: " + image_file_name);
	std::string file_contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	rapidxml::xml_document<> file_tree;
	file_tree.parse<0>(&(file_contents[0]));
	
	auto root = file_tree.first_node();
	
	for(auto node = root->first_node(); node != NULL; node = node->next_sibling() ){
		
		auto attribute = node->first_attribute();
		std::string sprite_name = attribute->value();
		
		SDL_Rect clipping;
		attribute = attribute->next_attribute();
		clipping.x = std::stoi(attribute->value());
		attribute = attribute->next_attribute();
		clipping.y = std::stoi(attribute->value());
		attribute = attribute->next_attribute();
		clipping.w = std::stoi(attribute->value());
		attribute = attribute->next_attribute();
		clipping.h = std::stoi(attribute->value());
		
		m_Sprites[sprite_name] = new TetrisSprite(m_Spritesheet, m_Renderer, clipping);
	}
}

TetrisSprite& TetrisSpritesheet::getSprite(std::string name) {
	if ( m_Sprites.find(name) == m_Sprites.end() )
		throw TetrisException("No such sprite in spritesheet: " + name );
	
	return *(m_Sprites[name]);
}

void TetrisSpritesheet::freeSpritesheet(){
	if(m_Spritesheet != NULL){
		SDL_DestroyTexture(m_Spritesheet);
		m_Spritesheet = NULL;
	}
}

TetrisSpritesheet::~TetrisSpritesheet(){
	auto delete_sprites_function = [&]( SpriteContainerEntry entry){
		delete entry.second;
	};
	for_each(m_Sprites.begin(), m_Sprites.end(), delete_sprites_function);
	freeSpritesheet();
}
