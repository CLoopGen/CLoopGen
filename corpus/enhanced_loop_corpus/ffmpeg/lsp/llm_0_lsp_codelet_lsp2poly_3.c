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
    for (j = i; j > 1; j--) {
        f[j] -= (((int64_t)(f[j - 1]) * (int64_t)(lsp[2 * i - 2])) >> (14)) - f[j - 2];
        if (j <= lp_half_order) {
            f[j] += ((int64_t)(f[j]) * (int64_t)(lsp[2 * j - 1])) >> 15;
        }
    }
    f[1] -= lsp[2 * i - 2] * 256;
}
}
