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
  //read first line (specifier P3 or P6) ignored
  fgets(pthrowaway, 1000, in);
  //read comment line 
  fgets(pthrowaway, 1000, in);
  ```
  And Last but not least we read the 3rd line as it stored the width and height of the image we wanna display. 
  ```
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
