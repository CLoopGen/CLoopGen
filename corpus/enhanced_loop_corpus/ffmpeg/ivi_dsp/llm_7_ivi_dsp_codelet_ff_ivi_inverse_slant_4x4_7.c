#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int i;
extern  int32_t *src;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int32_t s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    if (!s0 && !s1 && !s2 && !s3) {
        out[0] = out[1] = out[2] = out[3] = 0;
    } else {
        t1 = s0 + s2;
        t2 = s0 - s2;
        
        t0 = s1 + (s3 << 1); // Remove shared use of src[1] and src[3] by pre-loading
        t0 = ((t0 + 2) >> 2) + s1; // RAW: t0 depends on prior computation
        
        t3 = (s1 << 1) - s3;
        t3 = ((t3 + 2) >> 2) - s3;

        // Introduce artificial sequential dependency to prevent reordering
        t4 = t1 + t0;
        t0 = t4 - t0; // t0 now depends on t4, which depends on t1 and original t0
        t1 = t4;      // Break direct use of old t1; create new data flow

        t4 = t0; // Propagate through t4 late to increase transitive dependencies

        t0 = t2 - t3;
        t2 = t2 + t3;
        t3 = t0;

        // Force ordered writes with explicit sequencing via temp variables
        int o0 = (t1 + 1) >> 1;
        int o1 = (t2 + 1) >> 1;
        int o2 = (t3 + 1) >> 1;
        int o3 = (t4 + 1) >> 1;

        out[0] = o0;
        out[1] = o1;
        out[2] = o2;
        out[3] = o3;
    }
    src += 4;
    out += pitch;
}
}
