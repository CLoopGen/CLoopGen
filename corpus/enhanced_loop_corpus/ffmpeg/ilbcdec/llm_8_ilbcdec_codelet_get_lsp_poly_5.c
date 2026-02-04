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
for (i = 2 , k = 2 , l = 2; i <= 5; i++ , k += 2) {
    int32_t temp_store = f[l - 2];
    f[l] = temp_store;
    for (j = i; j > 1; j-- , l--) {
        int16_t local_high = f[l - 1] >> 16;
        int16_t local_low = (f[l - 1] >> 1) & 0x7FFF;
        int32_t computed_val = ((local_high * lsp[k]) * 4) + (((local_low * lsp[k]) >> 15) * 4);
        f[l] = f[l] + f[l - 2] - computed_val;
    }
    f[l] = f[l] - (lsp[k] << 10);
    l += i;
}
}
