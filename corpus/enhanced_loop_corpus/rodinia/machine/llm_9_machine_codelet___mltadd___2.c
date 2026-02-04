#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 2;
    int limit = (len4 / unroll_factor) * unroll_factor;
    for (i = 0; i < limit; i += unroll_factor) {
        int idx1 = 4 * i;
        int idx2 = 4 * (i + 1);
        dp1[idx1]     += s * dp2[idx1];
        dp1[idx1 + 1] += s * dp2[idx1 + 1];
        dp1[idx1 + 2] += s * dp2[idx1 + 2];
        dp1[idx1 + 3] += s * dp2[idx1 + 3];

        dp1[idx2]     += s * dp2[idx2];
        dp1[idx2 + 1] += s * dp2[idx2 + 1];
        dp1[idx2 + 2] += s * dp2[idx2 + 2];
        dp1[idx2 + 3] += s * dp2[idx2 + 3];
    }
    for (; i < len4; i++) {
        dp1[4 * i] += s * dp2[4 * i];
        dp1[4 * i + 1] += s * dp2[4 * i + 1];
        dp1[4 * i + 2] += s * dp2[4 * i + 2];
        dp1[4 * i + 3] += s * dp2[4 * i + 3];
    }
}
