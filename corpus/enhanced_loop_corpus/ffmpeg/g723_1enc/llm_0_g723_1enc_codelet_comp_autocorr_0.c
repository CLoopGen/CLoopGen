#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    for (outer_i = 0; outer_i < 3; outer_i++) {
        for (inner_i = 0; inner_i < 60; inner_i++) {
            i = (outer_i * 60) + inner_i;
            vector[i] = (vector[i] * hamming_window[i] + (1 << 14)) >> 15;
        }
    }
}
