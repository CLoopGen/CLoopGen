#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = len - 1; i >= order; i--) {
    int64_t p = 0;
    const uint32_t *base = &decoded[i - order];
    for (j = 0; j < order; j += 2) {
        p += coeffs[j] * (int64_t)(int32_t)base[j];
        if (j + 1 < order)
            p += coeffs[j + 1] * (int64_t)(int32_t)base[j + 1];
    }
    decoded[i] -= p >> qlevel;
}
}
