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
    for (i = 1; i < width; i++) {
        b1[i] = ((unsigned int)(b1[i-1]) - ((int)(1817 * (b0[i] + (unsigned int)b2[i]) + 2048) >> 12));
    }
    if (width > 0) {
        b1[0] = ((unsigned int)(b1[0]) - ((int)(1817 * (b0[0] + (unsigned int)b2[0]) + 2048) >> 12));
    }
}
