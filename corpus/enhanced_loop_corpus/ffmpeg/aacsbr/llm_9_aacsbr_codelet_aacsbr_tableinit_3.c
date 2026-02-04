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
    INTFLOAT factor = 1.0f;
    for (n = 0; n < 160; n++) {
        int idx = 2 * n;
        sbr_qmf_window_ds[idx] = sbr_qmf_window_us[2 * idx] * factor;
        sbr_qmf_window_ds[idx + 1] = sbr_qmf_window_us[2 * (idx + 1)] * factor;
    }
}
