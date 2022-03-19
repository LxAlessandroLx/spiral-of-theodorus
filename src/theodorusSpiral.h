#ifndef THEODORUS_SPIRAL
#define THEODORUS_SPIRAL

#include <stdlib.h>
#include <stdio.h>

extern int triangles;
extern int antialiasing;
extern int zoom;

extern void init();
extern void setAngles();
extern void reset();
extern void update();
extern void draw();
extern void run();

#endif
