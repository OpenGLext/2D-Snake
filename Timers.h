#pragma once
#include "StructData.h"

void glutTimer(int id)

{
	
	
	glutPostRedisplay();
	glutTimerFunc(Data::IntervalTimer,glutTimer,id);

}


