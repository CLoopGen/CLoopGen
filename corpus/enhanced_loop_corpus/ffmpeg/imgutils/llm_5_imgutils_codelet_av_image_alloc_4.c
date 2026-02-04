#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int temp = linesizes[i];
        if (temp <= 0) continue;
        linesizes[i] = (temp + align - 1) & ~(align - 1);
    }
}
