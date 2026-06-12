# Introduction
  The plan is to code an Image Viewer, where we use a bitmap file as input and read it byte per byte and drawing each pixel on the window.<br/>
  Since we're using the PPM format as input, we receive in the dimensions on the 3rd line. Then we get the maximum value of each R,G,B data (wich we will me ignoring).<br/>
  And we'll make it responsive to exiting events.

# Explaination
  We first import the std librairies and SDL2.<br/>
  Then we point to the input and allocate memory to another pointer.
  ```
  FILE *in = stdin; // reads stdin
  char *pthrowaway = calloc(1000, sizeof(char)); // allocate large chunk of memory
```
  Then we repeat 2 times the step : read the input and put it in our pointer.<br/>
  We do it 2 times because the first line of the ppm file is the format and the second a comment. 
```
  fgets(pthrowaway, 1000, in);
  fgets(pthrowaway, 1000, in);
  ```
  And Last but not least we read the 3rd line as it stores the width and height of the image we wanna display.<br/>
  With fgets we get a charachter array (char*) wich isn't an int. To convert it we declare our variable as int and give them the value -1.<br/>
  Then we use sscanf to cute the two numbers, from the stdin that we read and stor above, and put them in our variables via their adresses. Don't forget to free the memory.
  ```
  char *pdimensions = calloc(1000, sizeof(char));
  fgets(pdimensions, 1000, in);
  int width = -1;
  int height = -1;
  sscanf(pdimensions, "%d %d\n", &width, &height);
  free(pdimensions);
```
  We read the 4th line wich countain the max color value and then free the 'ignore' variable. 
```
  fgets(pthrowaway, 1000, in);
  free(pthrowaway);
```

Now just have to declare our window with our dimensions, and the surface inside window:
```
  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
```
Now we just have to read each octet and assign its value to a pixel (in order).
To do that we first declare that the variable color will only contain 4 octets. 
```
  Uint32 color = 0;
```
Then declare a rectangle of 1,1 dimensions wich will be our drawing pixel, we define its coordinates as 0,0 wich we will update in a simple manner.
We then define 3 variables r,g,b as 1 octet each. we then read the char(octet) from stdin and with the surface's pointer's format as its format value, we then assign is to the color variable. 
Then update pixel's x, and y.
And we then draw the pixel for each pixel given and update the window after all.
```
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
```
  We then run the event handling with a simple variable used as 'yes or no' and if the quit event is received, we exit the while loop.
```
  int app_running = 1;
  while (app_running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        app_running = 0;
      }
    }
    SDL_Delay(100);
  }
```
