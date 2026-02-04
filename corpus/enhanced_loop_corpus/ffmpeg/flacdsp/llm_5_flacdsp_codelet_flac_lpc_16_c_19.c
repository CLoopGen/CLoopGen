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
for (i = pred_order; i < len - 1; i += 2 , decoded += 2) {
    unsigned int c = coeffs[0];
    unsigned int d = decoded[0];
    int s0 = 0, s1 = 0;
    j = 1;
    if (pred_order <= 1) {
        decoded[1] += (unsigned int)(c * d >> qlevel);
        continue;
    }
    for (; j < pred_order; j++) {
        s0 += c * d;
        d = decoded[j];
        s1 += c * d;
        c = coeffs[j];
    }
    s0 += c * d;
    d = decoded[j] += (unsigned int)(s0 >> qlevel);
    s1 += c * d;
    decoded[j + 1] += (unsigned int)(s1 >> qlevel);
}
}
