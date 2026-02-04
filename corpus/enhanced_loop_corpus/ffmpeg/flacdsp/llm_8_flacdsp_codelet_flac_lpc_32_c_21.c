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
for (i = pred_order; i < len; i++, decoded++) {
    int64_t sum1 = 0, sum2 = 0;
    int half_order = pred_order / 2;
    for (j = 0; j < half_order; j++) {
        sum1 += (int64_t)coeffs[j] * decoded[j];
        sum2 += (int64_t)coeffs[pred_order - 1 - j] * decoded[pred_order - 1 - j];
    }
    if (pred_order % 2) {
        sum1 += (int64_t)coeffs[half_order] * decoded[half_order];
    }
    decoded[pred_order] += (sum1 + sum2) >> qlevel;
}
}
