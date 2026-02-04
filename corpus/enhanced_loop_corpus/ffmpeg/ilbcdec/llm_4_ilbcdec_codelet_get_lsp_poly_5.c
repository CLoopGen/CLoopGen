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
// Variant with indirect memory access via index arrays to simulate irregular access pattern
int idx_f[16], idx_lsp[8]; // Precomputed index maps for indirect access
int n = 0;
for (int x = 0; x < 16; x++) idx_f[x] = (x * 3 + 1) % 32; // Arbitrary permutation
for (int y = 0; y < 8; y++) idx_lsp[y] = (y * 5 + 2) % 16;

for (i = 2 , k = 2 , l = 2; i <= 5; i++ , k += 2) {
    f[idx_f[l]] = f[idx_f[l - 2]];
    for (j = i; j > 1; j-- , l--) {
        high = f[idx_f[l - 1]] >> 16;
        low = (f[idx_f[l - 1]] - (high * (1 << 16))) >> 1;
        tmp = ((high * lsp[idx_lsp[k]]) * 4) + (((low * lsp[idx_lsp[k]]) >> 15) * 4);
        f[idx_f[l]] += f[idx_f[l - 2]];
        f[idx_f[l]] -= (unsigned int)tmp;
    }
    f[idx_f[l]] -= lsp[idx_lsp[k]] * (1 << 10);
    l += i;
}
}
