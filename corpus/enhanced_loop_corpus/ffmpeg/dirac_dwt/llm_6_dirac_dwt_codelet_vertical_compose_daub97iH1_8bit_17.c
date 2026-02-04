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
    int temp;
    for (i = 0; i < width; i++) {
        temp = (unsigned int)(b0[i]) + (unsigned int)(b2[i]);
        b1[i] = ((unsigned int)(b1[i]) - ((int)(113 * temp + 64) >> 7));
    }
}
