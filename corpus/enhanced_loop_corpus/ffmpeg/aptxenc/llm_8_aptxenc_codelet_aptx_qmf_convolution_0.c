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
    for (i = 0; i < 8; i++) {
        e += ((int64_t)(sig[2*i]) * (int64_t)(coeffs[2*i]));
        e += ((int64_t)(sig[2*i + 1]) * (int64_t)(coeffs[2*i + 1]));
    }
}
