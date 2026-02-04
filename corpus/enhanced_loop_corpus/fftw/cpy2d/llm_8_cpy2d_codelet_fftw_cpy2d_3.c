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
    for (i1 = 0; i1 < n1; i1 += 2)
        for (i0 = 0; i0 < n0; ++i0) {
            if (i1 + 1 < n1) {
                R x0_0 = I[i0 * is0 + i1 * is1];
                R x1_0 = I[i0 * is0 + i1 * is1 + 1];
                R x0_1 = I[i0 * is0 + (i1 + 1) * is1];
                R x1_1 = I[i0 * is0 + (i1 + 1) * is1 + 1];
                O[i0 * os0 + i1 * os1] = x0_0;
                O[i0 * os0 + i1 * os1 + 1] = x1_0;
                O[i0 * os0 + (i1 + 1) * os1] = x0_1;
                O[i0 * os0 + (i1 + 1) * os1 + 1] = x1_1;
            } else {
                R x0 = I[i0 * is0 + i1 * is1];
                R x1 = I[i0 * is0 + i1 * is1 + 1];
                O[i0 * os0 + i1 * os1] = x0;
                O[i0 * os0 + i1 * os1 + 1] = x1;
            }
        }
}
