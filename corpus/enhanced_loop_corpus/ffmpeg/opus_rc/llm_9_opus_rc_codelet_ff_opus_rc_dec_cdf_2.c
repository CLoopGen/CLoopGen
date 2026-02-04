#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *cdf;
extern unsigned int k;
extern unsigned int symbol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (unsigned int i = 0; i < 1024 && cdf[k + i] <= symbol; i += 8) {
        for (unsigned int j = 0; j < 8 && (k + i + j) < 1024 && cdf[k + i + j] <= symbol; j++) {
            k++;
        }
    }
}
