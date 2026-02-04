#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 640; n++) {
        if (n <= 320) {
            sbr_qmf_window_us[320 + n] = sbr_qmf_window_us[320 - n];
        } else {
            sbr_qmf_window_us[n] *= 1.05f;
        }
    }
}
