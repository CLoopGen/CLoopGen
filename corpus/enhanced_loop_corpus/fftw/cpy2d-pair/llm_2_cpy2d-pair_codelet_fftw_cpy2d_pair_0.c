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
    // Variant 1: Consecutive Memory Access (row-major traversal with local pointers)
    R *pI0 = I0;
    R *pI1 = I1;
    R *pO0 = O0;
    R *pO1 = O1;
    for (i1 = 0; i1 < n1; ++i1) {
        for (i0 = 0; i0 < n0; ++i0) {
            R x0 = *(pI0 + i0);
            R x1 = *(pI1 + i0);
            *(pO0 + i0) = x0;
            *(pO1 + i0) = x1;
        }
        pI0 += is1;
        pI1 += is1;
        pO0 += os1;
        pO1 += os1;
    }
}
