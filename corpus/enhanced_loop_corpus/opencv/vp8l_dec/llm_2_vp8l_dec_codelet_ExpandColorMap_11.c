#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_colors;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    int *data = (int*)malloc(4 * num_colors * sizeof(int));
    for (i = 4; i < 4 * num_colors; ++i) {
        data[i] = i;  // Writing consecutively to allocated array
    }
    free(data);
}
