#include <stdio.h>

#include <inttypes.h>

extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Offsets
    // Use a stride-based access pattern where each operation works on elements separated by a fixed step,
    // simulating a more scattered memory footprint. This stresses cache performance differently.

    const int stride = 4;
    for (i = 8; i > 0; i -= 2) {
        // Apply operations using a strided indexing scheme across four parallel lanes

        // Lane 0: indices 0, 4, 8, 12
        x[(0+stride)%16] ^= (((x[0] + x[(0+3*stride)%16]) << 7) | ((x[0] + x[(0+3*stride)%16]) >> 25));
        x[(0+2*stride)%16] ^= (((x[(0+stride)%16] + x[0]) << 9) | ((x[(0+stride)%16] + x[0]) >> 23));
        x[(0+3*stride)%16] ^= (((x[(0+2*stride)%16] + x[(0+stride)%16]) << 13) | ((x[(0+2*stride)%16] + x[(0+stride)%16]) >> 19));
        x[0] ^= (((x[(0+3*stride)%16] + x[(0+2*stride)%16]) << 18) | ((x[(0+3*stride)%16] + x[(0+2*stride)%16]) >> 14));

        // Lane 1: indices 1, 5, 9, 13
        x[(1+stride)%16] ^= (((x[1] + x[(1+3*stride)%16]) << 7) | ((x[1] + x[(1+3*stride)%16]) >> 25));
        x[(1+2*stride)%16] ^= (((x[(1+stride)%16] + x[1]) << 9) | ((x[(1+stride)%16] + x[1]) >> 23));
        x[(1+3*stride)%16] ^= (((x[(1+2*stride)%16] + x[(1+stride)%16]) << 13) | ((x[(1+2*stride)%16] + x[(1+stride)%16]) >> 19));
        x[1] ^= (((x[(1+3*stride)%16] + x[(1+2*stride)%16]) << 18) | ((x[(1+3*stride)%16] + x[(1+2*stride)%16]) >> 14));

        // Lane 2: indices 2, 6, 10, 14
        x[(2+stride)%16] ^= (((x[2] + x[(2+3*stride)%16]) << 7) | ((x[2] + x[(2+3*stride)%16]) >> 25));
        x[(2+2*stride)%16] ^= (((x[(2+stride)%16] + x[2]) << 9) | ((x[(2+stride)%16] + x[2]) >> 23));
        x[(2+3*stride)%16] ^= (((x[(2+2*stride)%16] + x[(2+stride)%16]) << 13) | ((x[(2+2*stride)%16] + x[(2+stride)%16]) >> 19));
        x[2] ^= (((x[(2+3*stride)%16] + x[(2+2*stride)%16]) << 18) | ((x[(2+3*stride)%16] + x[(2+2*stride)%16]) >> 14));

        // Lane 3: indices 3, 7, 11, 15
        x[(3+stride)%16] ^= (((x[3] + x[(3+3*stride)%16]) << 7) | ((x[3] + x[(3+3*stride)%16]) >> 25));
        x[(3+2*stride)%16] ^= (((x[(3+stride)%16] + x[3]) << 9) | ((x[(3+stride)%16] + x[3]) >> 23));
        x[(3+3*stride)%16] ^= (((x[(3+2*stride)%16] + x[(3+stride)%16]) << 13) | ((x[(3+2*stride)%16] + x[(3+stride)%16]) >> 19));
        x[3] ^= (((x[(3+3*stride)%16] + x[(3+2*stride)%16]) << 18) | ((x[(3+3*stride)%16] + x[(3+2*stride)%16]) >> 14));

        // Second phase: diagonal-like mixing with offset arithmetic
        // Now use adjacent pairs with wrap-around via modulo indexing
        x[1] ^= (((x[0] + x[3]) << 7) | ((x[0] + x[3]) >> 25));
        x[2] ^= (((x[1] + x[0]) << 9) | ((x[1] + x[0]) >> 23));
        x[3] ^= (((x[2] + x[1]) << 13) | ((x[2] + x[1]) >> 19));
        x[0] ^= (((x[3] + x[2]) << 18) | ((x[3] + x[2]) >> 14));

        x[6] ^= (((x[5] + x[4]) << 7) | ((x[5] + x[4]) >> 25));
        x[7] ^= (((x[6] + x[5]) << 9) | ((x[6] + x[5]) >> 23));
        x[4] ^= (((x[7] + x[6]) << 13) | ((x[7] + x[6]) >> 19));
        x[5] ^= (((x[4] + x[7]) << 18) | ((x[4] + x[7]) >> 14));

        x[11] ^= (((x[10] + x[9]) << 7) | ((x[10] + x[9]) >> 25));
        x[8] ^= (((x[11] + x[10]) << 9) | ((x[11] + x[10]) >> 23));
        x[9] ^= (((x[8] + x[11]) << 13) | ((x[8] + x[11]) >> 19));
        x[10] ^= (((x[9] + x[8]) << 18) | ((x[9] + x[8]) >> 14));

        x[12] ^= (((x[15] + x[14]) << 7) | ((x[15] + x[14]) >> 25));
        x[13] ^= (((x[12] + x[15]) << 9) | ((x[12] + x[15]) >> 23));
        x[14] ^= (((x[13] + x[12]) << 13) | ((x[13] + x[12]) >> 19));
        x[15] ^= (((x[14] + x[13]) << 18) | ((x[14] + x[13]) >> 14));
    }
}
