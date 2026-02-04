#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 3) with wrap-around logic to stay within bounds
    int stride = 3;
    int count = (((60 << 2) / 2) + 60);
    for (i = 0; i < count; i++) {
        int idx = (i * stride) % 180;  // Strided access with modulo to avoid out-of-bounds
        vector[idx] = (int16_t)((vector[idx] * hamming_window[idx] + (1 << 14)) >> 15);
    }
}
