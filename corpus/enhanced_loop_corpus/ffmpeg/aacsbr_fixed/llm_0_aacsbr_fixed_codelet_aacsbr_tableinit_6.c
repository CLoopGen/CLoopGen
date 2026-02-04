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
    for (int i = 0; i < 320; i += 16) {
        for (int j = 0; j < 16; j++) {
            int n = i + j;
            sbr_qmf_window_ds[n] = sbr_qmf_window_us[2 * n];
        }
    }
}
