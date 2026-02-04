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
        ipd_hist[i] = 0;
        opd_hist[i] = ipd_hist[i]; // Introduce RAW dependency: opd_hist[i] depends on ipd_hist[i]
    }
}
