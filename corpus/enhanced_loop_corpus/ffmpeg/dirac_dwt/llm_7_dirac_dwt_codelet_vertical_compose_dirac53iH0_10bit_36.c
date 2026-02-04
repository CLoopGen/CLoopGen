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
    if (width > 0) {
        b1[0] = b1[0] + (unsigned int)((int)(b0[0] + (unsigned int)(b2[0]) + 1) >> 1);
        for (i = 1; i < width; i++) {
            b1[i] = b1[i] + (unsigned int)((int)(b0[i] + (unsigned int)(b2[i-1]) + 1) >> 1);
        }
    }
}
