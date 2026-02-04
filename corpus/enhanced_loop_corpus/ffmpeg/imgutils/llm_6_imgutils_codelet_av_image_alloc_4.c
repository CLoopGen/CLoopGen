#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = (linesizes[i] + align - 1);
    }
    for (i = 0; i < 4; i++) {
        linesizes[i] = temp[i] & ~(align - 1);
    }
}
