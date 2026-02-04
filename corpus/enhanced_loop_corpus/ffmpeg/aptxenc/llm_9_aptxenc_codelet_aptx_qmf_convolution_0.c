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
    int j;
    for (i = 0; i < 16; i++) {
        int64_t s = sig[i];
        for (j = 0; j < 3; j++) {
            e += (s * (int64_t)(coeffs[i])) >> j;
        }
    }
}
