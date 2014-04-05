//
//  TetrisGameFieldMesh.h
//  Tetris
//
//  Created by Karol Stola on 01.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisGameFieldMesh__
#define __Tetris__TetrisGameFieldMesh__

#include <iostream>
#include "../tetrominos/TetrisBrick.h"
#include "../../../../exceptions/TetrisException.h"

class TetrisGameFieldMesh {
	
public:
	TetrisGameFieldMesh();
	void draw();
	void addBrick(TetrisBrick* brick);
	TetrisBrick* popBrick();
	void setPosition(int x, int y);
	void deleteBrick();
	bool hasBrick();
	~TetrisGameFieldMesh();
	
private:
	TetrisBrick* m_Background;
	TetrisBrick* m_Brick;
	
};

#endif /* defined(__Tetris__TetrisGameFieldMesh__) */
