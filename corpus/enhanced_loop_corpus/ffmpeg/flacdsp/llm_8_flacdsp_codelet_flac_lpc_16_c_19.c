#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = pred_order; i < len - 3; i += 4, decoded += 4) {
    unsigned int c0 = coeffs[0];
    unsigned int d0 = decoded[0];
    unsigned int d1 = decoded[1];
    int s0 = 0, s1 = 0, s2 = 0, s3 = 0;
    for (j = 1; j < pred_order; j++) {
        s0 += c0 * d0;
        s1 += c0 * d1;
        unsigned int d2 = decoded[j];
        s2 += c0 * d2;
        d0 = d1;
        d1 = d2;
        c0 = coeffs[j];
    }
    s0 += c0 * d0;
    s1 += c0 * d1;
    d0 = decoded[j] += (unsigned int)(s0 >> qlevel);
    d1 = decoded[j + 1] += (unsigned int)(s1 >> qlevel);
    s2 += c0 * d0;
    s3 += c0 * d1;
    decoded[j + 2] += (unsigned int)(s2 >> qlevel);
    decoded[j + 3] += (unsigned int)(s3 >> qlevel);
}
}
