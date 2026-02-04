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
for (i = len - 1; i >= order + 4; i -= 4) {
    int64_t p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    for (j = 0; j < order; j++) {
        int32_t val0 = (int32_t)decoded[i - order + j];
        int32_t val1 = (int32_t)decoded[i - order + j + 1];
        int32_t val2 = (int32_t)decoded[i - order + j + 2];
        int32_t val3 = (int32_t)decoded[i - order + j + 3];
        p0 += coeffs[j] * (int64_t)val0;
        p1 += coeffs[j] * (int64_t)val1;
        p2 += coeffs[j] * (int64_t)val2;
        p3 += coeffs[j] * (int64_t)val3;
    }
    decoded[i]     -= p0 >> qlevel;
    if (i > order) decoded[i-1] -= p1 >> qlevel;
    if (i > order+1) decoded[i-2] -= p2 >> qlevel;
    if (i > order+2) decoded[i-3] -= p3 >> qlevel;
}
}
