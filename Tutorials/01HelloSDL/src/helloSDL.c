#include <string.h>
#include "SDL.h"
#include "utilities.h"

#if (defined _WIN32) || (defined _WIN64)
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
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	// store media path
	if( argc==2 ) strcpy(gMediaPath, argv[1]);
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	// Create a window via SDL
	gMainWindow = SDL_CreateWindow("Hello World", gMainWinRect.x, gMainWinRect.y, gMainWinRect.w, gMainWinRect.h, 0);
	// Load an image and set as the gMainWindow icon
	surface = SDL_LoadBMP(FullPath("/default/SDLLogo.bmp"));
	SDL_SetWindowIcon(gMainWindow, surface);
	SDL_FreeSurface(surface);
	// Create rendering context
	gMainRenderer = SDL_CreateRenderer(gMainWindow, -1, SDL_RENDERER_ACCELERATED);
	//����һ��BMPͼ��
	surface = SDL_LoadBMP(FullPath("/default/helloSDL.bmp"));
	//��ͼ��ת��Ϊ��Ч�ʵ�����
	texture = SDL_CreateTextureFromSurface(gMainRenderer, surface);
	// ͼ�������ã��ͷŵ�
	SDL_FreeSurface(surface);  
	// Display the image
	// �����ԭ������������
	SDL_RenderClear(gMainRenderer); //����
	// ��ʾͼ��
	SDL_RenderCopy(gMainRenderer, texture, NULL, NULL);
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
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(gMainRenderer);
	SDL_DestroyWindow(gMainWindow);
	SDL_Quit();
	// Finished!
	return 0;
}
