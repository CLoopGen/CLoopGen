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
for (z = 0; z < width; z += 2) {
    uint64_t s1_0 = 0, s2_0 = 0, ss_0 = 0, s12_0 = 0;
    uint64_t s1_1 = 0, s2_1 = 0, ss_1 = 0, s12_1 = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            unsigned int a0 = main16[x + y * main_stride];
            unsigned int b0 = ref16[x + y * ref_stride];
            s1_0 += a0;
            s2_0 += b0;
            ss_0 += a0 * a0;
            ss_0 += b0 * b0;
            s12_0 += a0 * b0;

            unsigned int a1 = main16[x + y * main_stride + 4];
            unsigned int b1 = ref16[x + y * ref_stride + 4];
            s1_1 += a1;
            s2_1 += b1;
            ss_1 += a1 * a1;
            ss_1 += b1 * b1;
            s12_1 += a1 * b1;
        }
    }
    sums[z][0] = s1_0;
    sums[z][1] = s2_0;
    sums[z][2] = ss_0;
    sums[z][3] = s12_0;

    if (z + 1 < width) {
        sums[z+1][0] = s1_1;
        sums[z+1][1] = s2_1;
        sums[z+1][2] = ss_1;
        sums[z+1][3] = s12_1;
    }
    main16 += 8;
    ref16 += 8;
}
}
