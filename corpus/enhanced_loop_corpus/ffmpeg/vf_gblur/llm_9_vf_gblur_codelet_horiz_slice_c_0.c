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
for (y = 0; y < height; y += 2) {
    for (step = 0; step < steps / 2; step++) {
        for (int dy = 0; dy < 2 && (y + dy) < height; dy++) {
            ptr = buffer + width * (y + dy);
            float temp = ptr[0];
            ptr[0] *= bscale;
            for (x = 1; x < width; x++) {
                temp = ptr[x] + nu * temp;
                ptr[x] = temp;
            }
            ptr[width - 1] *= bscale;
            for (x = width - 1; x > 0; x--) {
                ptr[x - 1] += nu * ptr[x];
            }
        }
    }
}
}
