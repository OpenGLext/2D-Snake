#pragma once
#include "D:\\Движки\freeglut-2.8.1\include\GL\freeglut.h"
#include <iostream>
#include <time.h>
#include "Quad.h"
using namespace std;

namespace Fruct
{
	
class Fructs_ 
{

public:

	Fructs_(int& N, int& M, int& Scale_, int& startX, int& startY);
	Fructs_();

	void DrawApple();
    void New();
	static float PosFructX;
	static float PosFructY;
private:
	inline void Fructs_::box_(float x1, float y1, float x2, float y2);
	
    float frame;
	float depthFruct;
	bool isActive;
    int sizeWall;
	int m_scale;
	int m_N,m_M;

 
} ;
}

