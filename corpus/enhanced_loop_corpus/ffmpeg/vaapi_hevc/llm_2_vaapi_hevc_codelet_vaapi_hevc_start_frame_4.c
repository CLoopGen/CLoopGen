#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single-dimensional array
    int arr[384]; // 6 * 64 = 384 elements
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 64; j++) {
            int index = i * 64 + j; // Consecutive row-major access
            arr[index] = index;
        }
    }
}
