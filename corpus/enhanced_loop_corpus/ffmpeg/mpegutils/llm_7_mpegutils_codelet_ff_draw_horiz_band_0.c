#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    offset[0] = 0;
    for (i = 1; i < 8; i++) {
        offset[i] = offset[i-1] + 0;
    }
}
