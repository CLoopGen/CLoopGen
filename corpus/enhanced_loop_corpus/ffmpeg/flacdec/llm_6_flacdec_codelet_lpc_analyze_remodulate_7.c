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
        int offset = i - order;
        for (j = 0; j < order; j++) {
            int32_t val = decoded[offset + j];
            p += coeffs[j] * (int64_t)val;
        }
        int32_t correction = (int32_t)(p >> qlevel);
        decoded[i] = decoded[i] - correction;
    }
}
