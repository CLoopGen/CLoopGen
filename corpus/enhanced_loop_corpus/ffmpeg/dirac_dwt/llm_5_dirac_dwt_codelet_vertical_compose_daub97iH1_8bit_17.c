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
    for (i = 0; i < width; i++) {
        unsigned int sum = (unsigned int)(b0[i]) + (unsigned int)(b2[i]);
        int offset = (113 * sum + 64) >> 7;
        if (offset < (unsigned int)(b1[i])) {
            b1[i] = (unsigned int)(b1[i]) - offset;
        }
    }
}
