#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t coeffs[16];
extern int32_t *sig;
extern int64_t e;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        int64_t product = (int64_t)(sig[i]) * (int64_t)(coeffs[i]);
        if (product > 0 || (i % 2 == 0)) {
            e += product;
        }
    }
}
