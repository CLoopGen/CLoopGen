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
if (width > 0) {
    for (i = 0; i < width; i += 2) {
        b1[i] = ((unsigned int)(b1[i]) - ((int)(113 * (b0[i] + (unsigned int)b2[i]) + 64) >> 7));
        if (i + 1 < width) {
            b1[i + 1] = ((unsigned int)(b1[i + 1]) - ((int)(113 * (b0[i + 1] + (unsigned int)b2[i + 1]) + 64) >> 7));
        }
    }
}
}
