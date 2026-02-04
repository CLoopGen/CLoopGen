#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 17; i += 2) {
        opd_hist[i] = 0;
        ipd_hist[i] = 0;
    }
    // Handle odd-sized array if needed by touching remaining element
    if (17 > 0 && 16 % 2 == 0) {
        opd_hist[16] = 0;
        ipd_hist[16] = 0;
    }
}
