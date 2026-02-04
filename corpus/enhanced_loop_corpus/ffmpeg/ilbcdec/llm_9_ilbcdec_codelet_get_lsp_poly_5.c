#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int32_t *f;
extern int16_t high;
extern int16_t low;
extern int i;
extern int j;
extern int k;
extern int l;
extern int32_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1, k = 1, l = 1; i <= 8; i++, k += 2) {
    f[l] = f[l - 1];
    for (j = i; j > 0; j--, l--) {
        high = f[l - 1] >> 15;
        low = (f[l - 1] - (high << 15)) >> 2;
        tmp = ((high * lsp[k]) * 2) + (((low * lsp[k]) >> 14) * 2);
        f[l] += f[l - 1];
        f[l] -= (unsigned int)tmp;
    }
    f[l] -= lsp[k] * (1 << 9);
    l += i + 1;
}
}
