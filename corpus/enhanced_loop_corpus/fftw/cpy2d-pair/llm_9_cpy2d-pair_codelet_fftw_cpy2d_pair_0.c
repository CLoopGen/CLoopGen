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
    const INT unroll_factor = 4;
    INT n0_unrolled = n0 - (n0 % unroll_factor);

    for (i1 = 0; i1 < n1; ++i1) {
        i0 = 0;
        for (; i0 < n0_unrolled; i0 += unroll_factor) {
            INT base_idx_0 = i0 * is0 + i1 * is1;
            INT base_idx_1 = (i0+1) * is0 + i1 * is1;
            INT base_idx_2 = (i0+2) * is0 + i1 * is1;
            INT base_idx_3 = (i0+3) * is0 + i1 * is1;

            INT base_oso_0 = i0 * os0 + i1 * os1;
            INT base_oso_1 = (i0+1) * os0 + i1 * os1;
            INT base_oso_2 = (i0+2) * os0 + i1 * os1;
            INT base_oso_3 = (i0+3) * os0 + i1 * os1;

            O0[base_oso_0] = I0[base_idx_0];
            O1[base_oso_0] = I1[base_idx_0];
            O0[base_oso_1] = I0[base_idx_1];
            O1[base_oso_1] = I1[base_idx_1];
            O0[base_oso_2] = I0[base_idx_2];
            O1[base_oso_2] = I1[base_idx_2];
            O0[base_oso_3] = I0[base_idx_3];
            O1[base_oso_3] = I1[base_idx_3];
        }
        for (; i0 < n0; ++i0) {
            INT idx = i0 * is0 + i1 * is1;
            INT oid = i0 * os0 + i1 * os1;
            O0[oid] = I0[idx];
            O1[oid] = I1[idx];
        }
    }
}
