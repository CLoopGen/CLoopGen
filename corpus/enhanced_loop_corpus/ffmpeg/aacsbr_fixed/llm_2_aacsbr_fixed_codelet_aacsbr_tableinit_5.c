#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2
    for (n = 2; n < 320; n += 2) {
        sbr_qmf_window_us[320 + n] = sbr_qmf_window_us[320 - n];
        if (n + 1 < 320) {
            sbr_qmf_window_us[320 + (n + 1)] = sbr_qmf_window_us[320 - (n + 1)];
        }
    }
}
