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
    for (i = 0; i < 16; i++) {
        if (sig[i] != 0 && coeffs[i] != 0) {
            e += ((int64_t)(sig[i]) * (int64_t)(coeffs[i]));
        }
    }
}
