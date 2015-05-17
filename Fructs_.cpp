#include "Fructs_.h"
using namespace Fruct;

Fructs_::Fructs_():m_N(30),m_M(20),m_scale(25),isActive(true)
{

	frame = 1.0f;
}

void Fructs_::New()
{
	//srand(time(0));
	srand(GetTickCount());

	PosFructX = (rand() %  m_N);
	PosFructY = (rand() %  m_M );
}
inline void Fructs_::box_(float x1, float y1, float x2, float y2)
	{

			glBegin(GL_QUADS);	
			glTexCoord2f(0.0f, 0.0f); glVertex2f(x1,y1);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x2,y1);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x2,y2);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x1,y2);
	glEnd();
	}
void Fructs_::DrawApple()
{
  // glColor3f(1.0,0,0);
   
   this->box_(this->PosFructX * m_scale, PosFructY * m_scale, (PosFructX + frame) * m_scale, (PosFructY + frame) * m_scale);
   
   
}


