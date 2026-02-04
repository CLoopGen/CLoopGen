#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern  float pow_0_775[10];
extern  float pow_0_625[10];
extern float lpc_s[10];
extern float lpc_p[10];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle 10 elements safely
    for (n = 0; n < 10; n += 2) {
        int idx = n;
        lpc_s[idx] = lpc[idx] * pow_0_625[idx];
        lpc_p[idx] = lpc[idx] * pow_0_775[idx];
        if (idx + 1 < 10) {
            lpc_s[idx + 1] = lpc[idx + 1] * pow_0_625[idx + 1];
            lpc_p[idx + 1] = lpc[idx + 1] * pow_0_775[idx + 1];
        }
    }
}
