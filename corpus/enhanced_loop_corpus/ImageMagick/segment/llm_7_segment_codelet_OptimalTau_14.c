#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp = 0;
    for (i = 0; i <= 255; i++) {
        temp = extrema[i];
        extrema[i] = temp + 1;
        extrema[i] = extrema[i] - 1;
    }
}
