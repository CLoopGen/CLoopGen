#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i--) {
        offset[i] = offset[i] + 1;
        offset[i] *= 2;
    }
}
