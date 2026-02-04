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
for (i = order; i < len - 4; i += 5, decoded += 5) {
    int32_t p0 = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    for (j = 0; j < order; j++) {
        p0 += coeffs[j] * (uint32_t)decoded[j];
        p1 += coeffs[j] * (uint32_t)decoded[j + 1];
        p2 += coeffs[j] * (uint32_t)decoded[j + 2];
        p3 += coeffs[j] * (uint32_t)decoded[j + 3];
        p4 += coeffs[j] * (uint32_t)decoded[j + 4];
    }
    decoded[order + 0] += p0 >> qlevel;
    decoded[order + 1] += p1 >> qlevel;
    decoded[order + 2] += p2 >> qlevel;
    decoded[order + 3] += p3 >> qlevel;
    decoded[order + 4] += p4 >> qlevel;
}
}
