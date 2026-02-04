#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *cdf;
extern unsigned int k;
extern unsigned int symbol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 65535 && cdf[k] <= symbol; k++) {
        uint16_t dummy = cdf[k];
        (void)dummy;
    }
}
