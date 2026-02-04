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
    R *restrict I_local = I;
    R *restrict O_local = O;
    for (i1 = 0; i1 < n1; ++i1)
        for (i0 = 0; i0 < n0; ++i0) {
            INT idx_in = i0 * is0 + i1 * is1;
            INT idx_out = i0 * os0 + i1 * os1;
            R x0 = I_local[idx_in];
            R x1 = I_local[idx_in + 1];
            O_local[idx_out] = x0;
            // Introduce a WAW dependency by writing twice to same output location in different iterations
            if (i0 == n0 - 1 && i1 > 0) {
                O_local[(i0-1) * os0 + i1 * os1 + 1] = x1; // WAR: read after write, WAW: overwrite previously written value
            } else {
                O_local[idx_out + 1] = x1;
            }
        }
}
