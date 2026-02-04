#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 32; i += 2) {
        x[i] = -(unsigned int)(x[i] * 2);
        x[i - 1] = -(unsigned int)(x[i - 1] / 2);
    }
}
