#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t prev = 0;
    for (i = 0; i < width; i++) {
        int32_t current_b0 = b0[i];
        if (i > 0) {
            current_b0 += prev; // Introduce loop-carried dependence (WAW/RAR via prev)
        }
        b1[i] = ((unsigned int)(b1[i]) + ((int)(217 * (current_b0 + (unsigned int)b2[i]) + 2048) >> 12));
        prev = b1[i]; // Create loop-carried dependency: current iteration writes, next reads 'prev'
    }
}
