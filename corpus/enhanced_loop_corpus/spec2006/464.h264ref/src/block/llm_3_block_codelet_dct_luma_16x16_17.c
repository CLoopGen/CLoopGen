#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M1[16][16];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic and fixed stride pattern
    int *m1_ptr = &M1[0][0]; // Flatten M1 base pointer
    for (int idx = 0; idx < 256; idx++) {
        int i = idx / 16;
        int j = idx % 16;
        // Use strided access: compute M0 indices with arithmetic, then map to flat offset
        int m0_val = *(&M0[0][0][0][0] + ((i % 4) * 64 + (i / 4) * 16 + (j % 4) * 4 + (j / 4)));
        *(m1_ptr + idx) = m0_val;
    }
}
