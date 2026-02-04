#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled trip count
    for (i = 0; i < 34; i++) {
        opd_hist[i % 17] = (int8_t)((i + 1) * (i + 1) % 128 - 64);
        ipd_hist[i % 17] = (int8_t)((i * 3 + 2) % 128 - 64);
    }
}
