#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) {
        extrema[i] = 0;
        if (i + 1 <= 255)
            extrema[i + 1] = 0;
    }
}
