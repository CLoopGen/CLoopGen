#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **incep;
extern int32 nfr;
extern int32 ceplen;
extern float32 *cur_mean;
extern float32 *sum;
extern int32 nframe;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements in inner loop, use a stride of 2 (unrolled-like pattern)
    // Handle odd-sized ceplen by ensuring we don't exceed bounds
    for (i = 0; i < nfr; i++) {
        int32 j_even, j_odd;
        for (j_even = 0, j_odd = 1; j_even < ceplen - 1; j_even += 2, j_odd += 2) {
            sum[j_even] += incep[i][j_even];
            sum[j_odd]  += incep[i][j_odd];
            incep[i][j_even] -= cur_mean[j_even];
            incep[i][j_odd]  -= cur_mean[j_odd];
        }
        // Handle last element if ceplen is odd
        if (j_even == ceplen - 1) {
            sum[j_even] += incep[i][j_even];
            incep[i][j_even] -= cur_mean[j_even];
        }
        ++nframe;
    }
}
