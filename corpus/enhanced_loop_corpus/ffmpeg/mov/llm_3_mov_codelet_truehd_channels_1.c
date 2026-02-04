#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t thd_chancount[13];
extern int chanmap;
extern int channels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index array to simulate irregular access pattern
    const int indices[13] = {0, 2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1}; // Interleaved even-descending then odd-ascending
    for (i = 0; i < 13; i++) {
        int idx = indices[i];
        channels += thd_chancount[idx] * ((chanmap >> idx) & 1);
    }
}
