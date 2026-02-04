#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern __attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 2; stride *= 2) {
        for (n = 1; n < 320; n += stride) {
            if (n + stride - 1 < 320) {
                sbr_qmf_window_us[320 + n + stride - 1] = sbr_qmf_window_us[320 - (n + stride - 1)];
            }
            if (stride == 1) continue;
            int mid = n + stride / 2 - 1;
            if (mid < 320 && mid >= 1) {
                sbr_qmf_window_us[320 + mid] = sbr_qmf_window_us[320 - mid];
            }
        }
    }
}
