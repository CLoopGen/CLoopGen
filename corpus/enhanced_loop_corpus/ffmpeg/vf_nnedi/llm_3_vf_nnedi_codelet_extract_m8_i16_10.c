#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *srcp;
extern  int stride;
extern  int xdia;
extern  int ydia;
extern int16_t *input;
extern int sum;
extern int sumsq;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use strided memory access with a fixed stride over a flattened index space
int total_elements = xdia * ydia;
int access_stride = 4; // Stride of 4 for accessing every 4th element (SIMD-like access pattern)
for (int idx = 0; idx < access_stride; idx++) {
    for (int base = idx; base < total_elements; base += access_stride) {
        int y = base / xdia;
        int x = base % xdia;
        const uint8_t *srcpT = srcp + y * stride * 2;
        if (x < xdia) { // Safe bounds check
            uint8_t val = srcpT[x];
            sum += val;
            sumsq += val * val;
            input[base] = val;
        }
    }
}
}
