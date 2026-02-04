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
for (i = 0; i < width; i += 2) {
    if (i + 1 < width) {
        b0[i] = ((int)(b0[i] - (unsigned int)((int)(b1[i] + 1U) >> 1)));
        b1[i] = ((int)(b1[i] + (unsigned int)(b0[i])));
        b0[i+1] = ((int)(b0[i+1] - (unsigned int)((int)(b1[i+1] + 1U) >> 1)));
        b1[i+1] = ((int)(b1[i+1] + (unsigned int)(b0[i+1])));
    } else {
        b0[i] = ((int)(b0[i] - (unsigned int)((int)(b1[i] + 1U) >> 1)));
        b1[i] = ((int)(b1[i] + (unsigned int)(b0[i])));
    }
}
}
