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
extern INT vl;
extern INT i0;
extern INT i1;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering loops to access I and O sequentially
    // Loop order changed to v, i0, i1 for spatial locality in vectorized dimension
    for (v = 0; v < vl; ++v)
        for (i0 = 0; i0 < n0; ++i0)
            for (i1 = 0; i1 < n1; ++i1) {
                INT idx_I = i0 * is0 + i1 * is1 + v;
                INT idx_O = i0 * os0 + i1 * os1 + v;
                R x0 = I[idx_I];
                O[idx_O] = x0;
            }
}
