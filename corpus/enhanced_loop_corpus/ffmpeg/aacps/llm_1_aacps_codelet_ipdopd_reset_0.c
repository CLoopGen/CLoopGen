#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 17; i += 4) {
        for (int j = i; j < i + 4 && j < 17; j++) {
            opd_hist[j] = 0;
            ipd_hist[j] = 0;
        }
    }
}
