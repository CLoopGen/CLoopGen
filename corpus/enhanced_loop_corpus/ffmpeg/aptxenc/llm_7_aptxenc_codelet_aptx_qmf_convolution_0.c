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
    int64_t local_e[16];
    local_e[0] = ((int64_t)(sig[0]) * (int64_t)(coeffs[0]));
    for (i = 1; i < 16; i++) {
        local_e[i] = local_e[i-1] + ((int64_t)(sig[i]) * (int64_t)(coeffs[i]));
    }
    e = local_e[15];
}
