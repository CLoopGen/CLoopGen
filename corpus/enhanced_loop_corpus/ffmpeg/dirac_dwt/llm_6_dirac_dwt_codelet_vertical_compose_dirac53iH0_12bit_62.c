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
    int j;
    for (j = 0; j < width; j++) {
        int temp = b0[j] + b2[j] + 1;
        b1[j] = b1[j] + (unsigned int)(temp >> 1);
    }
}
