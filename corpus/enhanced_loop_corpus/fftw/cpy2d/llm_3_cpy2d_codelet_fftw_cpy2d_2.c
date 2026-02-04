#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;
extern INT n1;
extern INT is1;
extern INT os1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride simulation using pointer arithmetic
    INT stride = 2; // Simulate strided access pattern
    for (i1 = 0; i1 < n1; i1 += stride)
        for (i0 = 0; i0 < n0; ++i0) {
            if (i1 + stride - 1 < n1) {
                // Unroll to maintain data consistency and use strided source indexing
                *(double *)&O[i0 * os0 + i1 * os1] = *(double *)&I[i0 * is0 + i1 * is1];
            } else {
                // Handle boundary with scalar write
                for (INT j = i1; j < n1; ++j) {
                    *(double *)&O[i0 * os0 + j * os1] = *(double *)&I[i0 * is0 + j * is1];
                }
            }
        }
}
