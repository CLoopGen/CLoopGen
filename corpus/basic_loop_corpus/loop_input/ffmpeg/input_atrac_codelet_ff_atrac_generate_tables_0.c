#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float qmf_window[48];
float qmf_48tap_half[24];
int i;
float s;

void init_vars() {
    for (int j = 0; j < 24; j++) {
        qmf_48tap_half[j] = (float)(j + 1) * 0.5f;
    }
}