# Introduction
  The plan is to code an Image Viewer, where we use a bitmap file as input and read it byte per byte and drawing each pixel on the window.<br/>
  Since we're using the PPM format as input, we receive in the dimensions on the 3rd line. Then we get the maximum value of each R,G,B data (wich we will me ignoring).<br/>
  And we'll make it responsive to exiting events.

# Explaination
  We first import the std librairies and SDL2.<br/>
  Then,
  ```
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
  free(pthrowaway);```
