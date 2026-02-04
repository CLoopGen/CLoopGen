#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices and local accumulation
    uint16_t temp_left[18];
    uint16_t temp_top[18];
    
    // Preload left and top values into temporary arrays with offset handling
    for (int j = 0; j < 18; j++) {
        if (j < 16) {
            temp_left[j] = left[j];
        } else {
            temp_left[j] = left[15]; // Clamp out-of-bounds
        }
        temp_top[j] = (j >= 1 && j <= 16) ? top[j - 1] : 0;
    }

    for (i = 0; i < 14; i++) {
        // Use consecutive indexing in temp arrays to improve spatial locality
        uint16_t a = temp_left[i + 0];
        uint16_t b = temp_left[i + 1];
        uint16_t c = temp_left[i + 2];

        v[i * 2] = (b + a + 1) >> 1;
        v[i * 2 + 1] = (c + (b << 1) + a + 2) >> 2;

        uint16_t t0 = temp_top[i + 0];
        uint16_t t1 = temp_top[i + 1];
        uint16_t t2 = temp_top[i + 2];
        v[32 + i] = (t0 + (t1 << 1) + t2 + 2) >> 2;
    }
}
