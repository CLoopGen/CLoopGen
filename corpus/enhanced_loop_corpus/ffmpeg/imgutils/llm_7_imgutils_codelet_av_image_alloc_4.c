#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (i = 0; i < 4; i++) {
        int curr_index = (i > 0) ? prev_index : i;
        linesizes[i] = ((linesizes[curr_index] + align - 1) & ~(align - 1));
        prev_index = i;
    }
}
