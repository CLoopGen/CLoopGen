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
    for (step = 0; step < steps; step++) {
        ptr = buffer + width * y;
        float prev = ptr[0];
        ptr[0] *= bscale;
        for (x = 1; x < width; x++) {
            float temp = ptr[x];
            ptr[x] += nu * prev;
            prev = temp;
        }
        ptr[width - 1] *= bscale;
        prev = ptr[width - 1];
        for (x = width - 2; x >= 0; x--) {
            float temp = ptr[x];
            ptr[x] += nu * prev;
            prev = temp;
        }
    }
}
}
