//
//  TetrisOccupationMatrix.h
//  Tetris
//
//  Created by Karol Stola on 02.04.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#ifndef __Tetris__TetrisOccupationMatrix__
#define __Tetris__TetrisOccupationMatrix__

#include <iostream>
#include <vector>

class TetrisOccupationMatrix {
	
public:
	TetrisOccupationMatrix(unsigned long size);
	TetrisOccupationMatrix(TetrisOccupationMatrix& other)			{ m_Matrix = other.m_Matrix; }
	TetrisOccupationMatrix(TetrisOccupationMatrix&& other)			{ std::swap(m_Matrix, other.m_Matrix); }
	TetrisOccupationMatrix& operator=(TetrisOccupationMatrix other)	{ std::swap(m_Matrix, other.m_Matrix); return *this; }
	std::vector<bool>& operator[](int i)							{ return m_Matrix[i]; }
	unsigned long size()											{ return m_Matrix.size(); }
	
private:
	typedef std::vector < std::vector < bool > > Matrix;
	Matrix m_Matrix;
	
};
#endif /* defined(__Tetris__TetrisOccupationMatrix__) */
