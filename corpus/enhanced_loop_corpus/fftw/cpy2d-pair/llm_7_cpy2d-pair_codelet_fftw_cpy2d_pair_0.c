#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I0;
extern R *I1;
extern R *O0;
extern R *O1;
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
            INT read_idx = i0 * is0 + i1 * is1;
            INT write_idx0 = i0 * os0 + i1 * os1;
            INT write_idx1 = write_idx0; // Explicit reuse to emphasize WAW-like potential (though not carried)
            R x0 = I0[read_idx];
            R x1 = I1[read_idx];
            O0[write_idx0] = x0;
            O1[write_idx1] = x1; // Introduces explicit index dependency reuse (WAR/WAW pattern in store)
        }
}
