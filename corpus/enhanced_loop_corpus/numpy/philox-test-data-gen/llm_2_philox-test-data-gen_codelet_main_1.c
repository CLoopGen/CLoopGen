#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride of 1
    // Simulating array access pattern by flattening the original 2D iteration space
    volatile int arr[1000];
    for (i = 0; i < 1000; i++) {
        arr[i] = i;  // Consecutive write access
    }
}
