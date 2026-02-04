#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (i = 0; i < 8; i++) {
        temp[i] = i;
    }
    for (i = 0; i < 8; i++) {
        offset[i] = temp[i] - i;
    }
}
