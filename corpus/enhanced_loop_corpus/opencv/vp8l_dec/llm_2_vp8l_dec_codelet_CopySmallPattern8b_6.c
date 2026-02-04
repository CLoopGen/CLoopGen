#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    int arr[1024];
    for (i = 0; i < (length >> 2); ++i) {
        arr[i] = i * 2;  // Writing consecutively to adjacent memory locations
    }
}
