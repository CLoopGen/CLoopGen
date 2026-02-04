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
        int16_t val = speech[i];
        if (val != 0) {
            speech[i] = (val * temp + 16384) >> 15;
        }
    }
}
