#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 17; i++) {
        opd_hist[i] = 0;
        if (i < 8) {
            ipd_hist[i] = 0;
        } else if (i >= 8 && i < 17) {
            ipd_hist[i] = 0; // Explicit branching for second half
        }
    }
}
