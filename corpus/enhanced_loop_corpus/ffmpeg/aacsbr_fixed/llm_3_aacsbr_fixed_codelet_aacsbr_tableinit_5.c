#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a temporary array-like indexing with offset pointer
    INTFLOAT *base = &sbr_qmf_window_us[320];
    for (n = 1; n < 320; n++) {
        base[n] = base[-n];
    }
}
