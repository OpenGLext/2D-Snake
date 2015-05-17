#include "Snake_Obj.h"
using namespace SNAKE;

Snake_Obj::Snake_Obj():m_scale(25),m_dir(1),m_len_body(4),m_IsCollision(false),firstRun(true)
{
		s[0].x = 10; s[0].y = 10;
	
		GameOver = false;
		speedsnake = 1.0f;
		frame = 0.9f;	
		speedsnake = 1.0f;
		frame = 0.9f;

		for (int i=0; i<20; i++) // обнулим всю структуру змейки
		{
			s[i].x = 0; s[i].y = 0;
		}

}
int Snake_Obj::GetDir() const
 {
	 return m_dir;
 }
bool Snake_Obj::IsGameOver() const
   {
	return GameOver;
   }
bool Snake_Obj::GetCollision() const
{
	return m_IsCollision;
}
Snake_Obj::~Snake_Obj()
{

}
const int& Snake_Obj::GetLenBody() const
{
	return m_len_body;
}
void Snake_Obj::Tick()
{
    

	for(int i=m_len_body; i>0; --i)
	{
		s[i].x = s[i-1].x;
		s[i].y = s[i-1].y;
	}

	if (m_dir == 0 ) s[0].y += 1;
	if (m_dir == 1 ) s[0].x -= 1;
	if (m_dir == 2 ) s[0].x += 1;
	if (m_dir == 3 ) s[0].y -= 1;

	std::cout<<"Head y"<<s[0].y<<endl;

	if (this->IsHeadIsTail()) { GameOver = true; }
	if (this->IsOutWall())    { GameOver = true; }
    else GameOver = false;
	this->Collision();
	

}
void Snake_Obj::SetLenghtBody(const int& len)
{
	this->m_len_body = len;
}
bool Snake_Obj::IsHeadIsTail()
{
	for (int i=1; i<m_len_body; i++)
		if ( ( s[0].x == s[i].x ) && ( s[0].y == s[i].y) )
		{
			//this->SetLenghtBody(this->GetLenBody()-1); 
                             // или уменьшим на -1 тело

			// уменьшим жизнь 
			this->SetLenghtBody(4); 
			std::cout<<"---Len "<<endl;
			return true; // уменьшим жизнь 
		}
}
 inline void Snake_Obj::box_(float x1, float y1, float x2, float y2)
{
	glBegin(GL_QUADS);	
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(x1,y1);

			glTexCoord2f(1.0f ,0.0f );
			glVertex2f(x2,y1);

			glTexCoord2f(1.0f ,1.0f ); 
			glVertex2f(x2,y2);

			glTexCoord2f(0.0f ,1.0f ); 
			glVertex2f(x1,y2);
	glEnd();
 }
 void Snake_Obj::DrawSnake()
	{
		
		for(int i=0; i<m_len_body; i++)
		{

			this->box_(s[i].x * m_scale  ,
				       s[i].y * m_scale  ,
				      (s[i].x + frame) * m_scale  , 
					  (s[i].y + frame) * m_scale );
		}
	}
void Snake_Obj::SetDir(const int dir) 
	{
		m_dir = dir;

	}	
void Snake_Obj::Draw()
	{
		this->Tick();
		DrawSnake();
	}
void Snake_Obj::SetBorder(const int& Left, const int& Right, const int& Top, const int& Bottom)
	{
		left = Left; right = Right; top = Top; bottom = Bottom;
		
	}
const bool Snake_Obj::IsOutWall()
	{

		if ( s[0].x < (0 ) ) 
		{
			m_dir = 2;

			return true;
		}

		if ( s[0].x > 27 )
		{
			m_dir = 1;
			return true;
		}

		if ( s[0].y > 17 ) //
		{
			m_dir = 3; //2
			return true;
		}

		if ( s[0].y < 1 )
		{
			m_dir = 0;
			return true;
		}

		return false;
	}
bool Snake_Obj::IsCollisionWithBlock(const int& xBlock, const int& yBlock)
{

	if ( ( s[0].x == xBlock ) && ( s[0].y == yBlock) ) { this->SetLenghtBody(4); return true;}
	                                                     // уменьшим тело до стартового
	return false;
}
void Snake_Obj::SetCollision(const bool SET)
{
	this->m_IsCollision = SET;
}
const bool Snake_Obj::Collision()
{
	
	if ((s[0].x == Fruct::Fructs_::PosFructX) && (s[0].y) == Fruct::Fructs_::PosFructY) { m_len_body++; m_IsCollision = true;  return true;   } 
else  return false;  

  
}

	

	
