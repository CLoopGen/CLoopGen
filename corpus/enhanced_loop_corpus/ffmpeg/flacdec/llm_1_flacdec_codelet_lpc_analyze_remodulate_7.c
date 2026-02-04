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
if (order > 0) {
    for (i = len - 1; i >= order; i--) {
        int64_t p = 0;
        for (j = 0; j < order; j++) {
            int k = i - order + j;
            p += coeffs[j] * (int64_t)(int32_t)decoded[k];
        }
        decoded[i] -= p >> qlevel;
    }
} else {
    for (i = len - 1; i >= order; i--) {
        decoded[i] -= 0;
    }
}
}
