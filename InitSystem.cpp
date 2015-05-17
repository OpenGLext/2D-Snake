#include "InitSystem.h"

void LoadTextures()
{
	 LoaderTexture->LoadTexture(head, h); 
	 LoaderTexture->LoadTexture(fon,backtga);
     LoaderTexture->LoadTexture(fructTexture, frtga);
     LoaderTexture->LoadTexture(logo,logo_);
     LoaderTexture->LoadTexture(buttonMenu,buttonMenu_);
     LoaderTexture->LoadTexture(fonMenu,fonMenu_);

	 glGenTextures(1, &head->texID);
	 glGenTextures(1, &fon->texID);
	 glGenTextures(1, &fructTexture->texID);
	 glGenTextures(1, &logo->texID);
	 glGenTextures(1, &buttonMenu->texID);
	 glGenTextures(1, &fonMenu->texID);
	
  Vector2Head = new s[0];
  Vector2Tail = new s[20]; 
                           
  Vector2PosFruct = new s[0]; 
 }
void InitGL()
{
	
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,Data::wf,0,Data::hf);
glEnable(GL_SMOOTH);
if (Data::blend )
{
glEnable(GL_BLEND); glBlendFunc(GL_ZERO,  GL_SRC_ALPHA_SATURATE);

}

  fruct = new Fruct::Fructs_();
  back = new Background();
  snake = new SNAKE::Snake_Obj();
  LoaderTexture = new Quad();
    fon = new Texture;
   head = new Texture;
   life = new Texture;
   logo = new Texture;
   fonMenu = new Texture;
   buttonMenu = new Texture;
   fructTexture = new Texture;
   texture = new Texture;

    glEnable(GL_TEXTURE_2D);

   Data::hWnd = FindWindow(L"GLUT",L"OpenGL Application");
   Data::hDC=GetDC(Data::hWnd);

   if (Data::hDC != 0 )
   {
	   ourtext = new Font(hDC,"times",10,15,30);
	
   }
   else 
   {
	   MessageBox(0,L"HDC window not found",L"Information",MB_OK); 
   }
   
LoadTextures();
State = STARTGAME;
menufade[0] = 0.019f;
		
 
}