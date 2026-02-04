#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t main_stride;
extern ptrdiff_t ref_stride;
extern int64_t (*sums)[4];
extern int width;
extern  uint16_t *main16;
extern  uint16_t *ref16;
extern int x;
extern int y;
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (z = 0; z < width; z++) {
    uint64_t s1 = 0, s2 = 0, ss = 0, s12 = 0;
    // Eliminate independent accumulation by combining all updates in a single expression per element
    // Introduce artificial loop-carried dependency via rotating accumulators (WAW-like pattern within loop)
    uint64_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            unsigned int a = main16[x + y * main_stride];
            unsigned int b = ref16[x + y * ref_stride];
            // Chain the accumulations to create sequential dependencies (RAW chains)
            t1 = s1 + a;
            t2 = s2 + b;
            t3 = ss + (uint64_t)a*a + (uint64_t)b*b;
            t4 = s12 + (uint64_t)a*b;
            // Update all at once to simulate batch update (creates WAW hazard if unoptimized)
            s1 = t1;
            s2 = t2;
            ss = t3;
            s12 = t4;
        }
    }
    sums[z][0] = s1;
    sums[z][1] = s2;
    sums[z][2] = ss;
    sums[z][3] = s12;
    main16 += 4;
    ref16 += 4;
}
}
