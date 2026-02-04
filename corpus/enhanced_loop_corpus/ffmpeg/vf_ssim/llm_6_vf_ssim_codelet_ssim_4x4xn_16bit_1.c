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
    uint16_t temp_main[16], temp_ref[16];
    // Introduce local data dependency: preload data into temporaries to decouple memory accesses from reduction
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            temp_main[x + y * 4] = main16[x + y * main_stride];
            temp_ref[x + y * 4] = ref16[x + y * ref_stride];
        }
    }
    // Now perform computation on local arrays, creating a two-phase dependency (load then compute)
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            unsigned int a = temp_main[x + y * 4];
            unsigned int b = temp_ref[x + y * 4];
            s1 += a;
            s2 += b;
            ss += (uint64_t)a * a;
            ss += (uint64_t)b * b;
            s12 += (uint64_t)a * b;
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
