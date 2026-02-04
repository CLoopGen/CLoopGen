#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 60; j++) {
        // First segment: 0 to 59
        vector[j] = (vector[j] * hamming_window[j] + (1 << 14)) >> 15;
        // Second segment: 60 to 119
        vector[j + 60] = (vector[j + 60] * hamming_window[j + 60] + (1 << 14)) >> 15;
        // Third segment: 120 to 179
        vector[j + 120] = (vector[j + 120] * hamming_window[j + 120] + (1 << 14)) >> 15;
    }
}
