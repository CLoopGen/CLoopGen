#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < 64; i += 2) {
        x[i] = -(unsigned int)x[i - 2];
    }
    if (1 < 64) {
        x[1] = -(unsigned int)x[1];
    }
}
