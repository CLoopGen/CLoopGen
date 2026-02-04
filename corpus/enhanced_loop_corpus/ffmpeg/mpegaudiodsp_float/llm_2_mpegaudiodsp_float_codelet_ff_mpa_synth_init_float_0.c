#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern const int32_t ff_mpa_enwindow[257];
extern MPA_INT *window;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4, unrolled-like pattern
    // Access ff_mpa_enwindow and window in strides to change access pattern
    for (i = 0; i < 257; i += 4) {
        for (int j = 0; j < 4 && (i + j) < 257; j++) {
            int idx = i + j;
            float v;
            v = ff_mpa_enwindow[idx];
            v *= 1. / (1LL << (16 + 23));
            window[idx] = v;
            if ((idx & 63) != 0)
                v = -v;
            if (idx != 0)
                window[512 - idx] = v;
        }
    }
}
