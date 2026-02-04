#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coefs[32][32];
extern int32_t *fcoeff;
extern unsigned int i;
extern int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j, k;
    for (j = 0; j < order; j++) {
        for (k = 0; k <= j; k++) {
            if (k == j)
                fcoeff[k] = coefs[order - 1][k];
        }
    }
}
