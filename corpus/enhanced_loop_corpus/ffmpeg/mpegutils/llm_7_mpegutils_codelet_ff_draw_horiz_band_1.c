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
        offset[j] = 0;
        offset[j] = offset[j] + j - i;
    }
}
