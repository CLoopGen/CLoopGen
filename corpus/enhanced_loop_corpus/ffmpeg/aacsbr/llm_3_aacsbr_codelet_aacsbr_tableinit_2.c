#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride (stride of 2, unrolled pattern)
    // Simulates non-unit stride access, processing two elements per iteration in reverse symmetry
    for (n = 1; n < 320; n += 2) {
        sbr_qmf_window_us[320 + n] = sbr_qmf_window_us[320 - n];
        if (n + 1 < 320) {
            sbr_qmf_window_us[320 + (n + 1)] = sbr_qmf_window_us[320 - (n + 1)];
        }
    }
}
