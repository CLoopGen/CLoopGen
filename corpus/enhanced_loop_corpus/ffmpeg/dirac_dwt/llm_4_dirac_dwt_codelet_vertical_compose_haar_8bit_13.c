#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        if (b1[i] >= 0) {
            b0[i] = b0[i] - ((unsigned int)(b1[i] + 1U) >> 1);
            b1[i] = b1[i] + b0[i];
        }
    }
}
