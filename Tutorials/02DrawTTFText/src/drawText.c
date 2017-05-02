#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "util.h"

#ifdef _WIN
#pragma warning(disable:4996) 
#endif

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
	if( argc==2 ) strcpy(gMediaPath, argv[1]);
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	// Create a window via SDL
	gMainWindow = SDL_CreateWindow("Draw Text using SDL_ttf", 
			gMainWinRect.x, gMainWinRect.y, gMainWinRect.w, gMainWinRect.h, 0);
	// Create rendering context
	gMainRenderer = SDL_CreateRenderer(gMainWindow, -1, SDL_RENDERER_ACCELERATED);
	// ��ʼ��TTF��ϵͳ
	TTF_Init();
	// �����ԭ������������
	SDL_SetRenderDrawColor(gMainRenderer, 128, 128, 128, 255); // ��ɫ
	SDL_RenderClear(gMainRenderer); //����
	drawstring("Hi, there!", gMainWinRect.w/8,20, 
		FullPath("/default/FreeSerif.ttf"), 64, textcolor);
	textcolor.r = 0; // ��ɫ
	drawstring("Can you see me?", gMainWinRect.w/8,gMainWinRect.h-100, 
		FullPath("/default/FreeSerif.ttf"), 64, textcolor);
	// ���������ݳ��ֳ���
	SDL_RenderPresent(gMainRenderer); 

	// Enter event processing loop 
	while ( 1 ) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break; // ��ֹӦ�ó���
			}
		}
	}
	// Destroy and quit
	TTF_Quit(); // �˳�TTF��ϵͳ
	SDL_DestroyRenderer(gMainRenderer);
	SDL_DestroyWindow(gMainWindow);
	SDL_Quit();
	// Finished!
	return 0;
}
