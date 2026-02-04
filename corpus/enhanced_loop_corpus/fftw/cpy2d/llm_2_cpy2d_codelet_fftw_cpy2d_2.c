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
    // Variant 1: Consecutive memory access by swapping loop order for better spatial locality
    for (i0 = 0; i0 < n0; ++i0)
        for (i1 = 0; i1 < n1; ++i1) {
            *(double *)&O[i1 * os1 + i0 * os0] = *(double *)&I[i1 * is1 + i0 * is0];
        }
}
