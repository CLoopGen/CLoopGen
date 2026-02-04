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
extern INT vl;
extern INT i0;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride over iterations
    INT stride = 1;
    for (i0 = 0; i0 < n0; i0 += stride) {
        for (v = 0; v < vl; ++v) {
            R x0 = I[i0 * is0 + v];
            O[i0 * os0 + v] = x0;
        }
        stride = (stride << 1); // Double the stride each outer iteration
    }
}
