#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2 - 3; x++) {
        unsigned int val1 = (unsigned int)(b[x + w2] + 1) >> 1;
        unsigned int val2 = (unsigned int)(b[x + w2 + 1] + 1) >> 1;
        unsigned int val3 = (unsigned int)(b[x + w2 + 2] + 1) >> 1;
        unsigned int avg = (val1 + val2 + val3 + 1) / 3;
        tmp[x] = b[x] - avg;
    }
}
