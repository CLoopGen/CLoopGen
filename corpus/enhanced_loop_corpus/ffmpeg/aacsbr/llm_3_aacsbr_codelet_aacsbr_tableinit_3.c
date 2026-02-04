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
    // Variant 2: Strided write pattern with reverse traversal and strided read maintained
    // Access is reversed (from high to low index) and writes are done in a non-unit stride manner
    // This changes both temporal and spatial access patterns on both arrays.
    for (n = 319; n >= 0; n--) {
        int idx = 319 - n; // Reverse index for destination to create strided-like logical write order
        sbr_qmf_window_ds[idx] = sbr_qmf_window_us[2 * n];
    }
}
