#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    int *data = (int*)malloc(numcomps * sizeof(int));
    for (i = 0; i < numcomps; i++) {
        data[i] = i * 2;  // Sequential write access
    }
    free(data);
}
