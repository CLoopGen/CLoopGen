#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 128; i += 4) {
        x[i] = -(unsigned int)(x[i] + 1);
        if (i + 2 < 64) {
            x[i + 2] = -(unsigned int)(x[i + 2] - 1);
        }
    }
}
