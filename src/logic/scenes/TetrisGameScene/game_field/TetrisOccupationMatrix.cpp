//
//  TetrisOccupationMatrix.cpp
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include "TetrisOccupationMatrix.h"

TetrisOccupationMatrix::TetrisOccupationMatrix(unsigned long size)
{
	m_Matrix.resize(size);
	for (auto& row: m_Matrix)
		row.resize(size, false);
}
