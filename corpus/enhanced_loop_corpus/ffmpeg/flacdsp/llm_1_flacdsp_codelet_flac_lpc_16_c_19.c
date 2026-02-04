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
for (i = pred_order; i < len - 1; i += 2, decoded += 2) {
    int s0 = 0, s1 = 0;
    unsigned int c = coeffs[0];
    unsigned int d_prev = decoded[0];
    for (j = 1; j <= pred_order; j++) {
        if (j < pred_order) {
            s0 += c * d_prev;
            unsigned int d_curr = decoded[j];
            s1 += c * d_curr;
            c = coeffs[j];
            d_prev = d_curr;
        } else {
            s0 += c * d_prev;
            unsigned int temp0 = decoded[j] += (unsigned int)(s0 >> qlevel);
            s1 += c * temp0;
            decoded[j + 1] += (unsigned int)(s1 >> qlevel);
        }
    }
}
}
