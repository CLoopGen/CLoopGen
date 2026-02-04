#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nop;
extern int *remap_axis_memory;
extern int **remap_axis;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = 0;
    for (i = 0; i < nop; i++) {
        remap_axis[i] = remap_axis_memory + offset;
        offset += 64;
    }
}
