#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[5];
    for (i = 3; i < 8; i++) {
        temp[i-3] = i * 2;
        offset[i] = temp[i-3];
    }
}
