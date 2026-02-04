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
    INTFLOAT temp[320];
    for (n = 0; n < 320; n++) {
        temp[n] = sbr_qmf_window_us[2 * n];
    }
    for (n = 0; n < 320; n++) {
        sbr_qmf_window_ds[n] = temp[n];
    }
}
