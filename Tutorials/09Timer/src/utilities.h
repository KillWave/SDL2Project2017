#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"

char * MakePath(char path[], char dir[], char filename[]);
char * FullPath(char filename[]);
void  drawrect(int x, int y, int w, int h, int color);
int   Color2Int(SDL_Color cc);
SDL_Color Int2Color(int color);
SDL_Rect drawstring(char s[], // �ı��ַ���
	int x, int y,             // ���Ƶ�λ��
	char fontFile[],          // ָ�������ļ�
	int fontSize,             // �����С
	SDL_Color color);         // ��ɫ
SDL_Texture* loadTextureFromBMP(char fileName[]);
