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
        if (i % 2 == 0) {
            opd_hist[i] = 0;
        } else {
            opd_hist[i] = 0;
        }
        ipd_hist[i] = 0;
    }
}
