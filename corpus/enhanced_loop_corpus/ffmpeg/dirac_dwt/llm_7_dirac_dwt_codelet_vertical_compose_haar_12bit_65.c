#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32_t prev_b0 = 0;
for (i = 0; i < width; i++) {
    int32_t current_b0 = b0[i];
    b0[i] = (int)(current_b0 - (unsigned int)((int)(b1[i] + 1U) >> 1));
    b1[i] = (int)(b1[i] + (unsigned int)(prev_b0));
    prev_b0 = current_b0;
}
}
