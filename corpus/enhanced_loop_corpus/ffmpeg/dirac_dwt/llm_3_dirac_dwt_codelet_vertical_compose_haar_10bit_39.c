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
for (i = 0; i < width; i++) {
    int idx = (i * 3) % width;
    b0[idx] = ((int)(b0[idx] - (unsigned int)((int)(b1[idx] + 1U) >> 1)));
    b1[idx] = ((int)(b1[idx] + (unsigned int)(b0[idx])));
}
}
