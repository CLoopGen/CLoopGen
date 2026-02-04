#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 3, j = 0; i < 40 && j < 10 && src[i]; i++, j++) {
        src[i][0] += (uint8_t)(i ^ j);
        if (src[i+1]) src[i+1][0] += 1;
    }
    channels = i;
}
