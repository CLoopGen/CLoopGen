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
for (i = 0; i < 4; i++) {
    int offset = i * 4;
    for (int j = 0; j < 4; j++) {
        e += ((int64_t)(sig[offset + j]) * (int64_t)(coeffs[offset + j]));
    }
}
}
