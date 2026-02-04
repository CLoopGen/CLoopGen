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
R temp_buffer[4];
for (i1 = n1l; i1 < n1u; ++i1) {
    for (i0 = n0l; i0 < n0u; ++i0) {
        INT src_idx = i1 * s0 + i0 * s1;
        INT dst_idx = i1 * s1 + i0 * s0;
        temp_buffer[0] = I[src_idx];
        temp_buffer[1] = I[src_idx + 1];
        temp_buffer[2] = I[dst_idx];
        temp_buffer[3] = I[dst_idx + 1];
        I[dst_idx] = temp_buffer[0];
        I[dst_idx + 1] = temp_buffer[1];
        I[src_idx] = temp_buffer[2];
        I[src_idx + 1] = temp_buffer[3];
    }
}
}
