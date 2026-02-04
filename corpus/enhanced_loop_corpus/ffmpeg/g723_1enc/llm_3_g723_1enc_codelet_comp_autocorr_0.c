#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access pattern
    int count = (((60 << 2) / 2) + 60);
    for (i = count - 1; i >= 0; i--) {
        vector[i] = (int16_t)((vector[i] * hamming_window[i] + (1 << 14)) >> 15);
    }
}
