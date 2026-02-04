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
    // Variant 2: Strided write with indirect read via pointer arithmetic
    // Use pointer induction variables to change access pattern
    // Read from sbr_qmf_window_us with stride 2, write consecutively into sbr_qmf_window_ds
    INTFLOAT *src = sbr_qmf_window_us;
    INTFLOAT *dst = sbr_qmf_window_ds;
    for (n = 0; n < 320; n++) {
        dst[n] = src[2 * n];  // Still strides over source, but base pointers used
    }
}
