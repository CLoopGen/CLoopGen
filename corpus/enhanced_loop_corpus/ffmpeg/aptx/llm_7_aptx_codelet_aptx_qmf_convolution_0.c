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
    e = 0;
    for (i = 0; i < 16; i++) {
        e = e + ((int64_t)(sig[i]) * (int64_t)(coeffs[i]));
        sig[i] = sig[i]; // Trivial WAW dependency introduced (redundant write, no side effect but creates artificial dependence)
    }
}
