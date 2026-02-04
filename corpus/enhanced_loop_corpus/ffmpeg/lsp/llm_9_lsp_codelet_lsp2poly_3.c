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
    if (i % 2 == 0) {
        for (j = i; j > 1; j -= 2) {
            int64_t product = ((int64_t)(f[j - 1]) * (int64_t)(lsp[2 * i - 2])) >> 14;
            f[j] -= product - f[j - 2];
            if (j > 2) {
                f[j - 1] -= product - f[j - 3];
            }
        }
    } else {
        for (j = i; j > 1; j--) {
            f[j] -= (((int64_t)(f[j - 1]) * (int64_t)(lsp[2 * i - 2])) >> 14) - f[j - 2];
        }
    }
    f[1] -= lsp[2 * i - 2] * 256;
}
}
