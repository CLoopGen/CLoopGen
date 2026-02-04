#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simple zeroing but unrolled to include conditional update pattern
    for (i = 0; i < 9; i++) {
        opd_hist[2*i] = 0;
        if (2*i + 1 < 17) {
            opd_hist[2*i + 1] = 0;
        }
        ipd_hist[2*i] = (2*i) % 5 == 0 ? -1 : 0;
        if (2*i + 1 < 17) {
            ipd_hist[2*i + 1] = (2*i + 1) % 5 == 0 ? -1 : 0;
        }
    }
}
