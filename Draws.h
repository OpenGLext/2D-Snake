#pragma once
#include <sstream>
#include "Fructs_.h"
#include "StructData.h"
#include "Quad.h"
#include "Background.h"
#include "LogSystem.h"
#include "Snake_Obj.h"
#include "Font.h"
#include "DefineTexture.h"
#include "Texturing.h"
#include <windef.h>
#include <atltypes.h>
 
using namespace LogSpace;
using namespace Data;

 inline GLvoid box(float x1, float y1, float x2, float y2)
{
	glBegin(GL_QUADS);	
        	glTexCoord2f(0.0f, 0.0f); glVertex2f(x1,y1);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x2,y1);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x2,y2);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x1,y2);
			
	glEnd();
}
 std::string GetStr(const char* mess,const float value,const int valueInt=0)
{
	std::string ScoreFloat="";
	std::stringstream StrStream;

	StrStream<<value;
	StrStream>>ScoreFloat;
	ScoreFloat = mess + ScoreFloat ;
	 
	return ScoreFloat;
}
 void ResetGame()
 {
	 glClear(GL_COLOR_BUFFER_BIT);
	 glClearColor(0,0,0,0);
 }
 void OutLogotype()
 {
	
	
  glColor3f(0.0f,0.0f,0.3f);
 
 }
 void GraphicLog(const char *mess)
 { 


  glColor3f(0.0f,0.0f,0.9f);
  ourtext->put(20, 430, depthGraphLog, mess);


 }
 void DrawBackground()
 {
	
  BindingTexture(fon);
  back->DrawHorizontLine(0,0,0,0);

		
 }
 void OutHigh()
 {
	
    std::string ScoreStr="Score: ";
	std::string ScoreInt="";
	std::string levelStr="Level: ";
	std::string levelInt="";

	std::stringstream StrStream, levelStream;
	StrStream<<Data::high;
	StrStream>>ScoreInt;
	ScoreStr += ScoreInt;
	
	levelStream<<Data::Level;
	levelStream>>levelInt;
	levelStr += levelInt;

	std::string lifes = GetStr("Life: ",Data::lives);

	
	      glColor3f(1.0f,0.0f,1.0f);
		  ourtext->put(100,100, 1.0f, levelStr.c_str());
         // ourtext->put(550,450, 0.0f,ScoreStr.c_str());
		 // ourtext->put(550,430, 0.8f, lifes.c_str());	
 }
 void DrawSnake()
 {
 
    BindingTexture(head);
    snake->Draw();
 }
 void DrawFruct()
 {
	 BindingTexture(fructTexture);
      fruct->DrawApple(); 
 }
 void LoadGameOver()
{
	      glEnable(GL_BLEND);
		
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	
 
          glColor3f(1.0f,0.7f,0.5f);
		  
		  ourtext->put( 10,15,0.0f,"Press space to Start game or ESC to Exit");
		
	
}
 void LevelComplete()
 {
	   
   // ResetGame(); 
		 // glClearColor(0.0f,0.5f,0.5f,0.0f);
	
	     // ourtext.put(150, 250, 0.0f, "Level is complete...");

	/*
	* ƒл€ отладки в качестве заглушки 
	* сделаю проверку 
	* конец уровн€ будет синим экраном
	*/
	//glClearColor(0.0f,0.0f,1.0f,0.5f);
	//glClear(GL_COLOR_BUFFER_BIT);

	 glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

		
 
          glColor3f(1.0f,0.7f,0.5f);
		  
		  ourtext->put( 10,15,0.0f,"Level is complete...");
		 
	
		Sleep(900);
 }
 void ResetLives()
  {
	  if ( Data::lives == 1) { State = GAME_OVER; LoadGameOver();  Sleep(900); }
	  else Data::lives -= 1;
  }
 int  DrawLogo(float n)
{
	glEnable(GL_TEXTURE_2D);
	BindingTexture(logo);
	//glBindTexture(GL_TEXTURE_2D, logo->texID);			// logo.tga
	box(0.0f,0.0f,Data::wf,Data::hf);	
	

	//if (n>=1){ // если конец игры вывести рекорд таблицу
		//glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		//if ((GameTime/100) % 2==0) 
			//glPrint(300,600,0,"press button to menu");							// Write GRID CRAZY On The Screen
	//}
	return TRUE;											
}
 int  DrawMenu(float n,int ID)
{
	// BACKGROUND
	BindingTexture(fonMenu);		// backmenu.tga
	//box(20.0f-400*(1-n),120.0f,330.0f-400*(1-n),360.0f);	
	box(300,150,450,300);

	// MENU ITEMS
	BindingTexture(buttonMenu);		// button.tga
	for (int i=0;i<4;i++)
	{
	if (i!=ID) if (menu_items_fade[i]>0.5f){menu_items_fade[i]-=0.002f; }
	if (ID==i) if (menu_items_fade[i]<1.0f){menu_items_fade[i]+=0.008f; } 
	glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
	
	//box(40.0f-400*(1-n),150.0f+i*50,300.0f-400*(1-n),195.0f+i*50);	
	glColor4f(0.0f,0.0f,0.0f,0.5f);
	box(320,280,430,320);
	}

    BindingTexture(fonMenu);		// backmenu.tga
	for (int i=0;i<4;i++)
	{
		glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
		//glPrint(50.0f-400.0f*(1.0f-n),155.0f+i*50.0f,0,menu_items[i]);							// Write GRID CRAZY On The Screen
	}
	
	return TRUE;											
}
 void RenderSnake()
 {
	 // считываем пикселы сцены

	 // провер€ем если это не хвост и не голова т.е все тело то сотрем
 }
 void LoadReset()
 {
	 snake->SetLenghtBody(4);
	 Data::lives = 3;
	 fruct->New();

 }
 inline void CheckBodySnake()
 {
	 switch (snake->GetDir())
	 {

	 case 0 : 
		 

			 for (int i=0; i<snake->GetLenBody(); i++)
				// if () {}
		 
		 break;

	 case 1 : break;
	 case 2 : break;
	 case 3 : break;

	 }
 }
 void NewDraw()
 {
	   ResetGame(); 

  if (snake->GetCollision())
	  { 
		  snake->SetCollision(false);
		     firstRun = false; 
		  changeFruct = true;

		   ResetGame(); 
		  fruct->New();
		  fruct->DrawApple();
	  }

	  if (firstRun | changeFruct)
	  {    
		  
           fruct->New(); 
		   DrawFruct();
		      firstRun = false;
		   changeFruct = false;
	  }
	 
    
	   // DrawBackground();
      // DrawFruct();
	 // DrawSnake();
	  OutHigh();
	  glutSwapBuffers();
 }
   /****************************** 
	 * попробуем сделать
	 через мышку попадание точки 
	 курсора
	 в плоскость  кнопки сравнение 
	 по миним и максимуму
	 if (curx > xminButton && curx < xmaxButton)
	 {
	   if cury > yminButton && cury < ymaxButton )
	   {
	     // попали в кнопку дергаем указатель на фу-ии обработчика нажати€
		 или даже просто вызываем нужный обработчик
	   }
	 }
	 *
	 ******************************
	 */ 
 void DrawMenu()
 {
	 float posMenuX(200),posMenuY(150),MenuScale(2.5f);
	 

	 glEnable(GL_TEXTURE_2D);
	 /****************************** 
	 * главна€ рамка меню задн€€
	 *
	 ******************************
	 */
	
	 gluBuild2DMipmaps(GL_TEXTURE_2D, fonMenu->bpp / 8,  fonMenu->width,  fonMenu->height, fonMenu->type, GL_UNSIGNED_BYTE,  fonMenu->imageData);		
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	 box(posMenuX,posMenuY,posMenuX*MenuScale,posMenuY*MenuScale);


	  /****************************** 
	 * рисуем 3 кнопки старт опции и выход,
	   дл€ начала хот€ бы одну 
	   сделать рабочую старт 
	 *
	 ******************************
	 */
	 posMenuX = 220; posMenuY = 355;
	 gluBuild2DMipmaps(GL_TEXTURE_2D, buttonMenu->bpp / 8,  buttonMenu->width,  buttonMenu->height, buttonMenu->type, GL_UNSIGNED_BYTE,  buttonMenu->imageData);		
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	 box(posMenuX,posMenuY,posMenuX+MenuScale,posMenuY+MenuScale);

	 //glDisable(GL_TEXTURE_2D);
 }
 void ProcessMenu()
 {
	

	 if ( State == LOGO)            {  DrawLogo(menufade[LOGO]);        }
	 if ( State == MAIN_MENU)       {  DrawMenu(); } //DrawMenu(menufade[MAIN_MENU],0); }
	 if ( State == STARTGAME)       {  NewDraw();                          }
	 if ( State == LEVELCOMPLETE )  {  LevelComplete();                 }
	 if ( State == GAME_OVER     )  {  LoadGameOver();                  }
	 if ( State == RESETGAME     )  {  LoadReset();                     }
	 
	glutSwapBuffers(); 
	glDisable(GL_TEXTURE_2D);
 }

