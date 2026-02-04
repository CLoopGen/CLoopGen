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
    if (order <= 0) return;
    for (i = 0; i < order; i++) {
        fcoeff[i] = coefs[order - 1][i];
    }
}
