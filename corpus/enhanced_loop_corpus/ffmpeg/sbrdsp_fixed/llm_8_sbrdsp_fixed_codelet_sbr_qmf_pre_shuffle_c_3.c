#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 2; k < 64; k += 2) {
        z[64 + k] = -z[64 - k/2];
        z[64 + k + 1] = z[k/2 + 1];
    }
}
