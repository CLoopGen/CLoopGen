#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t prev_b2 = b2[0];
    for (i = 0; i < width; i++) {
        int32_t current_val = (int)(((unsigned int)(prev_b2) + ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 8) >> 4)));
        prev_b2 = b2[i];
        b2[i] = current_val;
    }
}
