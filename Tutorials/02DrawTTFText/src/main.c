#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "utilities.h"


#if (defined _WIN32) || (defined _WIN64)
#pragma warning(disable:4996) 
#endif

int  gGameover = 0;
char gMediaPath[256] = "../Media";
/*���崰��λ��(100,100),��С(640,480)*/
SDL_Rect  gMainWinRect = { 100, 100, 640, 480 };
/* ����ָ����� */
SDL_Window   * gMainWindow = NULL;
/* ͼ�λ��ƻ���ָ�� */
SDL_Renderer * gMainRenderer = NULL;

int main(int argc, char *argv[]) 
{
	SDL_Color textcolor = { 255, 255, 0, 255 }; //��ɫ
	if( argc>1 ) 
		strcpy(gMediaPath, argv[1]);
	else {
		strcpy(gMediaPath, SDL_GetBasePath());
		strcat(gMediaPath, "../../../Media");
	}
	printf("base path = %s\n", SDL_GetBasePath());
	printf("media path = %s\n", gMediaPath);
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	// Create a window via SDL
	gMainWindow = SDL_CreateWindow("Draw Text using SDL_ttf", 
			gMainWinRect.x, gMainWinRect.y, gMainWinRect.w, gMainWinRect.h, 0);
	// Create rendering context
	gMainRenderer = SDL_CreateRenderer(gMainWindow, -1, SDL_RENDERER_ACCELERATED);
	// ��ʼ��TTF��ϵͳ
	TTF_Init();
	// ������Ļ 
	SDL_SetRenderDrawColor(gMainRenderer, 128, 128, 128, 255);
	SDL_RenderClear(gMainRenderer); //����
	drawstring("Hi, there!", gMainWinRect.w/8,20, 
		FullPath("/default/FreeSerif.ttf"), 64, textcolor);
	textcolor.r = 0; // ��ɫ
	drawstring("Can you see me?", gMainWinRect.w/8,gMainWinRect.h-100, 
		FullPath("/default/FreeSerif.ttf"), 64, textcolor);
	// ���������ݳ��ֳ���
	SDL_RenderPresent(gMainRenderer); 
	// Enter main loop 
	while ( !gGameover ) 
	{
		SDL_Event e; // �����¼�
		while ( !gGameover && SDL_PollEvent(&e)) 
		{
			if((e.type == SDL_KEYUP && e.key.keysym.sym==SDLK_ESCAPE) ||
				e.type == SDL_QUIT) //user close window or press ESC key
			{
				gGameover = 1; // ��ֹӦ�ó���
			}
			// other events ...
		}
		// ��һЩ���������顣��������������
		SDL_Delay(10); // ��ʱ10ms���������CPU
	}
	// Destroy and quit
	TTF_Quit(); // �˳�TTF��ϵͳ
	SDL_DestroyRenderer(gMainRenderer);
	SDL_DestroyWindow(gMainWindow);
	SDL_Quit();
	// Finished!
	return 0;
}
