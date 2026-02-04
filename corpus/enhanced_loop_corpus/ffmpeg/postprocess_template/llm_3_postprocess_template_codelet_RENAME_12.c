#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int idx = 0; idx < 8; idx++) {
    // Strided memory access pattern: simulate access to arr[idx][j] as arr2d[j][idx]
    // Transposed iteration induces stride in underlying storage
    for (int j = 0; j < 8; j++) {
        int linear_index = j * 8 + idx; // Stride of 8 instead of unit stride
        volatile int dummy = linear_index;
    }
}
}
