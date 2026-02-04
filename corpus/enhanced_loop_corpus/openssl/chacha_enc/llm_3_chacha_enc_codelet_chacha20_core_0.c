#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern u32 x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern with Pointer Arithmetic
    // Replace direct array indexing with pointer-based strided access.
    // Use fixed strides to traverse the array in non-consecutive but predictable steps.
    // This simulates scenarios where data structures are interleaved or padded.

    u32 *ptr = x;
    const int stride = 1;  // Logical stride remains 1, but access pattern is restructured

    for (i = 20; i > 0; i -= 2) {
        // Define strided views for different lanes
        u32 *v0 = ptr + 0, *v1 = ptr + 1, *v2 = ptr + 2, *v3 = ptr + 3;
        u32 *v4 = ptr + 4, *v5 = ptr + 5, *v6 = ptr + 6, *v7 = ptr + 7;
        u32 *v8 = ptr + 8, *v9 = ptr + 9, *v10 = ptr + 10, *v11 = ptr + 11;
        u32 *v12 = ptr + 12, *v13 = ptr + 13, *v14 = ptr + 14, *v15 = ptr + 15;

        // Round 1: Columnar operations using pointers
        #define ROUND(a,b,c,d,e,f,g,h) \
            do { \
                *(a) += *(e); \
                *(c) = ((((*(c)) ^ (*(a))) << 16) | ((((*(c)) ^ (*(a))) >> 16))); \
                *(g) += *(c); \
                *(e) = ((((*(e)) ^ (*(g))) << 12) | ((((*(e)) ^ (*(g))) >> 20))); \
                *(a) += *(e); \
                *(c) = ((((*(c)) ^ (*(a))) << 8) | ((((*(c)) ^ (*(a))) >> 24))); \
                *(g) += *(c); \
                *(e) = ((((*(e)) ^ (*(g))) << 7) | ((((*(e)) ^ (*(g))) >> 25))); \
            } while(0)

        ROUND(v0, v1, v12, v13, v4, v5, v8, v9);
        ROUND(v1, v2, v13, v14, v5, v6, v9, v10);
        ROUND(v2, v3, v14, v15, v6, v7, v10, v11);
        ROUND(v3, v0, v15, v12, v7, v4, v11, v8);

        // Round 2: Diagonal mixing via shifted lanes
        ROUND(v0, v1, v15, v14, v5, v6, v10, v9);
        ROUND(v1, v2, v12, v15, v6, v7, v11, v8);
        ROUND(v2, v3, v13, v12, v7, v4, v8, v9);
        ROUND(v3, v0, v14, v13, v4, v5, v9, v10);

        #undef ROUND
    }
}
