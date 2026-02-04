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
    if (temp == 0) {
        for (i = 0; i < subframe_size; i++)
            speech[i] = 0;
    } else {
        for (i = 0; i < subframe_size; i++)
            speech[i] = (speech[i] * temp + 16384) >> 15;
    }
}
