#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

__attribute__((aligned(32))) INTFLOAT sbr_qmf_window_ds[320];
__attribute__((aligned(32))) INTFLOAT sbr_qmf_window_us[640];
int n;

void init_vars() {
    for (int i = 0; i < 640; i++) {
        sbr_qmf_window_us[i] = rand() % 1000;
    }
    for (int i = 0; i < 320; i++) {
        sbr_qmf_window_ds[i] = 0;
    }
    n = 0;
}