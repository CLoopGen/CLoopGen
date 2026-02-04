#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 64; i += 2) {
        if (x[i] > 0) {
            x[i] = -(unsigned int)x[i];
        } else {
            continue;
        }
    }
}
