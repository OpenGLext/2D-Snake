//#include <Windows.h>
#include "D:\\Движки\freeglut-2.8.1\include\GL\freeglut.h"
#include "InitSystem.h"
#include "Draws.h"
#include "Keyboard.h"
#include "Timers.h"


#pragma comment(lib,"freeglut.lib")
using namespace std;



HINSTANCE	hInstance;
HINSTANCE hPrevInstance;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR pCmdLine,int nShowCmd)

{
	int argc=0; char** argv=0;
	

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GL_RGB|GL_RGBA);
    glutInitWindowPosition(150,50);
	glutInitWindowSize( Data::wf,Data::hf);
	
	glutCreateWindow("OpenGL 3D System");
	InitGL();
	glutDisplayFunc(NewDraw);
	//glutDisplayFunc(OutHigh);
	
	glutKeyboardFunc(getkeys_down);
	//glutIdleFunc(ProcessMenu);
	glutTimerFunc(Data::IntervalTimer,glutTimer,Data::id); 
	//glutTimerFunc(Data::IntervalTimer,glutTimerSnake,Data::id); 
	
	glutMainLoop();



return 0;
}