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
    uint16_t *m_ptr = main16;
    uint16_t *r_ptr = ref16;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            unsigned int a = m_ptr[x];
            unsigned int b = r_ptr[x];
            s1 += a;
            s2 += b;
            ss += a * a;
            ss += b * b;
            s12 += a * b;
        }
        m_ptr += main_stride;
        r_ptr += ref_stride;
    }
    sums[z][0] = s1;
    sums[z][1] = s2;
    sums[z][2] = ss;
    sums[z][3] = s12;
    main16 += 4;
    ref16 += 4;
}
}
