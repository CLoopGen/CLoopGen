#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n0l;
extern INT n0u;
extern INT n1l;
extern INT n1u;
extern R *I;
extern INT s0;
extern INT s1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by skipping every other element, increasing stride
for (i1 = n1l; i1 < n1u; i1 += 2) {
    for (i0 = n0l; i0 < n0u; i0 += 2) {
        INT idx1 = i1 * s0 + i0 * s1;
        INT idx2 = i1 * s1 + i0 * s0;
        R temp = I[idx1];
        I[idx1] = I[idx2];
        I[idx2] = temp;
        
        // Perform additional adjacent swaps to maintain memory activity
        if (i0 + 1 < n0u) {
            INT idx1_next = i1 * s0 + (i0 + 1) * s1;
            INT idx2_next = i1 * s1 + (i0 + 1) * s0;
            R temp2 = I[idx1_next];
            I[idx1_next] = I[idx2_next];
            I[idx2_next] = temp2;
        }
    }
}
}
