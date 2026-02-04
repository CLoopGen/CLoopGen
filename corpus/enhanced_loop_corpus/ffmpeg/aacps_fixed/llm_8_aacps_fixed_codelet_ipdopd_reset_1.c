#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 34; i += 2) {
        opd_hist[i] = 0;
        ipd_hist[i] = 0;
        if (i + 1 < 17) {
            opd_hist[i+1] = 0;
            ipd_hist[i+1] = 0;
        }
    }
}
