#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing table[in] and table[-in], we use a fixed stride of 2
    // and access elements in a forward-only pattern to avoid negative indexing issues
    int stride = 2;
    for (int i = 0; in + i <= 255; i += stride) {
        int idx = in + i;
        table[idx] = out;
        table[idx + 1] = -out;  // Use consecutive location for symmetry
    }
}
