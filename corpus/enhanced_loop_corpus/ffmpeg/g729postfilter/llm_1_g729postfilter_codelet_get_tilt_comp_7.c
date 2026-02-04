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
    for (i = 0; i < subframe_size; i++) {
        for (int k = 0; k < 1; k++) {
            speech[i] = (speech[i] * temp + 16384) >> 15;
        }
    }
}
