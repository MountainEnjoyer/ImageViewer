#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main () {
  
  FILE *in = stdin;
  char *pthrowaway = calloc(1000, sizeof(char));
  //read first line (specifier P3 or P6) ignored
  fgets(pthrowaway, 1000, in);
  //read comment line 
  fgets(pthrowaway, 1000, in);
  //read width and height
  char *pdimensions = calloc(1000, sizeof(char));
  fgets(pdimensions, 1000, in);
  int width = -1;
  int height = -1;
  sscanf(pdimensions, "%d %d\n", &width, &height);
  free(pdimensions);
  //reads the max color value
  fgets(pthrowaway, 1000, in);
  free(pthrowaway);


  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  Uint32 color = 0;

  SDL_Rect pixel = (SDL_Rect){0,0,1,1};
  for (int y=0; y<height; y++) {
    for (int x=0; x<width; x++) {
      Uint8 r,g,b;
      r = (char) getchar();
      g = (char) getchar();
      b = (char) getchar();
      color = SDL_MapRGB(psurface->format,r,g,b);
      pixel.x = x;
      pixel.y = y;
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  SDL_UpdateWindowSurface(pwindow);
  SDL_Delay(3000);

  return 0;
}
