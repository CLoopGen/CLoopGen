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
    int temp;
    for (i = 0; i < width; i++) {
        temp = (unsigned int)(b0[i]) + (unsigned int)(b2[i]);
        b1[i] = ((unsigned int)(b1[i]) + ((int)(217 * temp + 2048) >> 12));
    }
}
