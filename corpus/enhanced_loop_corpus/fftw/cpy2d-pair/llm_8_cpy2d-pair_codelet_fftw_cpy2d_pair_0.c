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
    for (i1 = 0; i1 < n1; i1 += 2) {
        if (i1 + 1 < n1) {
            for (i0 = 0; i0 < n0; ++i0) {
                INT idx_base_curr = i0 * is0 + i1 * is1;
                INT idx_base_next = i0 * is0 + (i1 + 1) * is1;
                INT oid_base_curr = i0 * os0 + i1 * os1;
                INT oid_base_next = i0 * os0 + (i1 + 1) * os1;

                R x0_curr = I0[idx_base_curr];
                R x1_curr = I1[idx_base_curr];
                R x0_next = I0[idx_base_next];
                R x1_next = I1[idx_base_next];

                O0[oid_base_curr] = x0_curr;
                O1[oid_base_curr] = x1_curr;
                O0[oid_base_next] = x0_next;
                O1[oid_base_next] = x1_next;
            }
        } else {
            for (i0 = 0; i0 < n0; ++i0) {
                INT idx = i0 * is0 + i1 * is1;
                INT oid = i0 * os0 + i1 * os1;
                O0[oid] = I0[idx];
                O1[oid] = I1[idx];
            }
        }
    }
}
