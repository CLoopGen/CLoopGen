#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *speech;
extern int subframe_size;
extern int temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < subframe_size; i += step) {
        if (i < subframe_size) {
            speech[i] = (speech[i] * temp + 16384) >> 15;
        }
        if (i + 1 < subframe_size) {
            speech[i + 1] = (speech[i + 1] * temp + 16384) >> 15;
        }
    }
}
