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
for (i = 0; i < width; i++) {
    int idx = (i * 3) % width;
    b1[idx] = (b1[idx] + (unsigned int)((int)(b0[idx] + (unsigned int)(b2[idx]) + 1) >> 1));
}
}
