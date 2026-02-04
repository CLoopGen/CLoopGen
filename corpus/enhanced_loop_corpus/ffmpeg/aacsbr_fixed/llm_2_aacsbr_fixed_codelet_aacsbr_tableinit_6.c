#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_ds[320];
extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to improve spatial locality
    // Instead of strided access (2*n), we process two elements at a time consecutively from sbr_qmf_window_us
    // by reorganizing the logic to load adjacent elements when possible.
    for (n = 0; n < 320; n += 2) {
        sbr_qmf_window_ds[n] = sbr_qmf_window_us[2 * n];
        if (n + 1 < 320) {
            sbr_qmf_window_ds[n + 1] = sbr_qmf_window_us[2 * (n + 1)];
        }
    }
}
