#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern INT n;
extern INT s0;
extern INT s1;
extern INT vl;
extern INT i0;
extern INT i1;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i1 = 1; i1 < n; ++i1) {
    for (i0 = 0; i0 < i1; ++i0) {
        R temp[16]; // Local buffer to hold values and modify data reuse
        INT offset1 = i1 * s0 + i0 * s1;
        INT offset2 = i1 * s1 + i0 * s0;
        for (v = 0; v < vl && v < 16; ++v) {
            temp[v] = I[offset1 + v];         // Read all needed first (break WAW/RW)
            R y0 = I[offset2 + v];
            I[offset2 + v] = temp[v];         // Use buffered value later (introduce WAR-like pattern)
        }
        for (v = 0; v < vl && v < 16; ++v) {
            I[offset1 + v] = I[offset2 + v];  // Now write back using updated values (creates loop-carried dependency via memory)
        }
    }
}
}
