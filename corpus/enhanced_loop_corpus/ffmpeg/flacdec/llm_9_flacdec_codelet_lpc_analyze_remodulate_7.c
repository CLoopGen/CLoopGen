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
if (order > 0 && len > order) {
    int64_t p = 0;
    for (j = 0; j < order; j++)
        p += coeffs[j] * (int64_t)(int32_t)decoded[order - 1 + j];
    decoded[len - 1] -= p >> qlevel;
}
for (i = len - 2; i >= order; i--) {
    int64_t p = 0;
    for (j = 0; j < order; j += 2) {
        if (j + 1 < order) {
            p += coeffs[j] * (int64_t)(int32_t)decoded[i - order + j];
            p += coeffs[j+1] * (int64_t)(int32_t)decoded[i - order + j + 1];
        } else {
            p += coeffs[j] * (int64_t)(int32_t)decoded[i - order + j];
        }
    }
    decoded[i] -= p >> qlevel;
}
}
