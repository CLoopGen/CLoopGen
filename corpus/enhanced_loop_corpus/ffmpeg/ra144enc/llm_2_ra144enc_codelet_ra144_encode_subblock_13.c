#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int8_t ff_cb1_vects[128][40];
extern const int8_t ff_cb2_vects[128][40];
extern float cb1[40];
extern float cb2[40];
extern int cb1_idx;
extern int cb2_idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4 (unrolled-like pattern)
    // Accesses every 4th element in a round-robin fashion across iterations
    int stride = 4;
    for (i = 0; i < 40; i += stride) {
        for (int s = 0; s < stride; s++) {
            int idx = i + s;
            if (idx < 40) {
                cb1[idx] = ff_cb1_vects[cb1_idx][idx];
                cb2[idx] = ff_cb2_vects[cb2_idx][idx];
            }
        }
    }
}
