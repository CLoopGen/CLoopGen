#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *buffer;
extern int width;
extern int height;
extern int steps;
extern float nu;
extern float bscale;
extern int step;
extern int x;
extern int y;
extern float *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    ptr = buffer + width * y;
    for (step = 0; step < steps; step++) {
        ptr[0] *= bscale;
        for (x = 1; x < width; x++)
            ptr[x] += nu * ptr[x - 1];
        ptr[width - 1] *= bscale;
        for (x = width - 1; x > 0; x--)
            ptr[x - 1] += nu * ptr[x];
    }
}
}
