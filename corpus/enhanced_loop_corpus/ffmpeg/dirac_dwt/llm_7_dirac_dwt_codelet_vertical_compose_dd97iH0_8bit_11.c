#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < width; i++) {
        b2[i] = (int)(((unsigned int)(b2[i-1]) + ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 8) >> 4)));
    }
    if (width > 0) {
        b2[0] = (int)(((unsigned int)(b2[0]) + ((int)(9U * b1[0] + 9U * b3[0] - b4[0] - b0[0] + 8) >> 4)));
    }
}
