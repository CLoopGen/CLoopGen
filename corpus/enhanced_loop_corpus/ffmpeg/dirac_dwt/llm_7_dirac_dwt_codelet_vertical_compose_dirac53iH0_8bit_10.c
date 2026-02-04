#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_b1 = b1[0];
    for (i = 1; i < width; i++) {
        int16_t current_b1 = b1[i];
        b1[i] = (prev_b1 + (unsigned int)((int)(b0[i] + (unsigned int)b2[i] + 1) >> 1));
        prev_b1 = current_b1;
    }
    if (width > 0) {
        b1[0] = (b1[0] + (unsigned int)((int)(b0[0] + (unsigned int)b2[0] + 1) >> 1));
    }
}
