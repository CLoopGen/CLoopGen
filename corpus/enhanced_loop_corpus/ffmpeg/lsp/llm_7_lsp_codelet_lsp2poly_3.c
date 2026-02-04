#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *f;
extern  int16_t *lsp;
extern int lp_half_order;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i <= lp_half_order; i++) {
    f[i] = f[i - 2];
    int16_t coeff = lsp[2 * i - 2];
    int scaled_coeff = coeff * 256;
    for (j = i; j > 1; j--) {
        int64_t prediction = ((int64_t)(f[j - 1]) * (int64_t)(coeff)) >> 14;
        f[j] = f[j] - prediction + f[j - 2];
    }
    f[1] = f[1] - scaled_coeff;
}
}
