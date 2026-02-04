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
    for (i1 = 0; i1 < n1; ++i1)
        for (i0 = 0; i0 < n0; ++i0) {
            INT idx = i0 * is0 + i1 * is1;
            R x0 = I[idx];
            R x1 = I[idx + 1];
            // Remove immediate data dependency by delaying write through accumulation of index
            INT offset = (i0 + i1) % 2; // Introduce non-uniform store pattern
            if (offset == 0) {
                O[i0 * os0 + i1 * os1] = x0;
                O[i0 * os0 + i1 * os1 + 1] = x1;
            } else {
                // Reverse access order to create different dependency chain
                O[i0 * os0 + i1 * os1 + 1] = x0; // RAW: use of x0 delayed
                O[i0 * os0 + i1 * os1] = x1;
            }
        }
}
