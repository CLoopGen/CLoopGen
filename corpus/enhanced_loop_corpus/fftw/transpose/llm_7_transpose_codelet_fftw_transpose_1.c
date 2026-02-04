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
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i1 = 1; i1 < n; ++i1) {
    for (i0 = 0; i0 < i1; ++i0) {
        INT read_idx = i1 * s0 + i0 * s1;
        INT write_idx = i1 * s1 + i0 * s0;
        R temp0 = I[read_idx];
        R temp1 = I[read_idx + 1];
        I[read_idx] = I[write_idx];
        I[read_idx + 1] = I[write_idx + 1];
        I[write_idx] = temp0;
        I[write_idx + 1] = temp1;
    }
}
}
