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
for (i = 3, k = 3, l = 3; i <= 6; i++, k += 3) {
    f[l] = f[l - 3];
    for (j = i; j > 2; j--, l -= 2) {
        high = f[l - 2] >> 17;
        low = (f[l - 2] - (high * (1 << 17))) >> 3;
        tmp = ((high * lsp[k]) * 8) + (((low * lsp[k]) >> 16) * 8) + ((lsp[k] * 3) << 5);
        f[l] += f[l - 3];
        f[l] -= (unsigned int)tmp;
        f[l] += (f[l] >> 12) * 2;
    }
    f[l] -= lsp[k] * (1 << 11);
    l += i + 2;
}
}
