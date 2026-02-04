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
    for (i = 0; i < nop; i++) {
        int offset = i << 6; // Equivalent to i * 64 using bit shift
        remap_axis[i] = remap_axis_memory + offset;
        remap_axis[i][0] = offset; // Additional memory write to increase computational intensity
        remap_axis[i][1] = offset + 1;
    }
}
