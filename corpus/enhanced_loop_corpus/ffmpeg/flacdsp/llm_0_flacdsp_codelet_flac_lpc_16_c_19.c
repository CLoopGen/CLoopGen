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
for (i = pred_order; i < len - 1; i += 2) {
    unsigned int c0 = coeffs[0];
    unsigned int d0 = decoded[0];
    int s0 = 0, s1 = 0;
    if (pred_order > 1) {
        for (j = 1; j < pred_order; j++) {
            s0 += c0 * d0;
            d0 = decoded[j];
            s1 += c0 * d0;
            c0 = coeffs[j];
        }
    }
    s0 += c0 * d0;
    d0 = decoded[j] += (unsigned int)(s0 >> qlevel);
    s1 += c0 * d0;
    decoded[j + 1] += (unsigned int)(s1 >> qlevel);
    decoded += 2;
}
}
