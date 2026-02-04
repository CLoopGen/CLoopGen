#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *cdf;
extern unsigned int k;
extern unsigned int symbol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            for (; cdf[k] <= symbol; k++)
                ;
        }
    }
}
