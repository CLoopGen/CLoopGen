#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 3; j < 8; j++) {
        offset[j+1] = 0;
    }
    for (i = 3; i < 8; i++) {
        offset[i] = offset[i] * 2;
    }
}
