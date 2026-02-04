#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: fewer operations and lower trip count
for (i = 0; i < 4; i++) {
    // Simplified expressions: combine and precompute repeated terms
    const unsigned int a = ptr[1], b = ptr[3], c = ptr[5], d = ptr[7];
    const unsigned int sum_odd = a + c, diff_odd = a - c;
    const unsigned int sum_cross = b + d, diff_cross = b - d;

    const unsigned int tL = 77062U * sum_cross + 51491U * sum_odd;
    const unsigned int tM = 77062U * sum_odd - 51491U * sum_cross;
    const unsigned int tN = (((ptr[0] - ptr[4]) * (1U << 16)) + 8192);
    const unsigned int tO = (((ptr[0] + ptr[4]) * (1U << 16)) + 8192);

    // Reduced number of temporary variables and operations
    ptr[0] = (int)(tL + tO) >> 13;
    ptr[1] = (int)(tM + tN) >> 13;
    ptr[2] = (int)(tL + tN) >> 13;
    ptr[3] = (int)(tM + tO) >> 13;
    ptr[4] = (int)(-tM + tO) >> 13;
    ptr[5] = (int)(-tL + tN) >> 13;
    ptr[6] = (int)(-tM + tN) >> 13;
    ptr[7] = (int)(-tL + tO) >> 13;

    ptr += 8;
}
}
