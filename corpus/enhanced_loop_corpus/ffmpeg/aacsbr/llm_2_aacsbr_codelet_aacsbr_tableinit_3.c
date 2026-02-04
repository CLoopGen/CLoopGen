#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_ds[320];
extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to improve spatial locality
    // Instead of accessing sbr_qmf_window_us with stride 2, we process two iterations at once
    // to enable consecutive reads (if original array allows), though here we maintain correctness.
    for (n = 0; n < 320; n += 2) {
        sbr_qmf_window_ds[n] = sbr_qmf_window_us[2 * n];
        if (n + 1 < 320) {
            sbr_qmf_window_ds[n + 1] = sbr_qmf_window_us[2 * (n + 1)];
        }
    }
}
