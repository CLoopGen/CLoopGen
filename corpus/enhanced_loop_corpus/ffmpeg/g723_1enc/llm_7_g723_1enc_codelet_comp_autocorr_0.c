#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = ((60 << 2) / 2) + 60;
    for (i = 0; i < offset; i += 2) {
        vector[i] = (vector[i] * hamming_window[i] + (1 << 14)) >> 15;
        if (i + 1 < offset) {
            vector[i + 1] = (vector[i + 1] * hamming_window[i + 1] + (1 << 14)) >> 15;
        }
    }
}
