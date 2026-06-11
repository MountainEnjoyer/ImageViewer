#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main () {
  printf("hellow world\n");
  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  Uint8 r,g,b;
  r = 0xFF;
  g=b=0x00;
  Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

  int x = 50;
  int y = 50;
  SDL_Rect pixel = (SDL_Rect){x,y,1,1};
  SDL_FillRect(psurface, &pixel, color);
  SDL_UpdateWindowSurface(pwindow);
  SDL_Delay(3000);

  return 0;
}
