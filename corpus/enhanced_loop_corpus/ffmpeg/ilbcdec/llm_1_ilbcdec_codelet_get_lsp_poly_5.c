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
for (i = 2, k = 2, l = 2; i <= 5; i++, k += 2) {
    f[l] = f[l - 2];
    if (i % 2 == 0) {
        for (j = i; j > 1; j--, l--) {
            high = f[l - 1] >> 16;
            low = (f[l - 1] - (high * (1 << 16))) >> 1;
            tmp = ((high * lsp[k]) * 4) + (((low * lsp[k]) >> 15) * 4);
            f[l] += f[l - 2];
            f[l] -= (unsigned int)tmp;
        }
    } else {
        j = i;
        l = l - (i - 1);
        for (int step = 0; step < i - 1; step++) {
            high = f[l + step - 1] >> 16;
            low = (f[l + step - 1] - (high * (1 << 16))) >> 1;
            tmp = ((high * lsp[k]) * 4) + (((low * lsp[k]) >> 15) * 4);
            f[l + step] += f[l + step - 2];
            f[l + step] -= (unsigned int)tmp;
        }
    }
    f[l] -= lsp[k] * (1 << 10);
    l += i;
}
}
