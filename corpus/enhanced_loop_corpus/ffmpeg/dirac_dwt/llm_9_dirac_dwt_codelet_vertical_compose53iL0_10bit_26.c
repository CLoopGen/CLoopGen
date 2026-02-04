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
    for (i = 0; i < width * 2; i++) {
        int idx = i % width;
        int temp = (b0[idx] + b2[idx] + 1);
        temp = (temp > 0) ? (temp >> 1) : -( (-temp) >> 1 );
        b1[idx] -= (unsigned int)((temp + 1) >> 1);
    }
}
