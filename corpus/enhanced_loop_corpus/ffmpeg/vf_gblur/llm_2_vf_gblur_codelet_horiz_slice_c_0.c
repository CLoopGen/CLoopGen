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
        // Change memory access to strided: process every 2nd element first, then the others
        // Forward pass with stride 2
        if (width > 0) ptr[0] *= bscale;
        for (x = 2; x < width; x += 2)
            ptr[x] += nu * ptr[x - 1];
        // Stride 2 reverse pass
        for (x = width - 1; x >= 2; x -= 2)
            ptr[x - 1] += nu * ptr[x];
        // Now handle odd-indexed elements in a second phase (interleaved pattern)
        for (x = 1; x < width; x += 2)
            ptr[x] += nu * ptr[(x > 0) ? x - 1 : 0];
        for (x = width - 2; x >= 1; x -= 2)
            ptr[x - 1] += nu * ptr[x];
        if (width > 0) ptr[width - 1] *= bscale;
    }
}
}
