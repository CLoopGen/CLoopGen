#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8] = {0};
    for (i = 3; i < 8; i++) {
        temp[i] = offset[i];
        offset[i] = temp[i-3] + 1;
    }
}
