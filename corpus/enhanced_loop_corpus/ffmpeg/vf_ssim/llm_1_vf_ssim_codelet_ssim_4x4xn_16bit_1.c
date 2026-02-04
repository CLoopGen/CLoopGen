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
        for (y = 0; y < 4; y++) {
            unsigned int a0 = main16[0 + y * main_stride];
            unsigned int a1 = main16[1 + y * main_stride];
            unsigned int a2 = main16[2 + y * main_stride];
            unsigned int a3 = main16[3 + y * main_stride];
            unsigned int b0 = ref16[0 + y * ref_stride];
            unsigned int b1 = ref16[1 + y * ref_stride];
            unsigned int b2 = ref16[2 + y * ref_stride];
            unsigned int b3 = ref16[3 + y * ref_stride];

            s1 += a0 + a1 + a2 + a3;
            s2 += b0 + b1 + b2 + b3;
            ss += (uint64_t)a0*a0 + a1*a1 + a2*a2 + a3*a3;
            ss += (uint64_t)b0*b0 + b1*b1 + b2*b2 + b3*b3;
            s12 += (uint64_t)a0*b0 + a1*b1 + a2*b2 + a3*b3;
        }
        sums[z][0] = s1;
        sums[z][1] = s2;
        sums[z][2] = ss;
        sums[z][3] = s12;
        main16 += 4;
        ref16 += 4;
    }
}
