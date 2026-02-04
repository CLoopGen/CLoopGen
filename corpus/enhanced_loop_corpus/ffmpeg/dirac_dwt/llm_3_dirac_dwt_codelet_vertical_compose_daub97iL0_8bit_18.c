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
    int *indices = (int*)alloca(width * sizeof(int));
    for (int j = 0; j < width; j++) {
        indices[j] = width - 1 - j; // reverse access pattern
    }
    for (i = 0; i < width; i++) {
        int idx = indices[i];
        b1[idx] = ((unsigned int)(b1[idx]) + ((int)(217 * (b0[idx] + (unsigned int)b2[idx]) + 2048) >> 12));
    }
}
