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
    R temp[16]; // Local buffer to create intra-loop RAW dependencies
    for (i1 = 0; i1 < n1; ++i1)
        for (i0 = 0; i0 < n0; ++i0)
            for (v = 0; v < vl && v < 16; ++v) {
                // Introduce RAW dependency: each read depends on prior computed value in temp
                R x0 = I[i0 * is0 + i1 * is1 + v];
                temp[v] = (v == 0) ? x0 : x0 + temp[v-1]; // Carry forward previous value
                O[i0 * os0 + i1 * os1 + v] = temp[v];
            }
    // Eliminate loop-carried dependency across iterations by making temp local
    // Each outer iteration starts fresh — no state carried between i1 or i0 steps
}
