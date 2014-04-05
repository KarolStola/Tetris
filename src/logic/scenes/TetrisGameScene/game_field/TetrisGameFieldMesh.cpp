//
//  TetrisGameFieldMesh.cpp
//  Tetris
//
//  Created by Karol Stola on 01.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisGameFieldMesh.h"

TetrisGameFieldMesh::TetrisGameFieldMesh()
	: m_Background{ TetrisBrick::create(TetrisBrick::stencil) }
	, m_Brick{NULL}
{

}


void TetrisGameFieldMesh::addBrick(TetrisBrick* brick){
	
	if (m_Brick != NULL)
		throw TetrisException("Trying to add Brick to mesh with the mesh being occupied -> memory leak.");
	
	m_Brick = brick;
	if ( m_Brick != NULL )
		m_Brick->move( m_Background->x(), m_Background->y() );
}

bool TetrisGameFieldMesh::hasBrick(){
	if (m_Brick != NULL)
		return true;
	else
		return false;
}

TetrisBrick* TetrisGameFieldMesh::popBrick(){
	TetrisBrick* brick = m_Brick;
	m_Brick = NULL;
	return brick;
}

void TetrisGameFieldMesh::deleteBrick(){
	if ( m_Brick != NULL ) {
		delete m_Brick;
		m_Brick = NULL;
	}
}

void TetrisGameFieldMesh::draw(){
	m_Background->draw();
	if (m_Brick != NULL)
		m_Brick->draw();
}

void TetrisGameFieldMesh::setPosition(int x, int y){
	m_Background->move(x,y);
	if ( m_Brick != NULL )
		m_Brick->move(x,y);
}

TetrisGameFieldMesh::~TetrisGameFieldMesh(){
	
	delete m_Background;
	if (m_Brick != NULL)
		delete m_Brick;

}