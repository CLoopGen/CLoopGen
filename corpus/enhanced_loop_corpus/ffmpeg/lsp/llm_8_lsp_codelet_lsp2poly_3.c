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
for (i = 2; i <= lp_half_order; i += 2) {
    if (i + 1 <= lp_half_order) {
        f[i] = f[i - 2];
        f[i + 1] = f[i - 1];
        for (j = i + 1; j > 1; j--) {
            int64_t temp = ((int64_t)(f[j - 1]) * (int64_t)(lsp[2 * i - 2])) >> 14;
            f[j] -= temp - f[j - 2];
            if (j > 2) {
                f[j-1] -= temp - f[j - 3];
            }
        }
        f[1] -= lsp[2 * i - 2] * 256;
        if (i + 1 <= lp_half_order) {
            f[1] -= lsp[2 * (i + 1) - 2] * 256;
        }
    } else {
        f[i] = f[i - 2];
        for (j = i; j > 1; j--)
            f[j] -= (((int64_t)(f[j - 1]) * (int64_t)(lsp[2 * i - 2])) >> 14) - f[j - 2];
        f[1] -= lsp[2 * i - 2] * 256;
    }
}
}
