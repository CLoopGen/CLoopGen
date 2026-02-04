#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int diff = (b1[i] + 1U) >> 1;
    b0[i] = b0[i] - diff;
    b1[i] = b1[i] + b0[i];

    // Additional computational work to increase arithmetic intensity
    b0[i] = (b0[i] < 0) ? -b0[i] : b0[i];
    b1[i] = (b1[i] * 3 + 1) & 0x7FFF; // Apply lightweight bit manipulation and clamp
}
}
