#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float qmf_window[48];
extern  float qmf_48tap_half[24];
extern int i;
extern float s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward and mirrored write using pointer arithmetic
    float *win = qmf_window;
    float *half = qmf_48tap_half;
    for (i = 0; i < 24; i++) {
        s = half[i] * 2.0f;
        *(win + i) = s;
        *(win + 47 - i) = s;
    }
}
