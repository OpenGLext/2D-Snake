#pragma once
#include "D:\\Движки\freeglut-2.8.1\include\GL\freeglut.h"
#include "Fructs_.h"
#include "Quad.h"
#include <memory>
#include "DefineTexture.h"
#include "LogSystem.h"
//Использование 

 //logFile<< LogSpace::color("gray") << LogSpace::color("green") << "Snake length" << snake.GetLenBody()<< LogSpace::endl;

using namespace std;

namespace SNAKE
{
	class Snake_Obj 
{
public:
	Snake_Obj();
	~Snake_Obj();



struct
{
 int x;
 int y;
} s[20];

	typedef struct 
	{
       int x,y;
	} Vector2f;

typedef Texture *headTexture_;
headTexture_ *headTexture;

	      void SetDir(const int dir) ;
	      void Draw();
	
	      const int& GetLenBody()const;
	      void SetBorder(const int& left, const int& right, const int& top, const int& bottom);
	      bool GetCollision() const;
		  bool IsHeadIsTail();
		  void SetLenghtBody(const int& len);
          bool IsGameOver() const;
          void DrawSnake();
	      static bool GameOver;
	      void SetCollision(const bool SET );
	      float speedsnake;
	      int GetDir() const;
	

private:
inline void box_(float x1, float y1, float x2, float y2);
	
	int m_scale;
	int m_dir;
	int m_len_body;
	int borderArray[3];
	int left,right,top,bottom;
	float frame;
	float timeDraw;
	bool IsCollisionWithBlock(const int& xBlock, const int& yBlock); // столкновение со стенкой
	bool m_IsCollision, firstRun;
	void Tick();
	const bool Collision();
	const bool IsOutWall();
	int textid;
	float gravity;
	float depthSnake;
	
};
	
}

