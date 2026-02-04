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
    for (step = 0; step < steps * 2; step++) {
        ptr = buffer + width * y;
        ptr[0] *= bscale;
        for (x = 1; x < width - 1; x += 2) {
            ptr[x] += nu * ptr[x - 1];
            ptr[x + 1] += nu * ptr[x];
        }
        if (x < width - 1) {
            ptr[x] += nu * ptr[x - 1];
            x++;
        }
        ptr[width - 1] *= bscale;
        for (; x > 1; x--) {
            ptr[x - 2] += nu * ptr[x - 1];
            if (x > 2) ptr[x - 3] += nu * ptr[x - 2];
        }
    }
}
}
