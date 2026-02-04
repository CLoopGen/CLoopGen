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
    for (i = 0; i < width; i += 2) {
        b1[i] = (b1[i] + (unsigned int)((int)(b0[i] + (unsigned int)(b2[i]) + 1) >> 1));
        if (i + 1 < width) {
            b1[i + 1] = (b1[i + 1] + (unsigned int)((int)(b0[i + 1] + (unsigned int)(b2[i + 1]) + 1) >> 1));
        }
    }
}
