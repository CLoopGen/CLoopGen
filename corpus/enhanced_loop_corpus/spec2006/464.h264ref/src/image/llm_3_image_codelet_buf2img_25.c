#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgX;
extern unsigned char *buf;
extern int size_x;
extern int size_y;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2 (unrolling-like pattern)
    // Process every second element in a reversed order, then handle remainder if needed
    int total = size_x * size_y;
    int stride = 2;
    int end = total - (total % stride);
    
    // Strided forward pass with step size 2
    for (int idx = 0; idx < end; idx += stride) {
        int j1 = idx / size_x;
        int i1 = idx % size_x;
        int j2 = (idx + 1) / size_x;
        int i2 = (idx + 1) % size_x;

        imgX[j1][i1] = buf[idx];
        imgX[j2][i2] = buf[idx + 1];
    }

    // Handle last element if total is odd
    if (total % stride != 0) {
        int idx = total - 1;
        int j_last = idx / size_x;
        int i_last = idx % size_x;
        imgX[j_last][i_last] = buf[idx];
    }
}
