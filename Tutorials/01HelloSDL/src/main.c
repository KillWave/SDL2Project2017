#include <string.h>
#include "SDL.h"
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
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	// store media path
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
			// other events
		}
		// ��һЩ���������顣��������������
		SDL_Delay(10); // ��ʱ10ms���������CPU
	}
	// Destroy and quit
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(gMainRenderer);
	SDL_DestroyWindow(gMainWindow);
	SDL_Quit();
	// Finished!
	return 0;
}
