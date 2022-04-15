#ifndef THEODORUS_SPIRAL
#define THEODORUS_SPIRAL

#include <stdlib.h>
#include <stdio.h>

extern int triangles;
extern int antialiasing;
extern int zoom;

void init();
void setAngles();
void reset();
void update();
void draw();
void run();

#endif
