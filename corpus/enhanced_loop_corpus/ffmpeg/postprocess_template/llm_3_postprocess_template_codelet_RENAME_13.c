#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int ref;
        int cur;
        // Modify memory access to consecutive access in row-major order
        // Simulate 2D traversal as flat 1D array with consecutive accesses
        volatile int matrix[64];
        int idx1 = y * 8 + x;   // Consecutive, predictable access
        int idx2 = y * 8 + x + 1;
        ref = matrix[idx1 % 64];
        cur = matrix[idx2 % 64];
    }
}
}
