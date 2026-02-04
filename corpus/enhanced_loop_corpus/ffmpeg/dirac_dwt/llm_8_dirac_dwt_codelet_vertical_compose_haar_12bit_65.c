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
        b0[i]   = b0[i] - ((b1[i] + 1U) >> 1);
        b1[i]   = b1[i] + b0[i];
        b0[i+1] = b0[i+1] - ((b1[i+1] + 1U) >> 1);
        b1[i+1] = b1[i+1] + b0[i+1];
    } else {
        b0[i] = b0[i] - ((b1[i] + 1U) >> 1);
        b1[i] = b1[i] + b0[i];
    }
}
}
