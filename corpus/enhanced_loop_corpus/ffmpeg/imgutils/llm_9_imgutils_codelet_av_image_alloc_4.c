#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i >= 0; i--) {
        int temp = align - 1;
        linesizes[i] = (linesizes[i] + temp) & ~temp;
    }
}
