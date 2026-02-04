#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 16; i >= 0; i--) {
        opd_hist[i] = 0;
        ipd_hist[i] = 0;
    }
}
