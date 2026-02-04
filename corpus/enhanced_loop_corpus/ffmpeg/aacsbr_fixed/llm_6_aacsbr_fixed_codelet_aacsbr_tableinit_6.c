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
    for (n = 0; n < 319; n++) {
        sbr_qmf_window_ds[n] = sbr_qmf_window_us[2 * n];
        sbr_qmf_window_ds[n + 1] += sbr_qmf_window_us[2 * n]; // Introduces WAW and RAW dependency: ds[n+1] depends on prior iteration's write and current read
    }
    if (n == 319) {
        sbr_qmf_window_ds[319] = sbr_qmf_window_us[638];
    }
}
